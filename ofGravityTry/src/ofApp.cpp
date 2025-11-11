#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Circles");
	ofSetFrameRate(60);

	circles.push_back(ofGradientCircle(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 100, ofColor::blue));
	circles.push_back(ofGradientCircle(ofGetWindowWidth() / 4, ofGetWindowHeight() / 4, 50, ofColor::white));
	circles.push_back(ofGradientCircle(ofGetWindowWidth() / 2 + ofGetWindowWidth() / 4, ofGetWindowHeight() / 2 + ofGetWindowHeight() / 4, 30, ofColor::red));

	circles[0].setup(true);
	circles[1].setup(true);
	circles[2].setup(true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::black);

	for (auto circle : circles) {
		circle.draw();
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
