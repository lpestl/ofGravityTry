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

void ofSnakeLevel::keyPressed(int key)
{
    switch (key)
    {
        case OF_KEY_LEFT:
            _circle.setAngularAcceleration(0.2); // Positive acceleration for left rotation
            break;
        case OF_KEY_RIGHT:
            _circle.setAngularAcceleration(-0.2); // Negative acceleration for right rotation
            break;
        case OF_KEY_UP:
            _circle.accelerateInDirection(500.0); // Forward acceleration
            break;
        case OF_KEY_DOWN:
            // Optional: Add reverse movement if needed
            break;
        default:
            break;
    }
}

void ofSnakeLevel::keyReleased(int key)
{
    switch (key)
    {
        case OF_KEY_LEFT:
        case OF_KEY_RIGHT:
            // Set negative acceleration to smoothly stop rotation
            _circle.setAngularAcceleration(0.0);
            break;
        case OF_KEY_UP:
            _circle.stopMovement(); // Smoothly stop forward movement
            break;
        default:
            break;
    }
}

void ofSnakeLevel::mouseMoved(int x, int y)
{
}

void ofSnakeLevel::mouseDragged(int x, int y, int button)
{
}

void ofSnakeLevel::mousePressed(int x, int y, int button)
{
}

void ofSnakeLevel::mouseReleased(int x, int y, int button)
{
}

void ofSnakeLevel::mouseEntered(int x, int y)
{
}

void ofSnakeLevel::mouseExited(int x, int y)
{
}
