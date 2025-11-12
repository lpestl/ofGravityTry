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
		100,
		ofColor::blue,
		ofVec2f(0.f, 0.f),  // Start with no initial speed
		ofVec2f(0.f, 0.0f), // Start with no acceleration
		5000.0f              // High mass
	);

	// Medium white circle with medium mass
	whiteCircle.setup(
		ofGetWindowWidth() / 2 + ofGetWindowHeight() / 6,
		ofGetWindowHeight() / 2,
		10,
		ofColor::white,
		ofVec2f(0.f, 150.f),  // Initial orbital speed
		ofVec2f(0.f, 0.f),
		10.0f
	);
	
	// Small red circle with low mass
	redCircle.setup(
		ofGetWindowWidth() / 2 - ofGetWindowHeight() / 6 * 2,
		ofGetWindowHeight() / 2,
		25,
		ofColor::red,
		ofVec2f(0.f, -100.f), // Initial orbital speed in opposite direction
		ofVec2f(0.f, 0.f),
		25.0f
	);
	
	_physicalSpace.setup();
	_physicalSpace.addObject(blueCircle);
	_physicalSpace.addObject(whiteCircle);
	_physicalSpace.addObject(redCircle);

	// for (int i = 0; i < 50; ++i)
	// {
	// 	auto circle = ofPhysicalCircle();
	// 	circle.setup(
	// 		ofRandom(ofGetWindowWidth()),
	// 		ofRandom(ofGetWindowHeight()),
	// 		ofRandom(50),
	// 		ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 255),
	// 		ofVec2f(ofRandom(-100, 100), ofRandom(-100, 100)),
	// 		ofVec2f(0.f, 0.f),
	// 		ofRandom(50.f)
	// 	);
	// 	auto weight = ofRandom(20.f);
	// 	if (weight > 1.f)
	// 		circle.setDebug(false);
	// 	_physicalSpace.addObject(circle);
	// }
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
