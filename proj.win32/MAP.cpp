#include "MAP.h"

MAP::MAP(int mapBasicX, int mapBasicY, HelloWorld *PScene, int size_x, int size_y)
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
    PScene->schedule(update, 1, -1, 0);


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
                landLayer->setTileGID(1, Vec2(p->pos.x, mapSize - p->pos.y - 1));
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
                landLayer->setTileGID(18, Vec2(p->pos.x, mapSize - p->pos.y - 1));
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
                landLayer->setTileGID(10, Vec2(p->pos.x, mapSize - p->pos.y - 1));
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
                landLayer->setTileGID(18, Vec2(p->pos.x, mapSize - p->pos.y - 1));
                p->life = Land::lifeOfFertileGrass;
            }
            else
            {
                p->gap--;
            }

        }
    }
}
