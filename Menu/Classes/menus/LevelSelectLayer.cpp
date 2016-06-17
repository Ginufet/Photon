#include "menus\LevelSelectlayer.h"
#include <vector>
#include <string>
//#include "Level.h"

USING_NS_CC;
USING_NS_CC_DEN;

Scene *LevelSelect::createScene() {
    auto scene = Scene::create();
    auto layer = LevelSelect::create();
    scene->addChild(layer);

    return scene;
}

bool LevelSelect::init() {
    if (!Layer::init()) {
        log("false");
        return false;
    }
    

    auto rootNode = CSLoader::createNode("csbs/LevelSelect.csb");
    rootNode->setPosition(Vec2::ZERO);
    this->addChild(rootNode);

    std::string levelPrefix = "Level";
    std::vector<std::string> levelNames(15);
    std::vector<ui::Button *> levels(15);

    for (int i = 0; i < 15; i++) {
        if (i < 9) {
            levelPrefix.push_back(i + '1');
        }
        else if (i == 9) {
            levelPrefix += "10";
        }
        else {
            levelPrefix.push_back(i - 9 + '0');
        }
        levelNames[i] = levelPrefix;
        levelPrefix.pop_back();

        levels[i] = dynamic_cast<ui::Button *>(rootNode->getChildByName(levelNames[i]));
        levels[i]->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type) {
            if (type == ui::Widget::TouchEventType::ENDED) {
                //auto scr = Level::createScene();
                //auto reScr = TransitionProgressInOut::create(0.6f, scr);
                //Director::getInstance()->pushScene(reScr);
                if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
                    SimpleAudioEngine::getInstance()->playEffect(FILE_SOUND_1);
                }
            }
        });
    }
    
    auto mainMenuButton = dynamic_cast<ui::Button *>(rootNode->getChildByName("MainMenuButton"));
    mainMenuButton->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED) {
            //auto scr = Level::createScene();
            //auto reScr = TransitionProgressInOut::create(0.6f, scr);
            Director::getInstance()->popToRootScene();
            if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
                SimpleAudioEngine::getInstance()->playEffect(FILE_SOUND_1);
            }
        }
    });


    return true;
}


void LevelSelect::onEnterTransitionDidFinish() {
    Layer::onEnterTransitionDidFinish();
    if (UserDefault::getInstance()->getBoolForKey(MUSIC_KEY)) {
        SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    }
}

//void LevelSelect::levelSelectMenuItemCallback(Ref *pSender, ui::Widget::TouchEventType type) {
//    auto item = (MenuItem *)pSender;
//    log("Touch Level%d ", item->getZOrder());
//    //To be continue...
//}

