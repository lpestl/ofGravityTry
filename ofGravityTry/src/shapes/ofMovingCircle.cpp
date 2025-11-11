#include "ofMovingCircle.h"

ofMovingCircle::~ofMovingCircle()
{
}

void ofMovingCircle::setup(float x, float y, float radius, const ofColor& color, const ofVec2f& speed,
	const ofVec2f& acceleration)
{
	ofGradientCircle::setup(x, y, radius, color);
	_speed = speed;
	_acceleration = acceleration;
}

void ofMovingCircle::setup(const ofVec2f& speed, const ofVec2f& acceleration)
{
	ofGradientCircle::setup();
	_speed = speed;
	_acceleration = acceleration;
}

void ofMovingCircle::setup() {
	ofGradientCircle::setup();
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
