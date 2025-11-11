#pragma once

#include "ofMain.h"

class ofGradientCircle {
public:
	ofGradientCircle();
	ofGradientCircle(float x, float y, float radius, const ofColor& color);

	void setup(bool useShader);
    void update();
    void draw();

	void setRadius(float radius);
    float getRadius() const;

	void setPosition(float x, float y);
    ofVec2f getPosition() const;

	void setColor(const ofColor& color);
    ofColor getColor() const;

private:
	void createGradientTexture();
	void createCircleMesh();

private:
	float _posX, _posY;
	float _radius;
	ofColor _color;

	ofTexture _gradientTexture;
	ofMesh _circleMesh;
	ofShader _gradientShader;

	bool _useShader;
};
