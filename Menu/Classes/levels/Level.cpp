#include "levels\Level.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene *Level::createScene() {
    auto scene = Scene::create();
    auto layer = Level::create();
    scene->addChild(layer);

    log("Level created");
    return scene;
}

bool Level::init() {
    if (!Layer::init()) {
        return false;
    }

    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    auto bgLevel = Sprite::create("pic/bgLevel.jpg");
    bgLevel->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(bgLevel, 0, "bgLevel");

    levelTTFConfig = TTFConfig("font/Foglihten.ttf", 24);
    
    //auto pauseMenu = MenuItemImage::create("pic/PauseNormal.png", "pic/PauseSelected.png",
    //                                       CC_CALLBACK_1(Level::pauseMenuItemCallback, this));
    //pauseMenu->setPosition(Vec2(origin.x + pauseMenu->getContentSize().width / 2,
    //                            origin.y + visibleSize.height - pauseMenu->getContentSize().height / 2));
    
    //auto menu = Menu::create(pauseMenu);
    //menu->setPosition(Vec2::ZERO);
    //this->addChild(menu);
    //
    return true;
}

Label * Level::createLabelWithTTF(TTFConfig & ttfConfig, const std::string & text,
                                  Vec2 & position, Vec2 & anchorPoint,
                                  TextHAlignment hAlignment, int maxLineWidth) {
    auto myLabel = Label::createWithTTF(ttfConfig, text, hAlignment, maxLineWidth);
    myLabel->setAnchorPoint(anchorPoint);
    myLabel->setPosition(position);

    return myLabel;
}

void Level::onEnterTransitionDidFinish() {
    Layer::onEnterTransitionDidFinish();
    if (UserDefault::getInstance()->getBoolForKey("music_key")) {
        SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    }
    log("Level onEnterTransitionDidFinish");
}

//void Level::pauseMenuItemCallback(cocos2d::Ref * pSender) {
//
//}
//
//void Level::nextLevelMenuItemCallBack(cocos2d::Ref * pSender) {
//}