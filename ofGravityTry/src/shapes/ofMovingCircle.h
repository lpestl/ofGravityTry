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

    ofVec2f getSpeed() const;
    ofVec2f getAcceleration() const;

	bool isDebug() const;
	void setDebug(bool debug);

protected:
	void setSpeed(ofVec2f speed);
	void setAcceleration(ofVec2f acceleration);
	
private:
	ofVec2f _speed {};
	ofVec2f _acceleration {};

	bool _debug { true };
};
