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

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
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
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    ////////////////////////////
    // 3. add your codes below...

    //加载地图
    auto map = TMXTiledMap::create("backgroundmap.tmx");
    map->setPosition(Vec2(0,150));
    map->setAnchorPoint(Vec2(0, 0));
    this->addChild(map, 0);

    //三个标签
    auto label1 = Label::createWithTTF("50%", "fonts/Marker Felt.ttf", 22);
    label1->setName("label1");
    label1->setPosition(370, 40);
    label1->setTextColor(cocos2d::Color4B::WHITE);
    this->addChild(label1,1);

    auto label2 = Label::createWithTTF("50%", "fonts/Marker Felt.ttf", 22);
    label2->setName("label2");
    label2->setPosition(370, 80);
    label2->setTextColor(cocos2d::Color4B::WHITE);
    this->addChild(label2, 1);

    auto label3 = Label::createWithTTF("50%", "fonts/Marker Felt.ttf", 22);
    label3->setName("label3");
    label3->setPosition(370, 120);
    label3->setTextColor(cocos2d::Color4B::WHITE);
    this->addChild(label3, 1);

    // 三个滑动条
    auto slider1 = Slider::create();
    slider1->setName("slider1");
    slider1->loadBarTexture("Slider_Back.png"); // what the slider looks like
    slider1->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
    slider1->loadProgressBarTexture("Slider_PressBar.png");
    slider1->setPosition(Vec2(200, 40));
    slider1->setPercent(50);
    slider1->setSize(cocos2d::Size(300, 20));
    slider1->addTouchEventListener(CC_CALLBACK_2(HelloWorld::sliderEvent,this));
    this->addChild(slider1, 1);

    auto slider2 = Slider::create();
    slider2->setName("slider2");
    slider2->loadBarTexture("Slider_Back.png"); // what the slider looks like
    slider2->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
    slider2->loadProgressBarTexture("Slider_PressBar.png");
    slider2->setPosition(Vec2(200, 80));
    slider2->setPercent(50);
    slider1->setSize(cocos2d::Size(300, 20));
    slider2->addTouchEventListener(CC_CALLBACK_2(HelloWorld::sliderEvent, this));
    this->addChild(slider2, 1);

    auto slider3 = Slider::create();
    slider3->setName("slider3");
    slider3->loadBarTexture("Slider_Back.png"); // what the slider looks like
    slider3->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
    slider3->loadProgressBarTexture("Slider_PressBar.png");
    slider3->setPosition(Vec2(200, 120));
    slider3->setPercent(50);
    slider1->setSize(cocos2d::Size(300, 20));
    slider3->addTouchEventListener(CC_CALLBACK_2(HelloWorld::sliderEvent, this));
    this->addChild(slider3, 1);



    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::sliderEvent(Ref* pSender, cocos2d::ui::Widget::TouchEventType type)
{
    switch (type)
    {
    case cocos2d::ui::Widget::TouchEventType::ENDED:

        cocos2d::ui::Slider* _slider = dynamic_cast<Slider*>(pSender);
        int percent = _slider->getPercent();
        std::string _sliderName = _slider->getName();
        
        std::string LABEL = "label";
        std::string num = _sliderName.substr(_sliderName.size()-1);//获取最后一位数字
        auto _label = (Label*)this->getChildByName(LABEL.append(num));
        _label->setString(std::to_string(percent).append("%"));
   
        log("%s --> %d %%", _sliderName.c_str(),percent);

        break;
    }
}