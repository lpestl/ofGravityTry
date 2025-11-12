#include "ofPhysicalCircle.h"

void ofPhysicalCircle::setup(float x, float y, float radius, const ofColor& color, const ofVec2f& speed,
    const ofVec2f& acceleration)
{
    ofMovingCircle::setup(x, y, radius, color, speed, acceleration);
}

void ofPhysicalCircle::setup()
{
    ofMovingCircle::setup();
}

void ofPhysicalCircle::update()
{
    ofMovingCircle::update();
}

void ofPhysicalCircle::draw()
{
    ofMovingCircle::draw();
}
