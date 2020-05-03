#include"animals.h"
#include<iostream>

vector<Sheep*> Wolf::li{};

void Wolf::funCallback()
{
	hp--;
	pos.x = des2.x;
	pos.y = des2.y;
	bool s = Catch();
	if (hp <= 0) {
		CCActionInterval* fadeout = CCFadeOut::create(1);
		player->runAction(fadeout);
		//if (prey != NULL) delete prey;
		prey = NULL;
		return;
	}
	if (!Check()) {
		Pos target = FindPrey(li);
		if ((target.x == pos.x) && (target.y == pos.y))
			RandomMove();
		else
			Move(prey->getPos());
	}else
		Move(prey->getPos());
}
void Animal::Move(Pos des)
{
	CCMoveTo* move = CCMoveTo::create((GetDistance(des) / speed), ccp(des.x, des.y));
	player->runAction(move);
	pos = des;

}
void Wolf::Move(Pos des)
{
	des2.x = des.x;
	des2.y = des.y;
	CCMoveTo* move = CCMoveTo::create((GetDistance(des) / speed), ccp(des.x, des.y));
	CallFunc* func = CallFunc::create(CC_CALLBACK_0(Wolf::funCallback, this));
	Sequence* sequence = Sequence::create(move, func, NULL);
	player->runAction(sequence);
	//pos = des;
}
void Animal::RandomMove()
{
	Pos des;
	int temp, symbolx, symboly;
	symbolx = rand() % 2 ? 1 : -1;
	symboly = rand() % 2 ? 1 : -1;
	des.x = pos.x + rand() % 100 * symbolx;
	des.y = pos.y + rand() % 100 * symboly;
	Move(des);
}
void Wolf::RandomMove()
{
	Pos des;
	int temp, symbolx, symboly;
	symbolx = rand() % 2 ? 1 : -1;
	symboly = rand() % 2 ? 1 : -1;
	des.x = pos.x + rand() % 150 * symbolx;
	des.y = pos.y + rand() % 150 * symboly;
	Move(des);
}

Wolf::Wolf(int ahp, double asight, double aspeed)
{

	hp = ahp;
	sight = asight;
	speed = aspeed;
	degree = 0;
	prey = NULL;

	auto glView = Director::getInstance()->getOpenGLView();
	auto frameSize = glView->getFrameSize();
	pos.x = abs(rand() % (int(frameSize.width)-500));
	pos.y = 183 + abs(rand() % (int(frameSize.height-500)));

	des2.x = pos.x;
	des2.y = pos.y;
	player = CCSprite::create("wolf.png");
//  player->setPosition(ccp(pos.x, pos.y));
	player->setPosition(ccp(pos.x, pos.y));


}
Pos Wolf::FindPrey(vector<Sheep *> li)
{
	Pos res, temp;
	res.x = pos.x;
	res.y = pos.y;
	double dis, min = DBL_MAX;
	for (int i = 0; i < li.size(); i++)
		if (li[i]!=NULL)
	{
		temp = li[i]->getPos();
		dis = GetDistance(temp);
		if ((dis <= sight) && (dis < min))
		{
			min = dis;
			res = temp;
			prey = li[i];
			num = i;
		}
	}
	return res;
}
bool Wolf::Catch()
{
	if (prey == NULL) return false;
	if (GetDistance(prey->getPos()) <= 100) {
		Sheep * temp = prey;
		prey = NULL;
		delete temp;
		degree = 0;
		hp = hp + 3;
		li[num] = NULL;
		return true;
	}
	else
		return false;
}
bool Wolf::Check()
{
	if (prey == NULL) return false;
	if (GetDistance(prey->getPos()) > sight)
	{
		prey = NULL;
		return false;
	}
	else
		return true;
}
Wolf::~Wolf()
{
	CCActionInterval * fadeout = CCFadeOut::create(1);
	player->runAction(fadeout);
	if (prey != NULL) delete prey;
	prey = NULL;

}

Sheep::Sheep(int ahp, double asight, double aspeed)
{
	hp = ahp;
	sight = asight;
	speed = aspeed;
	degree = 0;
	//prey = NULL;
	auto glView = Director::getInstance()->getOpenGLView();
	auto frameSize = glView->getFrameSize();
	pos.x = abs(rand() % (int(frameSize.width-500)));
	pos.y = 183+abs(rand() % (int(frameSize.height-500)));

	player = CCSprite::create("sheep.png");
	player->setPosition(ccp(pos.x, pos.y));

}
Sheep::~Sheep()
{
	CCActionInterval* fadeout = CCFadeOut::create(1);
	player->runAction(fadeout);
}