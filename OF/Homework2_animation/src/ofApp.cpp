#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(50);
	ofSetCircleResolution(50);
	skeleton.setup();

	for(int i= 0; i < NUMMarbles; i++){
		marbles[i].setup();

}

//--------------------------------------------------------------
void ofApp::update(){
	for(int i= 0; i < NUMMarbles; i++){
		marbles[i].move();

}

//--------------------------------------------------------------
void ofApp::draw(){
	skeleton.display();
	for(int i= 0; i < NUMMarbles; i=i+1){
	marbles[i].display();
}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){ 
	skeleton.reset(mouseX, mouseY);
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	skeleton.mouthY = 20;
	

	for(int i=0; i < NUMMarbles; i++){
	marbles[i].make(mouseX, mouseY);
}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	skeleton.mouthY = 0;
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