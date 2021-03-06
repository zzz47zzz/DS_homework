#include"animals.h"
#include<iostream>

MAP *Animal::map = NULL;
vector<Sheep *> Wolf::li {};
int Wolf::sum = 0;
// int Wolf::ssum = 0; // static
bool Animal::CheckRiver(Pos pos) {
    const int x = pos.x / 25 + 4, y = 99 - pos.y / 25 - 2;
    if (x < 0 || y < 0 || x>99 || y>99) return false;
    if (map->geo_info[x][y]->type == Land::TYPE_RIVER) {
        return false;
    }
    else return true;
}

inline bool randByHP(const int hp) {
    return 2 * hp + log(float(RAND_MAX) / rand() - 1) >= 12;
}
void Wolf::funCallback() {
    hp--;
    pos.x = des2.x;
    pos.y = des2.y;
    const bool s = Catch();
    if (hp <= 0) {
        CCActionInterval *fadeout = CCFadeOut::create(1);
        player->runAction(fadeout);
        //if (prey != NULL) delete prey;
        prey = NULL;
        map->scene->updateWolf(--sum);
        life = false;
        return;
    }
    else if (randByHP(hp)) //根据hp以一定概率吃羊
        RandomMove();
    else if (!Check()) {
        const Pos target = FindPrey(li);
        if ((target.x == pos.x) && (target.y == pos.y))
            RandomMove();
        else
            Move(prey->getPos());
    }
    else
        Move(prey->getPos());
}

void Wolf::Move(Pos des) {
    des2.x = des.x;
    des2.y = des.y;
    //log("%d", hp);
    CCMoveTo *move = CCMoveTo::create((GetDistance(des) / (min(hp / 8.f, 1.5f) * speed)), Vec2(des.x, des.y));
    CallFunc *func = CallFunc::create(CC_CALLBACK_0(Wolf::funCallback, this));
    Sequence *sequence = Sequence::create(move, func, NULL);
    player->runAction(sequence);
    //pos = des;
}
void Wolf::RandomMove() {
    Pos des;
    int /*temp,*/ symbolx, symboly;
    bool tmp = false;
    while (!tmp) {
        symbolx = rand() % 2 ? 1 : -1;
        symboly = rand() % 2 ? 1 : -1;
        des.x = pos.x + rand() % 150 * symbolx;
        des.y = pos.y + rand() % 150 * symboly;
        tmp = CheckRiver(des);
    }
    Move(des);
}
void Sheep::Move(Pos des) {
    des2.x = des.x;
    des2.y = des.y;
    CCMoveTo *move = CCMoveTo::create((GetDistance(des) / (min(hp / 5.f, 1.5f) * speed)), Vec2(des.x, des.y));
    CallFunc *func = CallFunc::create(CC_CALLBACK_0(Sheep::funCallback, this));
    Sequence *sequence = Sequence::create(move, func, NULL);
    if (!eaten)	player->runAction(sequence);
    //pos = des;
}
void Sheep::RandomMove() {
    Pos des;
    int /*temp,*/ symbolx, symboly;
    bool tmp = false;
    while (!tmp) {
        symbolx = rand() % 2 ? 1 : -1;
        symboly = rand() % 2 ? 1 : -1;
        des.x = pos.x + rand() % 150 * symbolx;
        des.y = pos.y + rand() % 150 * symboly;
        tmp = CheckRiver(des);
    }
    Move(des);
}
void Sheep::funCallback() {
    --hp;
    bool get_grass = false;
    Vec2 grass;
    pos.x = des2.x;
    pos.y = des2.y;
    const int t1 = int(pos.x) / 25 + 4;
    const int t2 = 99 - int(pos.y) / 25 - 2;
    if ((t1 > 0) && (t1 < 100) && (t2 > 0) && (t2 < 100)) {
        get_grass = map->sheep_eat_grass(Vec2(t1, t2));
    }
    if (get_grass) hp += 2; // 一棵草加2 HP
    if (!CheckRiver(pos)) { // 羊涉水即死
        hp = 0;
    }
    if (hp <= 0) {
        if (!eaten) {
            if (!player) return;
            disappear();
            return;
        }
    }
    if ((t1 > 0) && (t1 < 100) && (t2 > 0) && (t2 < 100)) {
        grass = find_grass(Vec2(t1, t2), map, sight);
        Pos temp;
        temp.x = (grass.x - 4) * 25;
        temp.y = (99 - 2 - grass.y) * 25;
        if (grass.x != -1 || grass.y != -1) Move(temp); else RandomMove();
    }
    else RandomMove();
}


Wolf::Wolf(int ahp, double asight, double aspeed) :prey(nullptr) {
    hp = ahp;
    sight = asight;
    speed = aspeed;
    degree = 0;

    //auto glView = Director::getInstance()->getOpenGLView();
    //auto frameSize = glView->getFrameSize();
    bool tmp = false;
    while (!tmp) {
        pos.x = rand() % 2500;
        pos.y = rand() % 2500;
        tmp = CheckRiver(pos);
    }
    des2.x = pos.x;
    des2.y = pos.y;
    player = CCSprite::create("wolf.png");
//  player->setPosition(ccp(pos.x, pos.y));
    player->setPosition(Vec2(pos.x, pos.y));
    sum++;
}
Pos Wolf::FindPrey(vector<Sheep *> li) {
    Pos res { pos.x,pos.y };
    if (li.empty())return res;
    double min = DBL_MAX;
    const size_t n = li.size();
    if (n < 500 || isVisible()) { // update when visible
        for (size_t i = 0; i < n; ++i)
            if (li[i]) {
                const Pos temp = li[i]->getPos();
                const double dis = GetDistance(temp);
                if ((dis <= sight) && (dis < min)) {
                    min = dis;
                    res = temp;
                    prey = li[i];
                }
            }
        return res;
    }
    else {
        size_t iMin = 0, m = 0;
        { size_t _n = n; while (_n >>= 1)++m; }
        for (size_t i = 0; i < m; ++i) {
            size_t i2;
            Sheep *p;
            i2 = rand() % n; p = li[i2];
            if (i2 == iMin || !p)continue;
            const Pos tmp = p->getPos();
            const double dis = GetDistance(tmp);
            if ((dis <= sight) && (dis < min)) {
                iMin = i2;
                min = dis;
            }
        }
        return(prey = li[iMin])->getPos();
    }
}
bool Wolf::Catch() {
    if (!prey) return false;
    if (GetDistance(prey->getPos()) <= 100) {
        prey->eaten = true;
        prey->disappear();
        hp = hp + 3; //每只羊增加3体力
        for (size_t i = 0; i < li.size(); i++)
            if (li[i] == prey) {
                li.erase(li.begin() + i);
                break;
            }
        prey = nullptr;
        return true;
    }
    else
        return false;
}
bool Wolf::Check() {
    if (!prey) return false;
    if (GetDistance(prey->getPos()) > sight) {
        prey = nullptr;
        return false;
    }
    else
        return true;
}
int Wolf::getSheepSum() {
    //int ssum = 0;
    //for (size_t i = 0; i < li.size(); i++)
    //    if (li[i]) ++ssum;
    //return ssum;
    return li.size();
}
Wolf::~Wolf() {
    CCActionInterval *fadeout = CCFadeOut::create(1);
    player->runAction(fadeout);
    map->scene->updateWolf(sum);
    prey = NULL;
}

Sheep::Sheep(int ahp, double asight, double aspeed) {
    hp = ahp;
    sight = asight;
    speed = aspeed;
    degree = 0;
    //auto frameSize = Director::getInstance()->getOpenGLView()->getFrameSize();
    bool tmp = false;
    while (!tmp) {
        pos.x = rand() % 2500;
        pos.y = rand() % 2500;
        tmp = CheckRiver(pos);
    }
    des2.x = pos.x;
    des2.y = pos.y;
    player = CCSprite::create("sheep.png");
    player->setPosition(Vec2(pos.x, pos.y));
    //++Wolf::ssum;
}
Sheep::~Sheep() {
    disappear();
    player = NULL;
}

void Sheep::disappear() {
    CCActionInterval *fadeout = CCFadeOut::create(1);
    player->runAction(fadeout);
    //map->scene->updateSheep(--Wolf::ssum);
    map->scene->updateSheep(Wolf::getSheepSum());
    hp = 0;
    life = false;
}

cocos2d::Vec2 Sheep::find_grass(cocos2d::Vec2 pos, MAP *m, int vision) {
    bool rec[101][101];
    memset(rec, 0, sizeof rec);
    const int moves[3] = { 1, -1, 0 };
    queue<cocos2d::Vec2> q = queue<cocos2d::Vec2>();
    q.push(pos);
    cocos2d::Vec2 tmp;
    int step = 0;
    while (!q.empty()) {
        if (step > vision) break;
        tmp = q.front();
        q.pop();
        rec[int(tmp.x)][int(tmp.y)] = true;
        Land *_geo = m->geo_info[int(tmp.x)][int(tmp.y)];
        int tmp_type = _geo->type;
        if (tmp_type == Land::TYPE_BARREN || tmp_type == Land::TYPE_FERTILE) {
            Barren *tmp_of_Barren = static_cast<Barren *>(_geo);
            if (tmp_of_Barren) {
                if (tmp_of_Barren->currentStatus == Land::HAS_GRASS) {
                    if (tmp == pos) return cocos2d::Vec2(-1, -1);
                    else return tmp;
                }
            }
        }
        else if (tmp_type == Land::TYPE_FERTILE) {
            Fertile *tmp_of_Fertile = static_cast<Fertile *>(_geo);
            if (tmp_of_Fertile) {
                if (tmp_of_Fertile->currentStatus == Land::HAS_GRASS) {
                    if (tmp == pos) return cocos2d::Vec2(-1, -1);
                    else return tmp;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                const int newx = tmp.x + moves[i];
                const int newy = tmp.y + moves[i];
                if (newx >= 0 && newx < 100 && newy >= 0 && newy < 100 && !rec[newx][newy]) {
                    const cocos2d::Vec2 new_pos = cocos2d::Vec2(newx, newy);
                    q.push(new_pos);
                }
            }
        }
        step++;
    }
    return cocos2d::Vec2(-1, -1);// 搜索失败返回-1,-1
}
