#pragma once

#include "ofMovingCircle.h"

class ofPhysicalCircle : public ofMovingCircle
{
public:
    virtual void setup(float x, float y, float radius, const ofColor& color, const ofVec2f& speed, const ofVec2f& acceleration);
    virtual void setup() override;
    virtual void update() override;
    virtual void draw() override;
    
private:
    float _mass { 1.0f };
    
};
