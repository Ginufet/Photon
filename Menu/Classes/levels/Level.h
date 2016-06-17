#pragma once
#include "PhotonGame.h"

class Level : public cocos2d::Layer {
protected:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    bool isLevelPassed;
    cocos2d::TTFConfig levelTTFConfig;
public:
    static cocos2d::Scene *createScene();

    virtual bool init();
    
    cocos2d::Label *createLabelWithTTF(cocos2d::TTFConfig &ttfConfig,
                                       const std::string &text, cocos2d::Vec2 &position,
                                       cocos2d::Vec2 &anchorPoint = cocos2d::Vec2(0.5,0.5),
                                       cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT,
                                       int maxLineWidth = 0);
    cocos2d::Sprite *createdLightSource();
    cocos2d::Sprite *createdReciever();


    virtual void onEnterTransitionDidFinish();
    
    void pauseMenuItemCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    void nextLevelMenuItemCallBack(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);


    CREATE_FUNC(Level);
};