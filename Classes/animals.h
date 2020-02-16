#ifndef ANI_H
#define ANI_H

#include<vector>
#include <stdlib.h>
#include "HelloWorldScene.h"
USING_NS_CC;
using namespace std;

struct Pos // λ�ã�
{
	double x;
	double y;
};
class Animal {
public:
	Pos getPos() //����λ��
	{
		return pos;
	}
	void RandomMove(); //δ��������ǰ����ƶ�
	void Move(Pos);//�ƶ�����ʾ
	void DegreeIncrease(int t = 1)//����������
	{
		degree += t;
	}
	void HpDecline(int t = 1) // ��������
	{
		hp -= t;
	}
	double GetDistance(Pos temp)
	{
		return sqrt((temp.x - pos.x) * (temp.x - pos.x) + (temp.y - pos.y) * (temp.y - pos.y));
	}
	int ReturnHP() //����hpֵ
	{
		return hp;
	}
	int ReturnDegree() //���ؼ���ֵ
	{
		return degree;
	}
	CCSprite* player; //����

protected:
	Pos pos; //λ��
	int hp; //Ѫ��������������ʱ���,�����壩
	int degree; //����ֵ
	double speed; //�ٶ�
	double sight; //��Ұ

};

class Sheep:public Animal
{
};


class Wolf:public Animal
{
public:
	Wolf(int ahp = 5, double asight = 150, double aspeed = 50);//��������λ�����أ�����/��
	~Wolf();
	bool Catch(); //��ȡʳ��ɹ����
	bool Check(); //����Ƿ���׷�����Ｐ��ǰ׷���������Ƿ�������Ұ֮��
	Pos FindPrey(vector<Sheep *> li); //Ѱ������ ��ǰʹ��stl������Ӧ�����б�������Լ���ɵ����ݽṹ
private:
	Sheep * prey; //��ǰ����������
};

#endif 