#include "ofDirectionCircle.h"

ofDirectionCircle::~ofDirectionCircle()
{
}

void ofDirectionCircle::setup(float x, float y, float radius, const ofColor& color)
{
    ofGradientCircle::setup(x, y, radius, color);
    _direction = ofVec2f(0.f, radius * 2);
}

void ofDirectionCircle::setup()
{
    ofMovingCircle::setup();
}

void ofDirectionCircle::update()
{
    ofMovingCircle::update();
}

void ofDirectionCircle::draw()
{
    ofMovingCircle::draw();
    if (isDebug())
    {
        ofPushMatrix();

        ofSetColor(ofColor::green);
		ofTranslate(getPosition());
        //ofRotateRad(_direction.angleRad(ofVec2f(0.f, 1.f)));
        ofDrawLine(0, 0, _direction.x, _direction.y);

        ofPopMatrix();
    }
}

void ofDirectionCircle::rotate(double deg)
{
    _direction.rotate(deg);
}
