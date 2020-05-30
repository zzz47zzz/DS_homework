#include "Land.h"

Land::Land(cocos2d::Vec2 pos, int type) : pos(pos), type(type) {}
int Land::GapOfBarrenGrass = 6;
int Land::lifeOfBarrenGrass = 200;
int Land::GapOfFertileGrass = 4;
int Land::lifeOfFertileGrass = 140;
Barren::Barren(cocos2d::Vec2 pos) :Land(pos, TYPE_BARREN) {
    currentStatus = rand() % 2;
    if (currentStatus == 0) gap = rand() % (GapOfBarrenGrass + 1);
    if (currentStatus == 1) life = rand() % (lifeOfBarrenGrass + 1);

}

int Barren::lifePass() {
    life--;
    return life;
}

int Barren::gapPass() {
    gap--;
    return gap;
}

void Barren::change() {
    if (currentStatus == HAS_GRASS) {
        currentStatus = NO_GRASS;

    }
    else {
        currentStatus = HAS_GRASS;
    }

}

Fertile::Fertile(cocos2d::Vec2 pos) :Land(pos, TYPE_FERTILE) {
    currentStatus = rand() % 2;
    if (currentStatus == 0) gap = rand() % (GapOfFertileGrass + 1);
    if (currentStatus == 1) life = rand() % (lifeOfFertileGrass + 1);

}

int Fertile::lifePass() {
    life--;
    return life;
}

int Fertile::gapPass() {
    gap--;
    return gap;
}

void Fertile::change() {
    if (currentStatus == HAS_GRASS) {
        currentStatus = NO_GRASS;

    }
    else {
        currentStatus = HAS_GRASS;

    }
}

River::River(cocos2d::Vec2 pos) :Land(pos, TYPE_RIVER) {}

Dessert::Dessert(cocos2d::Vec2 pos) : Land(pos, TYPE_DESSERT) {

}
