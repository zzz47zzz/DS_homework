#include "MAP.h"
#include <iostream>
#include "animals.h"

MAP::MAP(int mapBasicX, int mapBasicY, Scene *PScene, int size_x, int size_y, int nSheep, int nWolf)
    :nsheep(nSheep), nwolf(nWolf), map(TMXTiledMap::create("newMap.tmx")), scene((HelloWorld *)PScene) {
    Animal::map = this;
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
            if (type == Land::TYPE_BARREN) {
                Barren *tmp = new Barren(Vec2(i, j));
                BarrenGroup.push_back(tmp);
                geo_info[i][j] = tmp;
            }
            else if (type == Land::TYPE_FERTILE) {
                Fertile *tmp = new Fertile(Vec2(i, j));
                FertileGroup.push_back(tmp);
                geo_info[i][j] = tmp;
            }
            else if (type == Land::TYPE_RIVER) {
                River *tmp = new River(Vec2(i, j));
                geo_info[i][j] = tmp;
            }
            else if (type == Land::TYPE_DESSERT) {
                Dessert *tmp = new Dessert(Vec2(i, j));
                geo_info[i][j] = tmp;
            }
        }
    }

    PScene->getScheduler()->schedule(std::bind(&MAP::update, this, std::placeholders::_1), this, 1.0f, false, "updateGround");
    start(nSheep, nWolf);
    PScene->getScheduler()->schedule(std::bind(&MAP::update2, this, std::placeholders::_1), this, 5.0f, false, "updateAnimal");
}

void MAP::update(float t) {
    for (auto p = BarrenGroup.begin(); p != BarrenGroup.end(); ++p) {
        Barren *const bp = *p;
        if (bp->currentStatus == Land::HAS_GRASS) {
            if (bp->life == 0) {
                // turn grass into invisible
                bp->change();
                landLayer->setTileGID(2, bp->pos);
                bp->gap = Land::GapOfBarrenGrass;
            }
            else {
                bp->lifePass();
            }
        }
        else {
            if (bp->gap == 0) {
                // turn grass into visible
                bp->change();
                landLayer->setTileGID(18, bp->pos);
                bp->life = Land::lifeOfBarrenGrass;
            }
            else {
                bp->gapPass();
            }

        }
    }

    for (auto p = FertileGroup.begin(); p != FertileGroup.end(); ++p) {
        Fertile *const fp = *p;
        if (fp->currentStatus == Land::HAS_GRASS) {
            if (fp->life == 0) {
                // turn grass into invisible
                fp->change();
                landLayer->setTileGID(10, fp->pos);
                fp->gap = Land::GapOfFertileGrass;
            }
            else {
                fp->lifePass();
            }
        }
        else {
            if (fp->gap == 0) {
                // turn grass into visible
                fp->change();
                landLayer->setTileGID(18, fp->pos);
                fp->life = Land::lifeOfFertileGrass;
            }
            else {
                fp->gapPass();
            }

        }
    }
    scene->updateGrass(get_number_of_grass());
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
    }
    return -1;
}

void MAP::start(int nsheep, int nwolf) {
    Wolf *a[10000];
    Sheep *b[10000];
    for (int i = 0; i < nwolf; i++) {
        a[i] = new Wolf();
        map->addChild(a[i]->player);
    }
    for (int i = 0; i < nsheep; i++) {
        b[i] = new Sheep();
        Wolf::li.push_back(b[i]);
        map->addChild(b[i]->player);
    }
    for (int i = 0; i < nwolf; i++) {
        a[i]->funCallback();
    }
    for (int i = 0; i < nsheep; i++) {
        b[i]->funCallback();
    }
    scene->updateWolf(Wolf::getWolfSum());
    scene->updateSheep(Wolf::getSheepSum());
}

inline int raise(const int a0, const float k) {
    if (a0) {
        const int a1 = a0 * k;
        return a1>0 ? a1 : 1;
    }
    else return 0;
}
void MAP::update2(float t) {
    const int newWolfN = raise(Wolf::getWolfSum(), scene->wolfRate / 185.f);
    const int newSheepN = raise(Wolf::getSheepSum(), scene->sheepRate / 385.f);
    for (int i = 0; i < newWolfN; i++) {
        auto w = new Wolf();
        map->addChild(w->player);
        w->funCallback();
    }
    for (int i = 0; i < newSheepN; i++) {
        auto s = new Sheep();
        Wolf::li.push_back(s);
        map->addChild(s->player);
        s->funCallback();
    }
    scene->updateWolf(Wolf::getWolfSum());
    scene->updateSheep(Wolf::getSheepSum());
}

int MAP::get_number_of_grass() {
    int num = 0;
    for (auto p = BarrenGroup.begin(); p != BarrenGroup.end(); ++p) {
        if ((*p)->currentStatus == Land::HAS_GRASS) ++num;
    }
    for (auto p = FertileGroup.begin(); p != FertileGroup.end(); ++p) {
        if ((*p)->currentStatus == Land::HAS_GRASS) ++num;
    }
    return num;
}

bool MAP::sheep_eat_grass(cocos2d::Vec2 pos) {
    // 羊吃掉pos处的草，返回bool代表吃草成功与否，若该地没有草则失败，若成功吃草，则草在下一个update中会消失
    const int x = pos.x;
    const int y = pos.y;
    Land *tmp = geo_info[x][y];
    if (tmp->type == Land::TYPE_BARREN || tmp->type == Land::TYPE_FERTILE) {
        if (tmp->type == Land::TYPE_BARREN) {
            Barren *tmp_of_Barren = static_cast<Barren *>(tmp);
            if (tmp_of_Barren) {
                if (tmp_of_Barren->currentStatus == Land::HAS_GRASS) {
                    tmp_of_Barren->life = 0;
                    return true;
                }
            }
        }
        else {
            if (tmp->type == Land::TYPE_FERTILE) {
                Fertile *tmp_of_Fertile = static_cast<Fertile *>(tmp);
                if (tmp_of_Fertile) {
                    if (tmp_of_Fertile->currentStatus == Land::HAS_GRASS) {
                        tmp_of_Fertile->life = 0;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
