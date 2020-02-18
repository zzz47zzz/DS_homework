#include "MAP.h"

MAP::MAP(int mapBasicX, int mapBasicY, Scene *PScene, int size_x, int size_y)
{
    for (int i = 0; i < size_x; i++)
    {
        map_.push_back(std::vector<Land>());
    }
    map = TMXTiledMap::create("backgroundmap.tmx");
    map->setName("bgmap");
    map->setPosition(Vec2(mapBasicX, mapBasicY));
    map->setAnchorPoint(Vec2(0, 0));
    PScene->addChild(map, 0);
    mapSize = map->getContentSize();
    landLayer = map->getLayer("land");
    grassLayer = map->getLayer("grass");
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            int type = landLayer->getTileGIDAt(Vec2(i, j));
            switch (type)
            {
            case 0:
            case 1:
            case 2:
            case 3:
                BarrenGroup.push_back(Barren(Vec2(i, mapSize.width - j - 1)));
                break;
            case 8:
            case 9:
            case 10:
            case 11:
                FertileGroup.push_back(Fertile(Vec2(i, mapSize.width - j - 1)));
                break;
            default:
                break;
            }
        }
    }
    PScene->schedule(CC_SCHEDULE_SELECTOR(MAP::update), 1, -1, 0);

    
}

void MAP::update(float t)
{
    for (auto p = BarrenGroup.begin(); p != BarrenGroup.end(); ++p)
    {
        if (p->currentStatus == Land::HAS_GRASS)
        {
            if (p->life == 0)
            {
                // turn grass into invisible
                grassLayer->removeTileAt(Vec2(p->pos.x, mapSize.height - p->pos.y - 1));
                p->gap = Land::GapOfBarrenGrass;
            }
            else
            {
                p->life--;
            }
        }
        else
        {
            if (p->gap == 0)
            {
                // turn grass into visible
                grassLayer->setTileGID(18, Vec2(p->pos.x, mapSize.height - p->pos.y - 1));
                p->life = Land::lifeOfBarrenGrass;
            }
            else
            {
                p->gap--;
            }

        }
    }

    for (auto p = FertileGroup.begin(); p != FertileGroup.end(); ++p)
    {
        if (p->currentStatus == Land::HAS_GRASS)
        {
            if (p->life == 0)
            {
                // turn grass into invisible
                grassLayer->removeTileAt(Vec2(p->pos.x, mapSize.height - p->pos.y - 1));
                p->gap = Land::GapOfFertileGrass;
            }
            else
            {
                p->life--;
            }
        }
        else
        {
            if (p->gap == 0)
            {
                // turn grass into visible
                grassLayer->setTileGID(18, Vec2(p->pos.x, mapSize.height - p->pos.y - 1));
                p->life = Land::lifeOfFertileGrass;
            }
            else
            {
                p->gap--;
            }

        }
    }
}

int MAP::getType(Vec2 pos)
{
    int GID = landLayer->getTileGIDAt(Vec2(pos.x, mapSize.height - pos.y - 1));
    switch (GID)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        return Land::TYPE_BARREN;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        return Land::TYPE_DESSERT;
        break;
    case 8:
    case 9:
    case 10:
    case 11:
        return Land::TYPE_FERTILE;
        break;
    case 12:
    case 13:
    case 14:
    case 15:
        return Land::TYPE_RIVER;
        break;
    default:
        return -1;
        break;
    }
}
