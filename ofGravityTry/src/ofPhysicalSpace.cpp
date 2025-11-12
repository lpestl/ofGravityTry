#include "ofPhysicalSpace.h"

void ofPhysicalSpace::setup()
{
}

void ofPhysicalSpace::update()
{
    for (auto& object : _objects) {
        object.update();
    }
}

void ofPhysicalSpace::draw()
{
    ofBackground(ofColor::black);

    for (auto& object : _objects) {
        object.draw();
    }
}

void ofPhysicalSpace::addObject(const ofPhysicalCircle& object)
{
    _objects.push_back(object);
}
