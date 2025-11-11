#pragma once

#include "circle.h"

class ofGradientCircle : public circle {
public:
	virtual ~ofGradientCircle() override;

	virtual void setup(float x, float y, float radius, const ofColor& color);
	virtual void setup(float x, float y, float radius) override;
	virtual void setup(const ofColor& color);
	virtual void setup() override;
    virtual void update() override;
    virtual void draw() override;

	void setColor(const ofColor& color);
    ofColor getColor() const;

private:
	void createCircleMesh();

private:
	ofColor _color {ofColor(0, 0, 255, 255)};

	ofMesh _circleMesh {};
	ofShader _gradientShader {};
};
