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

private:
    ofVec2f _direction { 0.f, 50.f};
};
