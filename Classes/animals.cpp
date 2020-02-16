#include"animals.h"

void Animal::Move(Pos des)
{
	CCMoveTo* move = CCMoveTo::create((GetDistance(des) / speed), ccp(des.x, des.y));
	player->runAction(move);
	pos = des;
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

Wolf::Wolf(int ahp, double asight, double aspeed)
{

	hp = ahp;
	sight = asight;
	speed = aspeed;
	degree = 0;
	prey = NULL;

	auto glView = Director::getInstance()->getOpenGLView();
	auto frameSize = glView->getFrameSize();
	pos.x = rand() % (int(frameSize.width));
	pos.y = rand() % (int(frameSize.height));
	player = CCSprite::create("wolf.png");
	player->setPosition(ccp(pos.x, pos.y));

}
Pos Wolf::FindPrey(vector<Sheep *> li)
{
	Pos res, temp;
	double dis, min = DBL_MAX;
	for (int i = 0; i < li.size(); i++)
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
	if (GetDistance(prey->getPos()) <= 30) {
		Sheep * temp = prey;
		prey = NULL;
		delete temp;
		return true;
		degree = 0;
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