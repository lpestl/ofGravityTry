#pragma once
#include "ofDirectionCircle.h"

class ofSnakeLevel
{
public:    
    void setup();
    void update();
    void draw();

private:
    ofDirectionCircle _circle;
};
