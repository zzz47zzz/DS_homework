#pragma once
#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Land.h"
#include<vector>
USING_NS_CC;
using namespace cocos2d::ui;
class MAP: Ref
{
public:
	std::vector<std::vector<Land>> map_;
	std::vector<Barren> BarrenGroup;
	std::vector<Fertile> FertileGroup;
	TMXTiledMap* map;
	TMXLayer* landLayer;
	TMXLayer* grassLayer;
	Size mapSize;
	MAP(int mapBasicX, int mapBasicY, Scene* PScene, int size_x, int size_y);
	void update(float t);
	int getType(Vec2 pos);
};

