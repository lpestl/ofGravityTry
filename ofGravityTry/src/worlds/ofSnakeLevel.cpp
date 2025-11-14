#include "ofSnakeLevel.h"

#include "ofGraphics.h"

void ofSnakeLevel::setup()
{
    _circle.setup(0, 0, 50, ofColor::brown);
}

void ofSnakeLevel::update()
{
    _circle.update();
}

void ofSnakeLevel::draw()
{
    ofBackground(ofColor::black);

    _circle.draw();
}
