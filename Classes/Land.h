#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Land
{
public:
	Land(cocos2d::Vec2 pos, int type);
	// type of lands
	const static int TYPE_DESSERT = 0;
	const static int TYPE_RIVER = 1;
	const static int TYPE_BARREN = 2;
	const static int TYPE_FERTILE = 3;
	// grow grass or not
	const static int HAS_GRASS = 1;
	const static int NO_GRASS = 0;
	// life circle of barren and fertile
	const static int GapOfBarrenGrass = 3;
	const static int lifeOfBarrenGrass = 5;
	const static int GapOfFertileGrass = 2;
	const static int lifeOfFertileGrass = 7;
	// total number of grass 
	static int totalNumOfGrass;
	// type of land
	int type;
	// position of this land
	cocos2d::Vec2 pos;
};

class Barren : public Land
{
public:
	// life time left
	int life;
	// gap time left
	int gap;
	// current status(being grass or not)
	int currentStatus;

	Barren(cocos2d::Vec2 pos);
	int lifePass();

	int gapPass();

	void change();

};

class Fertile : public Land
{
public:
	// life time left
	int life;
	// gap time left
	int gap;
	// current status(being grass or not)
	int currentStatus;

	Fertile(cocos2d::Vec2 pos);

	int lifePass();

	int gapPass();

	void change();


};
class River: public Land
{
public:
	River(cocos2d::Vec2 pos);
};

class Dessert : public Land
{
public:
	Dessert(cocos2d::Vec2 pos);
};