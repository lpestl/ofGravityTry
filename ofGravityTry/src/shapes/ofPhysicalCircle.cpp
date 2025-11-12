#include "ofPhysicalCircle.h"

void ofPhysicalCircle::setup(float x, float y, float radius, const ofColor& color, const ofVec2f& speed,
    const ofVec2f& acceleration)
{
    ofMovingCircle::setup(x, y, radius, color, speed, acceleration);
}

void ofPhysicalCircle::setup(float x, float y, float radius, const ofColor& color, const ofVec2f& speed,
    const ofVec2f& acceleration, float mass)
{
    ofMovingCircle::setup(x, y, radius, color, speed, acceleration);
    _mass = mass;
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

float ofPhysicalCircle::getMass() const
{
    return _mass;
}

void ofPhysicalCircle::setMass(float mass)
{
    _mass = mass;
}

void ofPhysicalCircle::applyForce(const ofVec2f& force)
{
    // F = ma, so a = F/m
    ofVec2f acceleration = force / _mass;
    setAcceleration(getAcceleration() + acceleration);
}
