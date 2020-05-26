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
#include "animals.h"


USING_NS_CC;
using namespace cocos2d::ui;
//static
Scene *HelloWorld::createScene() {
    return HelloWorld::create();
}
void HelloWorld::updateWolf(const int n) {
    wolfNumLbl->setString(StringUtils::format("No. of Wolves: %d", n));
}
void HelloWorld::updateSheep(const int n) {
    sheepNumLbl->setString(StringUtils::format("No. of Sheep: %d", n));
}
void HelloWorld::updateGrass(const int n) {
    grassNumLbl->setString(StringUtils::format("No. of Grass: %d", n));
}
static double mapBasicX = 0;
static double mapBasicY = 180;

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename) {
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

    const auto VISIBLE_SIZE = Director::getInstance()->getVisibleSize();
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
        const float x = origin.x + VISIBLE_SIZE.width - closeItem->getContentSize().width / 2;
        const float y = origin.y + closeItem->getContentSize().height / 2;
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
    panelbg->setContentSize(cocos2d::Size(VISIBLE_SIZE.width, mapBasicY));
    panelbg->setAnchorPoint(Vec2(0, 0));
    panelbg->setPosition(Vec2(0, 0));
    this->addChild(panelbg, 1);

    // 三个滑动条
    auto slider1 = Slider::create();
    slider1->setName("slider1");
    slider1->loadBarTexture("Slider_Back.png"); // what the slider looks like
    slider1->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
    slider1->loadProgressBarTexture("Slider_PressBar.png");
    slider1->setPosition(Vec2(335, 50));
    slider1->setPercent(50);
    slider1->setContentSize(cocos2d::Size(300, 20));
    slider1->addEventListener(CC_CALLBACK_2(HelloWorld::sliderEvent, this));
    panelbg->addChild(slider1, 1);

    auto slider2 = Slider::create();
    slider2->setName("slider2");
    slider2->loadBarTexture("Slider_Back.png"); // what the slider looks like
    slider2->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
    slider2->loadProgressBarTexture("Slider_PressBar.png");
    slider2->setPosition(Vec2(335, 90));
    slider2->setPercent(50);
    slider2->setContentSize(cocos2d::Size(300, 20));
    slider2->addEventListener(CC_CALLBACK_2(HelloWorld::sliderEvent, this));
    panelbg->addChild(slider2, 1);

    auto slider3 = Slider::create();
    slider3->setName("slider3");
    slider3->loadBarTexture("Slider_Back.png"); // what the slider looks like
    slider3->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
    slider3->loadProgressBarTexture("Slider_PressBar.png");
    slider3->setPosition(Vec2(335, 130));
    slider3->setPercent(50);
    slider3->setContentSize(cocos2d::Size(300, 20));
    slider3->addEventListener(CC_CALLBACK_2(HelloWorld::sliderEvent, this));
    panelbg->addChild(slider3, 1);

    //三个百分比标签
    const std::string FONT_MARKFELT = "fonts/Marker Felt.ttf";
    const std::string FONT_ARIAL = "fonts/arial.ttf";
    auto label1 = Label::createWithTTF("50%", FONT_MARKFELT, 22);
    label1->setName("label1");
    label1->setPosition(475, 50);
    label1->setTextColor(cocos2d::Color4B::WHITE);
    panelbg->addChild(label1, 1);

    auto label2 = Label::createWithTTF("50%", FONT_MARKFELT, 22);
    label2->setName("label2");
    label2->setPosition(475, 90);
    label2->setTextColor(cocos2d::Color4B::WHITE);
    panelbg->addChild(label2, 1);

    auto label3 = Label::createWithTTF("50%", FONT_MARKFELT, 22);
    label3->setName("label3");
    label3->setPosition(475, 130);
    label3->setTextColor(cocos2d::Color4B::WHITE);
    panelbg->addChild(label3, 1);

    //五个名称标签
    auto label1_1 = Label::createWithTTF("Grass Growth Rate", FONT_MARKFELT, 22);
    label1_1->setName("label1_1");
    label1_1->setPosition(120, 50);
    label1_1->setTextColor(cocos2d::Color4B::WHITE);
    label1_1->enableBold();
    panelbg->addChild(label1_1, 1);

    auto label2_1 = Label::createWithTTF("Wolf Growth Rate", FONT_MARKFELT, 22);
    label2_1->setName("label2_1");
    label2_1->setPosition(120, 90);
    label2_1->setTextColor(cocos2d::Color4B::WHITE);
    label2_1->enableBold();
    panelbg->addChild(label2_1, 1);

    auto label3_1 = Label::createWithTTF("Sheep Growth Rate", FONT_MARKFELT, 22);
    label3_1->setName("label3_1");
    label3_1->setPosition(120, 130);
    label3_1->setTextColor(cocos2d::Color4B::WHITE);
    label3_1->enableBold();
    panelbg->addChild(label3_1, 1);

    auto label4 = Label::createWithTTF("Initial Wolf Num", FONT_MARKFELT, 22);
    label4->setName("label4");
    label4->setPosition(630, 90);
    label4->setTextColor(cocos2d::Color4B::WHITE);
    label4->enableBold();
    panelbg->addChild(label4, 1);

    auto label5 = Label::createWithTTF("Initial Sheep Num", FONT_MARKFELT, 22);
    label5->setName("label5");
    label5->setPosition(630, 130);
    label5->setTextColor(cocos2d::Color4B::WHITE);
    label5->enableBold();
    panelbg->addChild(label5, 1);

    //警告标签
    auto labelAlert = Label::createWithTTF("", FONT_MARKFELT, 23);
    labelAlert->setName("labelAlert");
    labelAlert->setPosition(1000, 90);
    labelAlert->setTextColor(cocos2d::Color4B::RED);
    labelAlert->enableShadow();
    panelbg->addChild(labelAlert, 1);

    //开始按钮
    auto start_btn = Button::create("", "white.png", "white.png");
    start_btn->setName("start_btn");
    start_btn->setTitleText("START!");
    start_btn->setTitleFontSize(30);
    start_btn->setTitleColor(cocos2d::Color3B::RED);
    start_btn->setPosition(cocos2d::Vec2(1000, 130));
    panelbg->addChild(start_btn, 1);

    //输入文本框
    auto textField1 = TextField::create("e.g. 1000", FONT_ARIAL, 25);
    textField1->setName("textField1");
    textField1->setPosition(cocos2d::Vec2(800, 130));
    textField1->setColor(cocos2d::Color3B::WHITE);
    textField1->setTextColor(cocos2d::Color4B::WHITE);
    //textField1->setSize(cocos2d::Size(100, 80));
    textField1->setMaxLengthEnabled(true);
    textField1->setMaxLength(6);
    textField1->setCursorEnabled(true);
    panelbg->addChild(textField1);

    auto textField2 = TextField::create("e.g. 100", FONT_ARIAL, 25);
    textField2->setName("textField2");
    textField2->setPosition(cocos2d::Vec2(800, 90));
    textField2->setColor(cocos2d::Color3B::WHITE);
    textField2->setTextColor(cocos2d::Color4B::WHITE);
    //textField2->setSize(cocos2d::Size(100, 80));
    textField2->setMaxLengthEnabled(true);
    textField2->setMaxLength(6);
    textField2->setCursorEnabled(true);
    panelbg->addChild(textField2);

    //4.Listener
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    // 显示数量信息
    auto infoArea = Sprite::create("white.png");
    infoArea->setName("infoArea");
    infoArea->setAnchorPoint(Vec2(0, 1));
    infoArea->setOpacity(150);
    infoArea->setPosition(Vec2(start_btn->getRightBoundary() + 100,
        start_btn->getTopBoundary()));
    infoArea->setContentSize(cocos2d::Size::ZERO);
    infoArea->setVisible(false);
    panelbg->addChild(infoArea, 1);

    sheepNumLbl = Label::createWithTTF("No. of Sheep:", FONT_MARKFELT, 22);
    sheepNumLbl->setName("sheepNumLbl");
    sheepNumLbl->setAnchorPoint(Vec2(0, 1));
    infoArea->addChild(sheepNumLbl);

    const auto LABEL_HEIGHT = sheepNumLbl->getContentSize().height;
    wolfNumLbl = Label::createWithTTF("No. of Wolves:", FONT_MARKFELT, 22);
    wolfNumLbl->setName("wolfNumLbl");
    wolfNumLbl->setAnchorPoint(Vec2(0, 1));
    wolfNumLbl->setPosition(Vec2(0, -(LABEL_HEIGHT + 10)));
    infoArea->addChild(wolfNumLbl);

    grassNumLbl = Label::createWithTTF("No. of Grass:", FONT_MARKFELT, 22);
    grassNumLbl->setName("grassNumLbl");
    grassNumLbl->setAnchorPoint(Vec2(0, 1));
    grassNumLbl->setPosition(Vec2(0, -2 * (LABEL_HEIGHT + 10)));
    infoArea->addChild(grassNumLbl);

    start_btn->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type) {

        auto _start_btn = dynamic_cast<Button *>(sender);
        auto _panelbg = (Sprite *)this->getChildByName("panelbg");
        auto _textField1 = (TextField *)_panelbg->getChildByName("textField1");
        auto _textField2 = (TextField *)_panelbg->getChildByName("textField2");
        //log("%s", _textField1->getString().c_str());
        //log("%s", _textField2->getString().c_str());
        auto input_sheep = _textField1->getString();
        auto input_wolf = _textField2->getString();
        auto _labelAlert = (Label *)_panelbg->getChildByName("labelAlert");
        int nSheep = 1, nWolf = 1;
        try {
            nSheep = std::stoi(input_sheep);
            nWolf = std::stoi(input_wolf);
            //log("%d", nSheep);
            //log("%d", nWolf);
            if (nSheep <= 0 || nSheep > 100000 || nWolf <= 0 || nWolf > 100000)
                throw std::out_of_range("");
        }
        catch (const std::invalid_argument &) {
            _labelAlert->setString("Input is NOT NUMERAL!");
            return;
        }
        catch (const std::out_of_range &) {
            _labelAlert->setString("Please input within 1-100000 !");
            return;
        }
        catch (...) {
            _labelAlert->setString("Unknown error...");
            return;
        }
        _labelAlert->setString("Loading...");

        switch (type) {
            case ui::Widget::TouchEventType::ENDED:
                if (_start_btn->isEnabled()) { //TODO: 未enabled时怎么重新开始地图
                    _start_btn->setEnabled(false);
                    
                    //加载地图
                    m = new MAP(mapBasicX, mapBasicY, this, 100, 100, nSheep, nWolf);
                    TMXTiledMap *map = m->map;
                    //小地图
                    const constexpr double PADDING = 5;
                    const Rect rect = Director::getInstance()->getOpenGLView()->getVisibleRect();
                    const auto RECT_WIDTH = rect.size.width;
                    const auto RECT_HEIGHT = rect.size.height;
                    //小地图背景
                    auto smallMapBase = Sprite::create("white.png");
                    smallMapBase->setName("smallMapBase");
                    const constexpr double smallMapWidth = 140;
                    const constexpr double smallMapHeight = 140;
                    smallMapBase->setContentSize(cocos2d::Size(smallMapWidth, smallMapHeight));
                    smallMapBase->setColor(cocos2d::Color3B::ORANGE);
                    smallMapBase->setAnchorPoint(Vec2::ZERO);
                    smallMapBase->setPosition(origin.x + RECT_WIDTH - PADDING - smallMapWidth, origin.y + RECT_HEIGHT - PADDING - smallMapHeight);
                    smallMapBase->setOpacity(150);
                    this->addChild(smallMapBase, 2);

                    //小地图表示屏幕视野的矩形
                    auto smallMapRect = Sprite::create("white.png");
                    double smallMapRectWidth = smallMapWidth / map->getContentSize().width * (RECT_WIDTH - mapBasicX);
                    double smallMapRectHeight = smallMapHeight / map->getContentSize().height * (RECT_HEIGHT - mapBasicY);
                    smallMapRect->setContentSize(cocos2d::Size(smallMapRectWidth, smallMapRectHeight));
                    smallMapRect->setColor(cocos2d::Color3B::RED);
                    smallMapRect->setAnchorPoint(Vec2::ZERO);
                    smallMapRect->setPosition(Vec2::ZERO);
                    smallMapRect->setOpacity(200);
                    smallMapRect->setName("smallMapRect");
                    smallMapBase->addChild(smallMapRect, 2);

                    const auto _infoArea = (Sprite*)_panelbg->getChildByName("infoArea");
                    _infoArea->setVisible(true);
                    started = true;
                }
                break;
        }

        _labelAlert->setString("Enjoy!");
    });

    srand(time(NULL));
    return true;
}


void HelloWorld::menuCloseCallback(Ref *pSender) {
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::sliderEvent(Ref *pSender, Slider::EventType type) {
    switch (type) {
        case Slider::EventType::ON_PERCENTAGE_CHANGED:
        {
            auto _slider = dynamic_cast<Slider *>(pSender);
            auto _panelbg = (Sprite *)this->getChildByName("panelbg");

            const std::string _sliderName = _slider->getName();
            const char _sliderNo = _sliderName.back();
            auto _label = (Label *)_panelbg->getChildByName(StringUtils::format("label%c", _sliderNo));

            const int percent = _slider->getPercent();
            switch (_sliderNo) {
                case '1':
                    grassRate = percent;
                    break;
                case '2':
                    wolfRate = percent;
                    break;
                case '3':
                    sheepRate = percent;
                    break;
            }
            _label->setString(StringUtils::format("%d%%", percent));

            //log("%s --> %d %%", _sliderName.c_str(), percent);
        }
        break;
    }
}
// Implementation of the keyboard event callback function prototype
void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {

    auto panelbg = (Sprite *)getChildByName("panelbg");
    auto _start_btn = (Button *)panelbg->getChildByName("start_btn");
    if (_start_btn->isEnabled()) {
        return;
    }
    auto _map = (TMXTiledMap *)getChildByName("bgmap");

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
    auto _smallMapBase = (Sprite *)getChildByName("smallMapBase");
    auto _smallMapRect = (Sprite *)_smallMapBase->getChildByName("smallMapRect");
    double baseWidth = _smallMapBase->getContentSize().width;
    double baseHeight = _smallMapBase->getContentSize().height;
    _smallMapRect->setPosition(Vec2(baseWidth * (mapBasicX - currentX) / mapWidth, baseHeight * (mapBasicY - currentY) / mapHeight));
    //log("%f %f", _smallMapBase->getPosition().x, _smallMapBase->getPosition().y);
    //log("%f %f", _smallMapRect->getPosition().x, _smallMapRect->getPosition().y);
}
