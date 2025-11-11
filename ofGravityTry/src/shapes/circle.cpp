#include "circle.h"

circle::circle()
    : _position(ofVec2f(0, 0))
    , _radius(100.f)
{
}

//--------------------------------------------------------------
circle::circle(float x, float y, float radius)
    : _position(ofVec2f(x, y))
    , _radius(radius)
{
}

//--------------------------------------------------------------
circle::~circle()
{
}

//--------------------------------------------------------------
void circle::setup(float x, float y, float radius)
{
    _position = ofVec2f(x, y);
    _radius = radius;
}

//--------------------------------------------------------------
void circle::update()
{
    
}

//--------------------------------------------------------------
void circle::draw()
{
    ofDrawCircle(_position, _radius);
}

//--------------------------------------------------------------
void circle::setRadius(float radius)
{
    _radius = radius;
}

//--------------------------------------------------------------
float circle::getRadius() const
{
    return _radius;
}

//--------------------------------------------------------------
void circle::setPosition(float x, float y)
{
    _position = ofVec2f(x, y);
}

//--------------------------------------------------------------
ofVec2f circle::getPosition() const
{
    return _position;
}


