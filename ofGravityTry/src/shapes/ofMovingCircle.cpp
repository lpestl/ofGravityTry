#include "ofMovingCircle.h"

ofMovingCircle::ofMovingCircle()
	: ofGradientCircle(0.0f, 0.0f, 100.0f, ofColor(255, 0, 0, 255))
	, _speed(ofVec2f(0.0f, 0.0f))
	, _acceleration(ofVec2f(0.0f, 0.0f))
{
}

ofMovingCircle::ofMovingCircle(float x, float y, float radius, const ofColor & color)
	: ofGradientCircle(x, y, radius, color)
	, _speed(ofVec2f(0.0f, 0.0f))
	, _acceleration(ofVec2f(0.0f, 0.0f))
{
}

ofMovingCircle::~ofMovingCircle()
{
}

void ofMovingCircle::setup() {
	ofGradientCircle::setup(true);
}

void ofMovingCircle::update() {
	// Update speed based on acceleration
	_speed += _acceleration;

	// Update position based on speed
	setPosition(getPosition() + _speed);

	// Check if we've reached the bottom of the window
	ofVec2f pos = getPosition();
	if (pos.y > ofGetWindowHeight() - getRadius()) {
		// Reverse the vertical speed when we hit the bottom
		_speed.y = -_speed.y;
		// Stop horizontal movement
		_speed.x = 0;
		// Set position to the bottom
		setPosition(pos.x, ofGetWindowHeight() - getRadius());
	}
}

void ofMovingCircle::draw() {
	ofGradientCircle::draw();
}

void ofMovingCircle::setSpeed(ofVec2f speed) {
    _speed = speed;
}

ofVec2f ofMovingCircle::getSpeed() const {
    return _speed;
}

void ofMovingCircle::setAcceleration(ofVec2f acceleration) {
    _acceleration = acceleration;
}

ofVec2f ofMovingCircle::getAcceleration() const {
    return _acceleration;
}
