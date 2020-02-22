#include "Land.h"

Land::Land(cocos2d::Vec2 pos, int type): pos(pos), type(type)
{
}

Barren::Barren(cocos2d::Vec2 pos):Land(pos, TYPE_BARREN)
{
	currentStatus = NO_GRASS;
	life = 0;
	gap = GapOfBarrenGrass;
}

int Barren::lifePass()
{
	life--;
	return life;
}

int Barren::gapPass()
{
	gap--;
	return gap;
}

void Barren::change()
{
	if (currentStatus == HAS_GRASS)
	{
		currentStatus = NO_GRASS;
		//²¹³ä´úÂë
	}
	else
	{
		currentStatus = HAS_GRASS;
		//²¹³ä´úÂë
	}
	
}

Fertile::Fertile(cocos2d::Vec2 pos):Land(pos, TYPE_FERTILE)
{
	life = lifeOfFertileGrass;
	gap = GapOfFertileGrass;
	currentStatus = NO_GRASS;
}

int Fertile::lifePass()
{
	life--;
	return life;
}

int Fertile::gapPass()
{
	gap--;
	return gap;
}

void Fertile::change()
{
	if (currentStatus == HAS_GRASS)
	{
		currentStatus = NO_GRASS;
		//²¹³ä´úÂë
	}
	else
	{
		currentStatus = HAS_GRASS;
		//²¹³ä´úÂë
	}
}

River::River(cocos2d::Vec2 pos):Land(pos, TYPE_RIVER)
{
}

Dessert::Dessert(cocos2d::Vec2 pos):Land(pos, TYPE_DESSERT)
{
}
