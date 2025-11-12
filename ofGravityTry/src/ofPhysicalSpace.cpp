#include "ofPhysicalSpace.h"
#include <cmath>

void ofPhysicalSpace::setup()
{
}

void ofPhysicalSpace::update()
{
    // Reset accelerations for all objects
    for (auto& object : _objects) {
        object.setAcceleration(ofVec2f(0.0f, 0.0f));
    }
    
    // Calculate gravitational forces between all pairs of objects
    for (size_t i = 0; i < _objects.size(); ++i) {
        for (size_t j = i + 1; j < _objects.size(); ++j) {
            ofVec2f force = calculateGravitationalForce(_objects[i], _objects[j]);
            
            // Apply equal and opposite forces (Newton's third law)
            _objects[i].applyForce(force);
            _objects[j].applyForce(-force);
        }
    }
    
    // Update all objects
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

ofVec2f ofPhysicalSpace::calculateGravitationalForce(const ofPhysicalCircle& obj1, const ofPhysicalCircle& obj2) const
{
    // Law of universal gravitation: F = G * (m1 * m2) / r^2
    ofVec2f direction = obj2.getPosition() - obj1.getPosition();
    float distance = direction.length();
    
    // Avoid division by zero and very small distances
    if (distance < 1.0f) {
        distance = 1.0f;
    }
    
    // Calculate force magnitude
    float forceMagnitude = _gravitationalConstant * (obj1.getMass() * obj2.getMass()) / (distance * distance);
    
    // Normalize direction and scale by force magnitude
    direction.normalize();
    return direction * forceMagnitude;
}
