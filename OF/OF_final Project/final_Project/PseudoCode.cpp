#include "ofApp.h"
// declare static verticies points (this is takend fromt the examples
static int pts[] = {257,219,257,258,259,274,263,325,266,345,266,352,269,369,276,387,286,415,291,425,302,451,308,462,316,472,321,480,328,488,333,495,339,501,345,505,350,507,365,515,370,519,377,522,382,525,388,527,405,534,426,538,439,539,452,539,468,540,485,540,496,541,607,541,618,539,625,537,641,530,666,513,682,500,710,476,723,463,727,457,729,453,732,450,734,447,738,440,746,423,756,404,772,363,779,343,781,339,784,327,789,301,792,278,794,267,794,257,795,250,795,232,796,222,796,197,797,195,797,188,796,188};
static int nPts  = 61*2;

//--------------------------------------------------------------

void ofApp::setup(){
	// In the setup I will load the sound I will use that I placed in the bin folder of my project. 
	// load in sounds: OW
	
		
// I will set the background color and the force/ popularity function to off (you aren't just popular from the get go) 
	

	// register the listener so that we get the events
	
	// This adds the start shape ( this is the default for the examples from box2d)

	
	// make the shape
	edgeLine.setPhysics(0.0, 0.5, 0.5);
	edgeLine.create(box2d.getWorld());
	

}

//--------------------------------------------------------------
// Then I will outline the contact function that will affect my friends when they bump into each other
void ofApp::contactStart(ofxBox2dContactArgs &e) {
	
		
		// Friends don't mind bumping into the ground so they won't make noise then
		
			// friends only say how when they are hit by others 
			
	}
}

//--------------------------------------------------------------
// Then create the reset function for when Friends aren't touching
void ofApp::contactEnd(ofxBox2dContactArgs &e) {

}



//--------------------------------------------------------------
// In the update function we will describe what happens when you become popular. ( everything changes)
void ofApp::update(){
	
	
	
	// gravity will change when you are popular
	
	// But only for your friends... they will be drawn to you. 
		// set how the change in gravity affects them
	}

	// remove shapes that are offscreen


}

//--------------------------------------------------------------
void ofApp::draw(){
	// what do the circles you draw look like ? 
	
	// what do the boxed you draw look like ? 
	
	// what do your friends look like and what do they sound like? 

		// add the eventlistner qualifyer for the mouth
		

	}
	// display the lines that you have drawn
	
	
	// make some instructions for the screen
	string info = "";

}

//--------------------------------------------------------------
// Decide which keys will make things appear
void ofApp::keyPressed(int key){
	// press c to make circles 
	
	// press b to make boxes 

	// press z to make friends

        // a random radius 4px - 20px
	
	
	// press f to be popular	
	
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
// when you drag the mouse whil the button is pressed you will draw a line 
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
// Whne you press the mouse it will start drawing the line
void ofApp::mousePressed(int x, int y, int button) {


//--------------------------------------------------------------
// when you release the mouse it will stop darwind and simplify the vertices
void ofApp::mouseReleased(int x, int y, int button){

	//polyLine.simplifyToMaxVerts(); // this is based on the max box2d verts
	


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
