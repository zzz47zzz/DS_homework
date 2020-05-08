/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;
using namespace cocos2d::ui;
//static
Scene* HelloWorld::createScene() {
    return HelloWorld::create();
}
static double mapBasicX = 0;
static double mapBasicY = 180;

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename) {
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
    //////////////////////////////
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0) {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    ////////////////////////////
    // 3. add your codes below...
    //地图


    //面板背景
    auto panelbg = Sprite::create("panelbg.png");
    panelbg->setName("panelbg");
    panelbg->setContentSize(cocos2d::Size(visibleSize.width, mapBasicY));
    panelbg->setAnchorPoint(Vec2(0, 0));
    panelbg->setPosition(Vec2(0, 0));
    this->addChild(panelbg, 1);

    // 三个滑动条
    auto slider1 = Slider::create();
    slider1->setName("slider1");
    slider1->loadBarTexture("Slider_Back.png"); // what the slider looks like
    slider1->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
    slider1->loadProgressBarTexture("Slider_PressBar.png");
    slider1->setPosition(Vec2(300, 50));
    slider1->setPercent(50);
    slider1->setContentSize(cocos2d::Size(300, 20));
    slider1->addTouchEventListener(CC_CALLBACK_2(HelloWorld::sliderEvent, this));
    panelbg->addChild(slider1, 1);

    auto slider2 = Slider::create();
    slider2->setName("slider2");
    slider2->loadBarTexture("Slider_Back.png"); // what the slider looks like
    slider2->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
    slider2->loadProgressBarTexture("Slider_PressBar.png");
    slider2->setPosition(Vec2(300, 90));
    slider2->setPercent(50);
    slider2->setContentSize(cocos2d::Size(300, 20));
    slider2->addTouchEventListener(CC_CALLBACK_2(HelloWorld::sliderEvent, this));
    panelbg->addChild(slider2, 1);

    auto slider3 = Slider::create();
    slider3->setName("slider3");
    slider3->loadBarTexture("Slider_Back.png"); // what the slider looks like
    slider3->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
    slider3->loadProgressBarTexture("Slider_PressBar.png");
    slider3->setPosition(Vec2(300, 130));
    slider3->setPercent(50);
    slider3->setContentSize(cocos2d::Size(300, 20));
    slider3->addTouchEventListener(CC_CALLBACK_2(HelloWorld::sliderEvent, this));
    panelbg->addChild(slider3, 1);

    //三个百分比标签
    auto label1 = Label::createWithTTF("50%", "fonts/Marker Felt.ttf", 22);
    label1->setName("label1");
    label1->setPosition(450, 50);
    label1->setTextColor(cocos2d::Color4B::WHITE);
    panelbg->addChild(label1, 1);

    auto label2 = Label::createWithTTF("50%", "fonts/Marker Felt.ttf", 22);
    label2->setName("label2");
    label2->setPosition(450, 90);
    label2->setTextColor(cocos2d::Color4B::WHITE);
    panelbg->addChild(label2, 1);

    auto label3 = Label::createWithTTF("50%", "fonts/Marker Felt.ttf", 22);
    label3->setName("label3");
    label3->setPosition(450, 130);
    label3->setTextColor(cocos2d::Color4B::WHITE);
    panelbg->addChild(label3, 1);

    //三个名称标签
    auto label1_1 = Label::createWithTTF("grass growth rate", "fonts/Marker Felt.ttf", 22);
    label1_1->setName("label1_1");
    label1_1->setPosition(90, 50);
    label1_1->setTextColor(cocos2d::Color4B::WHITE);
    panelbg->addChild(label1_1, 1);

    auto label2_1 = Label::createWithTTF("cow growth rate", "fonts/Marker Felt.ttf", 22);
    label2_1->setName("label2_1");
    label2_1->setPosition(90, 90);
    label2_1->setTextColor(cocos2d::Color4B::WHITE);
    panelbg->addChild(label2_1, 1);

    auto label3_1 = Label::createWithTTF("wolf growth rate", "fonts/Marker Felt.ttf", 22);
    label3_1->setName("label3_1");
    label3_1->setPosition(90, 130);
    label3_1->setTextColor(cocos2d::Color4B::WHITE);
    panelbg->addChild(label3_1, 1);

    //开始按钮
    auto start_btn = Button::create("", "white.png", "white.png");
    start_btn->setName("start_btn");
    start_btn->setTitleText("start");
    start_btn->setTitleFontSize(32);
    start_btn->setTitleColor(cocos2d::Color3B::RED);
    start_btn->setPosition(cocos2d::Vec2(1000, 150));
    panelbg->addChild(start_btn, 1);



    //4.Listener
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    start_btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        cocos2d::ui::Button* _start_btn = dynamic_cast<Button*>(sender);

        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            if (_start_btn->isEnabled()) {
                _start_btn->setEnabled(false);
                //加载地图
                MAP* m = new MAP(mapBasicX, mapBasicY, this, 100, 100);
                TMXTiledMap* map = m->map;
                //小地图
                double padding = 5;
                //小地图背景
                auto smallMapBase = Sprite::create("white.png");
                smallMapBase->setName("smallMapBase");
                double smallMapWidth = 140;
                double smallMapHeight = 140;
                //auto smallMapBase = (Sprite*)this->getChildByName("smallMapBase");
                smallMapBase->setContentSize(cocos2d::Size(smallMapWidth, smallMapHeight));
                smallMapBase->setColor(cocos2d::Color3B::ORANGE);
                smallMapBase->setAnchorPoint(Vec2(0, 0));
                smallMapBase->setPosition(origin.x + visibleSize.width - padding - smallMapWidth, origin.y + visibleSize.height - padding - smallMapHeight);
                smallMapBase->setOpacity(150);
                this->addChild(smallMapBase, 1);

                //小地图表示屏幕视野的矩形
                auto smallMapRect = Sprite::create("white.png");
                double smallMapRectWidth = smallMapWidth / map->getContentSize().width * (visibleSize.width - mapBasicX);
                double smallMapRectHeight = smallMapHeight / map->getContentSize().height * (visibleSize.height - mapBasicY);
                //auto smallMapRect = (Sprite*)smallMapBase->getChildByName("smallMapRect");
                smallMapRect->setContentSize(cocos2d::Size(smallMapRectWidth, smallMapRectHeight));
                smallMapRect->setColor(cocos2d::Color3B::RED);
                smallMapRect->setAnchorPoint(Vec2(0, 0));
                smallMapRect->setPosition(Vec2::ZERO);
                smallMapRect->setOpacity(200);
                smallMapRect->setName("smallMapRect");
                smallMapBase->addChild(smallMapRect, 1);

            }
            break;
        default:
            break;
        }
        });

    srand(time(NULL));
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender) {
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::sliderEvent(Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
    switch (type) {
    case cocos2d::ui::Widget::TouchEventType::ENDED:

        cocos2d::ui::Slider* _slider = dynamic_cast<Slider*>(pSender);
        auto _panelbg = (Sprite*)this->getChildByName("panelbg");

        int percent = _slider->getPercent();
        std::string _sliderName = _slider->getName();
        std::string LABEL = "label";
        std::string num = _sliderName.substr(_sliderName.size() - 1);//获取最后一位数字
        auto _label = (Label*)_panelbg->getChildByName(LABEL.append(num));
        _label->setString(std::to_string(percent).append("%"));

        log("%s --> %d %%", _sliderName.c_str(), percent);

        break;
    }
}
// Implementation of the keyboard event callback function prototype
void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {

    auto panelbg = (Sprite*)getChildByName("panelbg");
    auto _start_btn = (Button*)panelbg->getChildByName("start_btn");
    if (_start_btn->isEnabled()) {
        return;
    }
    auto _map = (TMXTiledMap*)getChildByName("bgmap");

    double currentX = _map->getPosition().x;
    double currentY = _map->getPosition().y;

    double mapWidth = _map->getContentSize().width;
    double mapHeight = _map->getContentSize().height;

    double visibleWidth = Director::getInstance()->getVisibleSize().width;
    double visibleHeight = Director::getInstance()->getVisibleSize().height;

    double deltaX = _map->getTileSize().width * 5;
    double deltaY = _map->getTileSize().height * 5;


    if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW || keyCode == EventKeyboard::KeyCode::KEY_W) {
        //超出范围
        if (currentY + mapHeight - deltaY < visibleHeight) {
            _map->setPosition(Vec2(currentX, visibleHeight - mapHeight));
        }
        else {
            _map->setPosition(Vec2(currentX, currentY - deltaY));
        }
    }
    else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW || keyCode == EventKeyboard::KeyCode::KEY_S) {
        //超出范围
        if (currentY + deltaY > mapBasicY) {
            _map->setPosition(Vec2(currentX, mapBasicY));
        }
        else {
            _map->setPosition(Vec2(currentX, currentY + deltaY));
        }
    }
    else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW || keyCode == EventKeyboard::KeyCode::KEY_A) {
        //超出范围
        if (currentX + deltaX > mapBasicX) {
            _map->setPosition(Vec2(mapBasicX, currentY));
        }
        else {
            _map->setPosition(Vec2(currentX + deltaX, currentY));
        }
    }
    else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW || keyCode == EventKeyboard::KeyCode::KEY_D) {
        //超出范围
        if (currentX + mapWidth - deltaX < visibleWidth) {
            _map->setPosition(Vec2(visibleWidth - mapWidth, currentY));
        }
        else {
            _map->setPosition(Vec2(currentX - deltaX, currentY));
        }
    }

    //设置小地图
    currentX = _map->getPosition().x;
    currentY = _map->getPosition().y;
    auto _smallMapBase = (Sprite*)getChildByName("smallMapBase");
    auto _smallMapRect = (Sprite*)_smallMapBase->getChildByName("smallMapRect");
    double baseWidth = _smallMapBase->getContentSize().width;
    double baseHeight = _smallMapBase->getContentSize().height;
    _smallMapRect->setPosition(Vec2(baseWidth * (mapBasicX - currentX) / mapWidth, baseHeight * (mapBasicY - currentY) / mapHeight));
}
