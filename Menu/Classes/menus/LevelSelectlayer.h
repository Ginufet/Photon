#pragma once

#include "PhotonGame.h"

class LevelSelect : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void onEnterTransitionDidFinish();
   
    CREATE_FUNC(LevelSelect);
};

