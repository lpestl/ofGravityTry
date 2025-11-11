#pragma once

#include "ofMain.h"

class circle
{
public:
    virtual ~circle();

    virtual void setup(float x, float y, float radius);
    virtual void setup();
    virtual void update();
    virtual void draw();

    void setRadius(float radius);
    float getRadius() const;

    void setPosition(ofVec2f position);
    void setPosition(float x, float y);
    ofVec2f getPosition() const;

private:
    ofVec2f _position {};
    float _radius { 100.f };
};
