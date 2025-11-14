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

    ofSetColor(255);
    ofDrawLine(0, 0, ofGetWindowWidth(), 0);
    ofDrawLine(ofGetWindowWidth(), 0, ofGetWindowWidth(), ofGetWindowHeight());
    ofDrawLine(ofGetWindowWidth(), ofGetWindowHeight(), 0, ofGetWindowHeight());
    ofDrawLine(0, ofGetWindowHeight(), 0, 0);
    
    // Draw trajectories first (behind the circles)
    drawTrajectories();

    // Draw the circles on top
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

void ofPhysicalSpace::drawTrajectories()
{
    const int predictionSteps = 500; // Predict 100 frames ahead
    const float timeStep = 1.0f / 60.0f; // Assume 60 FPS
    
    for (const auto& object : _objects) {
        if (object.isDebug())
        {
            std::vector<ofVec2f> trajectory = predictTrajectory(object, predictionSteps);
        
            // Set color based on object color
            ofColor trajectoryColor = object.getColor();
            trajectoryColor.a = 100; // Semi-transparent
            ofSetColor(trajectoryColor);
        
            // Draw trajectory lines
            ofSetLineWidth(2);
            for (size_t i = 0; i < trajectory.size() - 1; ++i) {
                ofDrawLine(trajectory[i], trajectory[i + 1]);
            }
        
            // Draw prediction points
            ofSetColor(trajectoryColor);
            for (size_t i = 0; i < trajectory.size(); i += 5) { // Draw every 5th point
                ofDrawCircle(trajectory[i], 2);
            }
        }
    }
}

std::vector<ofVec2f> ofPhysicalSpace::predictTrajectory(const ofPhysicalCircle& object, int steps) const
{
    std::vector<ofVec2f> trajectory;
    trajectory.reserve(steps + 1);
    
    // Start with current position
    trajectory.push_back(object.getPosition());
    
    // Create a copy of the object for simulation
    ofPhysicalCircle simulatedObject = object;
    
    // Simulate future positions
    for (int i = 0; i < steps; ++i) {
        // Reset acceleration
        simulatedObject.setAcceleration(ofVec2f(0.0f, 0.0f));
        
        // Calculate gravitational forces from all other objects
        for (const auto& otherObject : _objects) {
            if (&object != &otherObject) {
                ofVec2f force = calculateGravitationalForce(simulatedObject, otherObject);
                simulatedObject.applyForce(force);
            }
        }
        
        // Update position and speed using Euler integration
        ofVec2f acceleration = simulatedObject.getAcceleration();
        ofVec2f speed = simulatedObject.getSpeed();
        
        // Update speed: v = v0 + a * dt
        speed += acceleration * ofGetLastFrameTime();
        simulatedObject.setSpeed(speed);
        
        // Update position: p = p0 + v * dt
        ofVec2f position = simulatedObject.getPosition();
        position += speed * ofGetLastFrameTime();
        simulatedObject.setPosition(position);
        
        // Add to trajectory
        trajectory.push_back(position);
    }
    
    return trajectory;
}
