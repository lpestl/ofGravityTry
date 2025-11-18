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
    // Handle linear movement
    if (_isAccelerating) {
        // Apply forward acceleration in the direction the circle is facing
        ofVec2f accelerationVector = _direction.getNormalized() * _forwardAcceleration;
        setAcceleration(accelerationVector);
    } else if (_decelerationAcceleration != 0.0) {
        // Apply deceleration in the opposite direction of movement
        ofVec2f currentSpeed = getSpeed();
        if (currentSpeed.length() > 0) {
            ofVec2f decelerationVector = -currentSpeed.getNormalized() * _decelerationAcceleration;
            setAcceleration(decelerationVector);
            
            // Stop deceleration when speed is very low
            if (currentSpeed.length() < 5.0) {
                setSpeed(ofVec2f(0, 0));
                setAcceleration(ofVec2f(0, 0));
                _decelerationAcceleration = 0.0;
            }
        }
    }
    
    // Apply maximum speed limit
    ofVec2f currentSpeed = getSpeed();
    if (currentSpeed.length() > _maxSpeed) {
        setSpeed(currentSpeed.getNormalized() * _maxSpeed);
    }
    
    // Call parent update for basic physics
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

// Linear movement methods implementation
void ofDirectionCircle::accelerateInDirection(float acceleration)
{
    _isAccelerating = true;
    _forwardAcceleration = acceleration;
    _decelerationAcceleration = 0.0;
}

void ofDirectionCircle::setMaxSpeed(float maxSpeed)
{
    _maxSpeed = maxSpeed;
}

void ofDirectionCircle::stopMovement()
{
    _isAccelerating = false;
    _forwardAcceleration = 0.0;
    
    // Set deceleration to smoothly stop
    ofVec2f currentSpeed = getSpeed();
    if (currentSpeed.length() > 0) {
        _decelerationAcceleration = 50.0; // deceleration strength
    } else {
        setAcceleration(ofVec2f(0, 0));
        _decelerationAcceleration = 0.0;
    }
}
