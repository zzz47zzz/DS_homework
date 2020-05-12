#include "MAP.h"
#include <iostream>
#include "animals.h"

MAP::MAP(int mapBasicX, int mapBasicY, Scene *PScene, int size_x, int size_y, int nSheep, int nWolf) {
    map = TMXTiledMap::create("newMap.tmx");
    map->setName("bgmap");
    map->setPosition(Vec2(mapBasicX, mapBasicY));
    map->setAnchorPoint(Vec2(0, 0));
    PScene->addChild(map, 0);
    mapSize = map->getContentSize();
    landLayer = map->getLayer("land");
    grassLayer = map->getLayer("grass");
    for (int i = 0; i < size_x; ++i) {
        for (int j = 0; j < size_y; ++j) {
            const int type = getType(Vec2(i, j));
            if (type == Land::TYPE_BARREN)
            {
                Barren* tmp = new Barren(Vec2(i, j));
                BarrenGroup.push_back(tmp);
                geo_info[i][j] = tmp;
            }
            else if (type == Land::TYPE_FERTILE)
            {
                Fertile* tmp = new Fertile(Vec2(i, j));
                FertileGroup.push_back(tmp);
                geo_info[i][j] = tmp;
            }
            else if (type == Land::TYPE_RIVER)
            {
                River* tmp = new River(Vec2(i, j));
                geo_info[i][j] = tmp;
            }
            else if (type == Land::TYPE_DESSERT)
            {
                Dessert* tmp = new Dessert(Vec2(i, j));
                geo_info[i][j] = tmp;
            }  
        }
    }
  
    start();
    
    PScene->getScheduler()->schedule(CC_SCHEDULE_SELECTOR(MAP::update), this, 1.0f, false);
    PScene->getScheduler()->schedule(CC_SCHEDULE_SELECTOR(MAP::update2), this, 5.0f, false);

}

void MAP::update(float t) {
    for (auto p = BarrenGroup.begin(); p != BarrenGroup.end(); ++p) {
        if ((*p)->currentStatus == Land::HAS_GRASS) {
            if ((*p)->life == 0) {
                // turn grass into invisible
                (*p)->change();
                landLayer->setTileGID(2, (*p)->pos);
                (*p)->gap = Land::GapOfBarrenGrass;
            }
            else {
                (*p)->lifePass();
            }
        }
        else {
            if ((*p)->gap == 0) {
                // turn grass into visible
                (*p)->change();
                landLayer->setTileGID(18, (*p)->pos);
                (*p)->life = Land::lifeOfBarrenGrass;
            }
            else {
                (*p)->gapPass();
            }

        }
    }

    for (auto p = FertileGroup.begin(); p != FertileGroup.end(); ++p) {
        if ((*p)->currentStatus == Land::HAS_GRASS) {
            if ((*p)->life == 0) {
                // turn grass into invisible
                (*p)->change();
                landLayer->setTileGID(10, (*p)->pos);
                (*p)->gap = Land::GapOfFertileGrass;
            }
            else {
                (*p)->lifePass();
            }
        }
        else {
            if ((*p)->gap == 0) {
                // turn grass into visible
                (*p)->change();
                landLayer->setTileGID(18, (*p)->pos);
                (*p)->life = Land::lifeOfFertileGrass;
            }
            else {
                (*p)->gapPass();
            }

        }
    }
  //  for (int i = 0; i <= 50; i++) {
  //     if (!a[i]->life) delete(a[i]);
  //  }

}

int MAP::getType(Vec2 pos) {
    const int GID = landLayer->getTileGIDAt(pos);
    switch (GID) {
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

void MAP::start() {
    Wolf* a[1000];
    Sheep* b[1000];
    for (int i = 0; i <= 50; i++) {
        a[i] = new Wolf();
        map->addChild(a[i]->player);
    }
    for (int i = 0; i <= 100; i++) {
        b[i] = new Sheep();
        Wolf::li.push_back(b[i]);
        map->addChild(b[i]->player);
    }
    for (int i = 0; i <= 50; i++) {
        a[i]->funCallback();
    }
    for (int i = 0; i <= 100; i++) {
        b[i]->funCallback();
    }

}

void MAP::update2(float t) {
    Wolf* a[1000];
    Sheep* b[1000];
    for (int i = 0; i <= 10; i++) {
        a[i] = new Wolf();
        map->addChild(a[i]->player);
    }
    for (int i = 0; i <= 50; i++) {
        b[i] = new Sheep();
        Wolf::li.push_back(b[i]);
        map->addChild(b[i]->player);
    }
    for (int i = 0; i <= 10; i++) {
        a[i]->funCallback();
    }
    for (int i = 0; i <= 50; i++) {
        b[i]->funCallback();
    }
}

int MAP::get_number_of_grass()
{
    int num = 0;
    for (auto p = BarrenGroup.begin(); p != BarrenGroup.end(); ++p)
    {
        if ((*p)->currentStatus == Land::HAS_GRASS) num++;
    }
    for (auto p = FertileGroup.begin(); p != FertileGroup.end(); ++p)
    {
        if ((*p)->currentStatus == Land::HAS_GRASS) num++;
    }
    return num;
}

bool MAP::sheep_eat_grass(cocos2d::Vec2 pos)
{
    // 羊吃掉pos处的草，返回bool代表吃草成功与否，若该地没有草则失败，若成功吃草，则草在下一个update中会消失
    int x = pos.x;
    int y = pos.y;
    Land* tmp = geo_info[x][y];
    if (tmp->type == Land::TYPE_BARREN || tmp->type == Land::TYPE_FERTILE)
    {
        if (tmp->type == Land::TYPE_BARREN)
        {
            Barren* tmp_of_Barren = static_cast<Barren*>(tmp);
            if (tmp_of_Barren != nullptr)
            {
                if (tmp_of_Barren->currentStatus == Land::HAS_GRASS)
                {
                    tmp_of_Barren->life = 0;
                    return true;
                }
            }
        }
        else
        {
            if (tmp->type == Land::TYPE_FERTILE)
            {
                Fertile* tmp_of_Fertile = static_cast<Fertile*>(tmp);
                if (tmp_of_Fertile != nullptr)
                {
                    if (tmp_of_Fertile->currentStatus == Land::HAS_GRASS)
                    {
                        tmp_of_Fertile->life = 0;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
