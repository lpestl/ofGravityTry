#pragma once

#include "ofMain.h"

class circle
{
public:
    circle();
    circle(float x, float y, float radius);
    virtual ~circle();
    
    virtual void setup(float x, float y, float radius);
    virtual void update();
    virtual void draw();

    void setRadius(float radius);
    float getRadius() const;

    void setPosition(float x, float y);
    ofVec2f getPosition() const;

private:
    ofVec2f _position;
    float _radius;    
};
