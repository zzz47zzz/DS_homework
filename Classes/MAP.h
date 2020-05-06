#pragma once
#include "Land.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include <vector>


USING_NS_CC;
using namespace cocos2d::ui;
class MAP : Ref {
public:
    MAP(int mapBasicX, int mapBasicY, Scene *PScene, int size_x, int size_y);
    std::vector<Barren> BarrenGroup;
    std::vector<Fertile> FertileGroup;
    TMXTiledMap *map = nullptr;
    TMXLayer *landLayer;
    TMXLayer *grassLayer;
    

    Size mapSize;
    void update(float t);
    int getType(Vec2 pos);

    void start();
    void update2(float t);

};
