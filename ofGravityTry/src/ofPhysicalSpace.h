#pragma once
#include <vector>

#include "ofPhysicalCircle.h"
#include "ofVec2f.h"

class ofPhysicalSpace
{
public:
    virtual void setup();
    virtual void update();
    virtual void draw();

    void addObject(const ofPhysicalCircle& object);
    
private:
    std::vector<ofPhysicalCircle> _objects;
};
