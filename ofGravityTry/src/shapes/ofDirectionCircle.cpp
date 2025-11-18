#include "ofDirectionCircle.h"
#include <algorithm>

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
    
    // Update angular velocity based on acceleration
    _angularVelocity += _angularAcceleration;
    
    // Apply deceleration when no acceleration is applied
    if (_angularAcceleration == 0.0) {
        if (_angularVelocity > 0) {
            _angularVelocity = std::max(0.0, _angularVelocity - _decelerationRate);
        } else if (_angularVelocity < 0) {
            _angularVelocity = std::min(0.0, _angularVelocity + _decelerationRate);
        }
    }
    
    // Clamp angular velocity to maximum
    if (_angularVelocity > _maxAngularVelocity) {
        _angularVelocity = _maxAngularVelocity;
    } else if (_angularVelocity < -_maxAngularVelocity) {
        _angularVelocity = -_maxAngularVelocity;
    }
    
    // Apply rotation based on angular velocity
    if (_angularVelocity != 0.0) {
        rotate(_angularVelocity);
    }
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

// Angular physics methods implementation
void ofDirectionCircle::setAngularAcceleration(double acceleration)
{
    _angularAcceleration = acceleration;
}

void ofDirectionCircle::setMaxAngularVelocity(double maxVelocity)
{
    _maxAngularVelocity = maxVelocity;
}

double ofDirectionCircle::getAngularVelocity() const
{
    return _angularVelocity;
}

void ofDirectionCircle::resetAngularPhysics()
{
    _angularVelocity = 0.0;
    _angularAcceleration = 0.0;
}
