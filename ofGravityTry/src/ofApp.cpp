#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Circles");
	ofSetFrameRate(60);

	circles.push_back(ofMovingCircle());
	/*circles.push_back(ofMovingCircle());
	circles.push_back(ofMovingCircle());*/

	circles[0].setup(
		ofGetWindowWidth() / 2,
		ofGetWindowHeight() / 2,
		100,
		ofColor::blue,
		ofVec2f(2.f, 0.f),
		ofVec2f(0.0f, 2.0f)
	);

	/*circles[1].setup(
		ofGetWindowWidth() / 4,
		ofGetWindowHeight() / 4,
		50,
		ofColor::white,
		ofVec2f(0.f, 0.f),
		ofVec2f(-0.1, 1.5f)
	);
	
	circles[2].setup(
		ofGetWindowWidth() / 2 + ofGetWindowWidth() / 4,
		ofGetWindowHeight() / 2 + ofGetWindowHeight() / 4,
		30, ofColor::red,
		ofVec2f(0, 0),
		ofVec2f(-0.1, -0.5f)
	);*/
}

//--------------------------------------------------------------
void ofApp::update(){
	for (auto& g_circle : circles) {
		g_circle.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::black);

	for (auto& g_circle : circles) {
		g_circle.draw();
	}
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
