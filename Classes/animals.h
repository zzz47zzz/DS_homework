#ifndef ANI_H
#define ANI_H

#include <vector>
#include <stdlib.h>
#include "HelloWorldScene.h"
USING_NS_CC;
using namespace std;

struct Pos // λ��
{
    float x;
    float y;
};
class Animal {
public:
    Pos getPos() //����λ��
    {
        return pos;
    }
    inline void DegreeIncrease(int t = 1)//����������
    {
        degree += t;
    }
    void HpDecline(int t = 1) // ��������
    {
        hp -= t;
    }
    double GetDistance(Pos temp) {
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
    CCSprite *player; //����
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    bool life = true;
    static MAP *map;
    bool CheckRiver(Pos);
protected:
    Pos pos; //λ��
    Pos des2; //��ǰ����Ŀ��
    int hp; //Ѫ��������������ʱ���,�����壩
    int degree; //����ֵ
    double speed; //�ٶ�
    double sight; //��Ұ

};

class Wolf;
class Sheep :public Animal {
public:
    Sheep(int ahp = 6, double asight = 110, double aspeed = 15);//��������λ�����أ�����/��
    ~Sheep();
    void Move(Pos);//�ƶ�����ʾ
    void RandomMove(); //δ��������ǰ����ƶ�
    void funCallback();
    Wolf *wolf;
    bool eaten = false;
    void disappear();
    cocos2d::Vec2 find_grass(cocos2d::Vec2 pos, MAP *m, int vision);
};

class Wolf :public Animal {
public:
    Wolf(int ahp = 3, double asight = 200, double aspeed = 55);//��������λ�����أ�����/��
    ~Wolf();
    bool Catch(); //��ȡʳ��ɹ����
    bool Check(); //����Ƿ���׷�����Ｐ��ǰ׷���������Ƿ�������Ұ֮��
    Pos FindPrey(vector<Sheep *> li); //Ѱ������ ��ǰʹ��stl������Ӧ�����б�������Լ���ɵ����ݽṹ
    Sheep *prey; //��ǰ����������
    void Move(Pos);//�ƶ�����ʾ
    void RandomMove(); //δ��������ǰ����ƶ�
    void funCallback();
    static vector<Sheep *> li;
    int num;
    static int sum;
    static int GetWolfSum() { return sum; } //�����ǵ�����
    static int getSheepSum();
};

#endif 