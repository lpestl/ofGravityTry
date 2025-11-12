#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Circles");
	ofSetFrameRate(60);

	auto blueCircle = ofPhysicalCircle();
	auto whiteCircle = ofPhysicalCircle();

	blueCircle.setup(
		ofGetWindowWidth() / 2,
		ofGetWindowHeight() / 2,
		50,
		ofColor::blue,
		ofVec2f(50.f, 10.f),
		ofVec2f(50.f, 0.0f)
	);

	whiteCircle.setup(
		ofGetWindowWidth() / 4 * 3,
		ofGetWindowHeight() / 2,
		25,
		ofColor::white,
		ofVec2f(10.f, 50.f),
		ofVec2f(0.f, 50.f)
	);
	
	_physicalSpace.setup();
	_physicalSpace.addObject(blueCircle);
	_physicalSpace.addObject(whiteCircle);
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
