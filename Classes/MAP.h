#pragma once

#include <vector>
#include "Land.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <math.h>

USING_NS_CC;
using namespace cocos2d::ui;

class HelloWorld;
class Wolf;
class MAP : Ref {
public:
    MAP(int mapBasicX, int mapBasicY, Scene *PScene, int size_x, int size_y, int nSheep, int nWolf);
    std::vector<Barren *> BarrenGroup;
    std::vector<Fertile *> FertileGroup;
    HelloWorld *scene = nullptr;
    TMXTiledMap *map = nullptr;
    TMXLayer *landLayer;
    TMXLayer *grassLayer;
    Land *geo_info[100][100];
    int nsheep;
    int nwolf;
    Size mapSize;
    std::vector<Wolf *> wolves;

    void update(float t);
    int getType(Vec2 pos);
    void change_grass_gap(int x);
    void start(int nsheep, int nwolf);
    void update2(float t);
    int get_number_of_grass();
    bool sheep_eat_grass(cocos2d::Vec2 pos);
};
