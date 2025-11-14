#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Snakes");
	ofSetFrameRate(60);

	_camera.disableOrtho();
	_camera.enableOrtho();
    
	_camera.setPosition(0, 0, 500);
    
	_bCameraMoving = false;
	_cameraOffset.set(0, 0);

	_level.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	_camera.setPosition(_cameraOffset.x, _cameraOffset.y, 500);

	_level.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	_camera.begin();

	_level.draw();

	_camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'r') {
		_cameraOffset.set(0, 0);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == OF_KEY_SPACE)
	{
		
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (_bCameraMoving) {
		ofVec2f mouseDiff = ofVec2f(x, y) - _lastMousePos;
        
		_cameraOffset.x -= mouseDiff.x;
		_cameraOffset.y += mouseDiff.y;
        
		_lastMousePos.set(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_LEFT) {
		_bCameraMoving = true;
		_lastMousePos.set(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_LEFT) {
		_bCameraMoving = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	_camera.setAspectRatio((float)w / (float)h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
