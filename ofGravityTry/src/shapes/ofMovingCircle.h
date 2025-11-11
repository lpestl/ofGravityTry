#pragma once

#include "ofGradientCircle.h"

class ofMovingCircle : public ofGradientCircle {
public:
	ofMovingCircle();
	ofMovingCircle(float x, float y, float radius, const ofColor& color);
	virtual ~ofMovingCircle();

	void setup();
    void update();
    void draw();

	void setSpeed(ofVec2f speed);
    ofVec2f getSpeed() const;

	void setAcceleration(ofVec2f acceleration);
    ofVec2f getAcceleration() const;

private:
	ofVec2f _speed;
	ofVec2f _acceleration;
};
