#pragma once

#include "circle.h"

class ofGradientCircle : public circle {
public:
	ofGradientCircle();
	ofGradientCircle(float x, float y, float radius, const ofColor& color);
	virtual ~ofGradientCircle();

	void setup(bool useShader);
    void update();
    void draw();

	void setColor(const ofColor& color);
    ofColor getColor() const;

private:
	void createGradientTexture();
	void createCircleMesh();

private:
	ofColor _color;

	ofTexture _gradientTexture;
	ofMesh _circleMesh;
	ofShader _gradientShader;

	bool _useShader;
};
