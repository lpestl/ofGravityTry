#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Gravitational Circles");
	ofSetFrameRate(60);

	auto blueCircle = ofPhysicalCircle();
	auto whiteCircle = ofPhysicalCircle();
	auto redCircle = ofPhysicalCircle();

	// Large blue circle with high mass
	blueCircle.setup(
		ofGetWindowWidth() / 2,
		ofGetWindowHeight() / 2,
		50,
		ofColor::blue,
		ofVec2f(0.f, 0.f),  // Start with no initial speed
		ofVec2f(0.f, 0.0f), // Start with no acceleration
		5000.0f              // High mass
	);

	// Medium white circle with medium mass
	whiteCircle.setup(
		ofGetWindowWidth() / 4 * 3,
		ofGetWindowHeight() / 2,
		25,
		ofColor::white,
		ofVec2f(0.f, 80.f),  // Initial orbital speed
		ofVec2f(0.f, 0.f),
		10.0f
	);
	
	// Small red circle with low mass
	redCircle.setup(
		ofGetWindowWidth() / 4,
		ofGetWindowHeight() / 2,
		15,
		ofColor::red,
		ofVec2f(0.f, -60.f), // Initial orbital speed in opposite direction
		ofVec2f(0.f, 0.f),
		50.0f
	);
	
	_physicalSpace.setup();
	_physicalSpace.addObject(blueCircle);
	_physicalSpace.addObject(whiteCircle);
	_physicalSpace.addObject(redCircle);
}

//--------------------------------------------------------------
void ofApp::update(){
	_physicalSpace.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	_physicalSpace.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
