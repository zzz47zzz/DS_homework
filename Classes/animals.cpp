#include"animals.h"
#include<iostream>


vector<Sheep*> Wolf::li{};
int Wolf::sum = 0;

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
		sum--;
		life = false;
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

void Wolf::Move(Pos des)
{
	des2.x = des.x;
	des2.y = des.y;
	CCMoveTo* move = CCMoveTo::create((GetDistance(des) / speed), Vec2(des.x, des.y));
	CallFunc* func = CallFunc::create(CC_CALLBACK_0(Wolf::funCallback, this));
	Sequence* sequence = Sequence::create(move, func, NULL);
	player->runAction(sequence);
	//pos = des;
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
void Sheep::Move(Pos des)
{
	des2.x = des.x;
	des2.y = des.y;
	CCMoveTo* move = CCMoveTo::create((GetDistance(des) / speed), Vec2(des.x, des.y));
	CallFunc* func = CallFunc::create(CC_CALLBACK_0(Sheep::funCallback, this));
	Sequence* sequence = Sequence::create(move, func, NULL);
	if(!eaten)	player->runAction(sequence);
	//pos = des;
}
void Sheep::RandomMove()
{
	Pos des;
	int temp, symbolx, symboly;
	symbolx = rand() % 2 ? 1 : -1;
	symboly = rand() % 2 ? 1 : -1;
	des.x = pos.x + rand() % 150 * symbolx;
	des.y = pos.y + rand() % 150 * symboly;
	Move(des);
}
void Sheep::funCallback()
{
	hp--;
	pos.x = des2.x;
	pos.y = des2.y;
	if (hp <= 0) {
		if (!eaten)
		{
			CCActionInterval* fadeout = CCFadeOut::create(1);
		if (player == NULL) return;
		if (player != NULL) player->runAction(fadeout);
		life = false;
		return;
		}
	}
	RandomMove();
	return;
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

	pos.x = abs(rand() % 3000);
	pos.y = abs(rand() % 3000);

	des2.x = pos.x;
	des2.y = pos.y;
	player = CCSprite::create("wolf.png");
//  player->setPosition(ccp(pos.x, pos.y));
	player->setPosition(Vec2(pos.x, pos.y));
	sum++;
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
		}
	}
	return res;
}
bool Wolf::Catch()
{
	if (prey == NULL) return false;
	if (GetDistance(prey->getPos()) <= 100) {
		prey->eaten = true;
		prey->disappear();
		hp = hp + 3;
		for (int i = 0; i < li.size(); i++)
			if (li[i] == prey) {
				li[i] == NULL;
				li.erase(li.begin() + i);
			}
		prey = NULL;
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
int Wolf::GetSheepSum() {
	int ssum=0;
	for (int i = 0; i < li.size(); i++)
		if (li[i] != NULL) ssum++;
	return ssum;
}
Wolf::~Wolf()
{
	CCActionInterval * fadeout = CCFadeOut::create(1);
	player->runAction(fadeout);
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
	pos.x = abs(rand() % 4000);
	pos.y = abs(rand() % 4000);
	des2.x = pos.x;
	des2.y = pos.y;
	player = CCSprite::create("sheep.png");
	player->setPosition(Vec2(pos.x, pos.y));
}
Sheep::~Sheep()
{
	CCActionInterval* fadeout = CCFadeOut::create(1);
	player->runAction(fadeout);
	player = NULL;
}

void Sheep::disappear()
{
	CCActionInterval* fadeout = CCFadeOut::create(1);
	player->runAction(fadeout);
}