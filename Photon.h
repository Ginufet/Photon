#ifndef _PHOTON_H_
#define _PHOTON_H_

#include "cocos2d.h"
#include <vector>

class Photon : public cocos2d::Sprite
{
public:
	virtual bool init();
	void setVelocity(cocos2d::Vec2 v);
	cocos2d::Vec2 getVelocity();
	CREATE_FUNC(Photon);
private:
	cocos2d::Vec2 velocity;
};

#endif // _PHOTON_H_
