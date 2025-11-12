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
	_speed += _acceleration * ofGetLastFrameTime();

	// Update position based on speed
	setPosition(getPosition() + _speed * ofGetLastFrameTime());

	auto bottomBound = ofGetWindowHeight() - getRadius();
	auto topBound = 0 + getRadius();
	auto leftBound = 0 + getRadius();
	auto rightBound = ofGetWindowWidth() - getRadius();
	
	// Check if we've reached the bottom of the window
	ofVec2f pos = getPosition();
	if (pos.y > bottomBound) {
		// Reverse the vertical speed when we hit the bottom
		_speed.y = -_speed.y / 2.f;		
		// Set position to the bottom
		setPosition(pos.x, bottomBound);
	}
	if (pos.y < topBound)
	{
		_speed.y = -_speed.y / 2.f;
		setPosition(pos.x, topBound);
	}
	if (pos.x > rightBound)
	{
		_speed.x = -_speed.x / 2.f;
		setPosition(rightBound, pos.y);
	}
	if (pos.x < leftBound)
	{
		_speed.x = -_speed.x / 2.f;
		setPosition(leftBound, pos.y);
	}
}

void ofMovingCircle::draw() {
	ofGradientCircle::draw();

	if (_debug)
	{
		// draw speed vector
		ofSetColor(ofColor::red);
		ofPushMatrix();
		ofTranslate(getPosition());
		ofRotateRad(-getSpeed().angleRad(ofVec2f(0.0f, 1.0f)));
		ofDrawLine(ofVec2f(0,0), ofVec2f(0, getSpeed().length()));
		ofDrawLine(ofVec2f(6, getSpeed().length()-10), ofVec2f(0, getSpeed().length()));
		ofDrawLine(ofVec2f(-6, getSpeed().length()-10), ofVec2f(0, getSpeed().length()));
		ofDrawBitmapString(getSpeed().length(), 10.f, getSpeed().length() / 2);
		ofPopMatrix();

		// draw acceleration vector
		ofSetColor(ofColor::yellow);
		ofPushMatrix();
		ofTranslate(getPosition());
		ofRotateRad(-getAcceleration().angleRad(ofVec2f(0.0f, 1.0f)));
		ofDrawLine(ofVec2f(0,0), ofVec2f(0, getAcceleration().length()));
		ofDrawLine(ofVec2f(6, getAcceleration().length()-10), ofVec2f(0, getAcceleration().length()));
		ofDrawLine(ofVec2f(-6, getAcceleration().length()-10), ofVec2f(0, getAcceleration().length()));
		ofDrawBitmapString(getAcceleration().length(), 10.f, getAcceleration().length() / 2);
		ofPopMatrix();
	}
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

bool ofMovingCircle::isDebug() const
{
	return _debug;
}

void ofMovingCircle::setDebug(bool debug)
{
	_debug = debug;
}
