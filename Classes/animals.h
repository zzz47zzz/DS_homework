#ifndef ANI_H
#define ANI_H

#include <vector>
#include <stdlib.h>
#include "HelloWorldScene.h"
USING_NS_CC;
using namespace std;

struct Pos // 位置
{
    float x;
    float y;
};
class Animal {
public:
    CCSprite *player; //精灵
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    bool life = true;
    static MAP *map;

    bool CheckRiver(Pos);
    Pos getPos() //返回位置
    {
        return pos;
    }
    void DegreeIncrease(int t = 1)//饥饿度增加
    {
        degree += t;
    }
    void HpDecline(int t = 1) // 寿命减少
    {
        hp -= t;
    }
    double GetDistance(Pos temp) {
        return sqrt((temp.x - pos.x) * (temp.x - pos.x) + (temp.y - pos.y) * (temp.y - pos.y));
    }
    int ReturnHP() //返回hp值
    {
        return hp;
    }
    int ReturnDegree() //返回饥饿值
    {
        return degree;
    }
    bool isVisible() {
        const float currentX = map->map->getPositionX();
        const float currentY = map->map->getPositionY();
        const float visibleWidth = Director::getInstance()->getVisibleSize().width;
        const float visibleHeight = Director::getInstance()->getVisibleSize().height;
        return Rect(0, 180, visibleWidth, visibleHeight - 180).containsPoint(Vec2(currentX + pos.x, currentY + pos.y));
    }
protected:
    Pos pos; //位置
    Pos des2; //当前动作目标
    int hp; //血条（距离死亡的时间等,待定义）
    int degree; //饥饿值
    double speed; //速度
    double sight; //视野

};

class Wolf;
class Sheep :public Animal {
public:
    //hp正常5，初始3
    Sheep(int ahp = 3, double asight = 110, double aspeed = 15);//后两个单位：像素；像素/秒
    ~Sheep();
    void Move(Pos);//移动及显示
    void RandomMove(); //未发现猎物前随机移动
    void funCallback();
    Wolf *wolf;
    bool eaten = false;
    void disappear();
    cocos2d::Vec2 find_grass(cocos2d::Vec2 pos, MAP *m, int vision);
};

class Wolf :public Animal {
public:
    //hp正常8，初始5
    Wolf(int ahp = 5, double asight = 200, double aspeed = 55);//后两个单位：像素；像素/秒
    ~Wolf();
    bool Catch(); //获取食物成功与否
    bool Check(); //检查是否有追捕猎物及当前追捕的猎物是否仍在视野之内
    Pos FindPrey(vector<Sheep *> li); //寻找猎物
    Sheep *prey; //当前锁定的猎物
    void Move(Pos);//移动及显示
    void RandomMove(); //未发现猎物前随机移动
    void funCallback();
    static vector<Sheep *> li;
    int num;
    static int sum/*, ssum*/;
    static int getWolfSum() { return sum; } //返回狼的数量
    static int getSheepSum();
    static int getActiveWolfSum() {}
};

#endif 