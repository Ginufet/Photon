#include "Photon.h"

USING_NS_CC;

void Photon::setVelocity(Vec2 v) {
	velocity = v;
	return;
}

Vec2 Photon::getVelocity() {
	return velocity;
}

bool Photon::init() {
	if (!Sprite::init()) {
		return false;
	}
	initWithFile("photon.png");

	return true;
}
