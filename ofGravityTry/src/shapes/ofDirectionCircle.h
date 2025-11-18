#pragma once
#include "ofMovingCircle.h"

class ofDirectionCircle : public ofMovingCircle
{
public:
    virtual ~ofDirectionCircle() override;

    virtual void setup(float x, float y, float radius, const ofColor& color) override;
    virtual void setup() override;
    virtual void update() override;
    virtual void draw() override;
    
    void rotate(double deg);
    
    // Angular physics methods
    void setAngularAcceleration(double acceleration);
    void setMaxAngularVelocity(double maxVelocity);
    double getAngularVelocity() const;
    void resetAngularPhysics();
    
    // Linear movement methods
    void accelerateInDirection(float acceleration);
    void setMaxSpeed(float maxSpeed);
    void stopMovement();

private:
    ofVec2f _direction { 0.f, 50.f};
    
    // Angular physics properties
    double _angularVelocity { 0.0 };
    double _angularAcceleration { 0.0 };
    double _maxAngularVelocity { 10.0 }; // degrees per frame
    double _decelerationRate { 0.5 }; // deceleration when no acceleration is applied
    
    // Linear movement properties
    float _maxSpeed { 300.0 }; // maximum speed in pixels per second
    bool _isAccelerating { false };
    float _forwardAcceleration { 0.0 };
    float _decelerationAcceleration { 0.0 };
};
