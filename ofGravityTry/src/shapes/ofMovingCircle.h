#pragma once

#include "ofGradientCircle.h"

class ofMovingCircle : public ofGradientCircle {
public:
	virtual ~ofMovingCircle() override;

	virtual void setup(float x, float y, float radius, const ofColor& color, const ofVec2f& speed, const ofVec2f& acceleration);
	virtual void setup(const ofVec2f& speed, const ofVec2f& acceleration);
	virtual void setup() override;
    virtual void update() override;
    virtual void draw() override;

	void setSpeed(ofVec2f speed);
    ofVec2f getSpeed() const;

	void setAcceleration(ofVec2f acceleration);
    ofVec2f getAcceleration() const;

private:
	ofVec2f _speed {};
	ofVec2f _acceleration {};
};
