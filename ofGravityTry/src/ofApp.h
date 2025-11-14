#pragma once

#include "circle.h"
#include "ofMain.h"
#include "ofPhysicalSpace.h"
#include "shapes/ofGradientCircle.h"
#include "shapes/ofMovingCircle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:
		ofPhysicalSpace _physicalSpace;
	
		ofCamera _camera;
		bool _bCameraMoving { false };
		ofVec2f _lastMousePos;
		ofVec2f _cameraOffset;
};
