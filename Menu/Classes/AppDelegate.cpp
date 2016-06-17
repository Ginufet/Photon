#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;
USING_NS_CC_DEN;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() {
}

void AppDelegate::initGLContextAttrs() {
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

void AppDelegate::initSoundAndMusic() {
    //initialize bgm
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(FILE_BGM);
    UserDefault::getInstance()->setBoolForKey(MUSIC_KEY, true);
    UserDefault::getInstance()->setBoolForKey(MUSIC_PLAYED_KEY, false);

    log("Background Music Preloaded");

    //initialize effect
    SimpleAudioEngine::getInstance()->preloadEffect(FILE_SOUND_1);
    UserDefault::getInstance()->setBoolForKey(SOUND_KEY, true);

    log("Effect Sound Preloaded");
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

    if (!glview) {
        glview = GLViewImpl::createWithRect("LearningCocos", Rect(0, 0, WINDOW_SIZE));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(WINDOW_SIZE, ResolutionPolicy::SHOW_ALL);

    director->setDisplayStats(true);

    director->setAnimationInterval(1.0 / 60);

    FileUtils::getInstance()->addSearchPath("res");

    this->initSoundAndMusic();

    auto scene = HelloWorld::createScene();

    director->runWithScene(scene);

    log("applicationDidFinishLaunching");

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    log("applicationDidEnterBackground");

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    log("applicationWillEnterForeground");

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

