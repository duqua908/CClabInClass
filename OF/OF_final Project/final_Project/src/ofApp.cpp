#include "ofApp.h"
// declare static verticies points (this is takend fromt the examples
static int pts[] = {257,219,257,258,259,274,263,325,266,345,266,352,269,369,276,387,286,415,291,425,302,451,308,462,316,472,321,480,328,488,333,495,339,501,345,505,350,507,365,515,370,519,377,522,382,525,388,527,405,534,426,538,439,539,452,539,468,540,485,540,496,541,607,541,618,539,625,537,641,530,666,513,682,500,710,476,723,463,727,457,729,453,732,450,734,447,738,440,746,423,756,404,772,363,779,343,781,339,784,327,789,301,792,278,794,267,794,257,795,250,795,232,796,222,796,197,797,195,797,188,796,188};
static int nPts  = 61*2;

//--------------------------------------------------------------

void ofApp::setup(){
	// In the setup I will load the sound I will use that I placed in the bin folder of my project. 
	// load in sounds:
		ow.loadSound("sounds/ow.mp3");
		ow.setMultiPlay(false);
		ow.setLoop(false);
		
// I will set the background color and the force/ popularity function to off (you aren't just popular from the get go) 
	ofSetVerticalSync(true);
	ofBackgroundHex(0xfdefc2);
	ofSetLogLevel(OF_LOG_NOTICE);
	
	bMouseForce = false;

	box2d.init();
	box2d.enableEvents();   // <-- turn on the event listener
	box2d.setGravity(0, 10);
	box2d.createGround();
	box2d.setFPS(30.0);
	box2d.registerGrabbing();

	// register the listener so that we get the events
	ofAddListener(box2d.contactStartEvents, this, &ofApp::contactStart);
	ofAddListener(box2d.contactEndEvents, this, &ofApp::contactEnd);
	
	// This adds the start shape ( this is the default for the examples from box2d)
	for (int i=0; i<nPts; i+=2) {
		float x = pts[i];
		float y = pts[i+1];
		edgeLine.addVertex(x, y);
	}
	
	// make the shape
	edgeLine.setPhysics(0.0, 0.5, 0.5);
	edgeLine.create(box2d.getWorld());
	

}

//--------------------------------------------------------------
// Then I will outline the contact function that will affect my friends when they bump into each other
void ofApp::contactStart(ofxBox2dContactArgs &e) {
	if(e.a != NULL && e.b != NULL) { 
		
		// Friends don't mind bumping into the ground so they won't make noise then
		if(e.a->GetType() == b2Shape::e_circle && e.b->GetType() == b2Shape::e_circle) {
			
			SoundData * aData = (SoundData*)e.a->GetBody()->GetUserData();
			SoundData * bData = (SoundData*)e.b->GetBody()->GetUserData();
			
			// friends only say how when they are hit by others 
			if(aData) {
				aData->bHit = true;
				ow.play();
		
			}
			
		}
	}
}

//--------------------------------------------------------------
// Then create the reset function for when Friends aren't touching
void ofApp::contactEnd(ofxBox2dContactArgs &e) {
	if(e.a != NULL && e.b != NULL) { 
		
		SoundData * aData = (SoundData*)e.a->GetBody()->GetUserData();
		SoundData * bData = (SoundData*)e.b->GetBody()->GetUserData();
		
		if(aData) {
			aData->bHit = false;
		}
		
		if(bData) {
			bData->bHit = false;
		}
	}
}



//--------------------------------------------------------------
// In the update function we will describe what happens when you become popular. ( everything changes)
void ofApp::update(){
	
	ofSoundUpdate();	

	box2d.update();
	
	// gravity will change when you are popular
	if(bMouseForce) {
		float strength = 8.0f;
		float damping  = 0.7f;
		float minDis   = 100;
	// But only for your friends... they will be drawn to you. 
		for(int i=0; i<friends.size(); i++) {
			friends[i].get()->addAttractionPoint(mouseX, mouseY, strength);
			friends[i].get()->setDamping(damping, damping);
		}
	}

	// remove shapes offscreen
    ofRemove(boxes, ofxBox2dBaseShape::shouldRemoveOffScreen);
    ofRemove(circles, ofxBox2dBaseShape::shouldRemoveOffScreen);
    ofRemove(customParticles, ofxBox2dBaseShape::shouldRemoveOffScreen);

}

//--------------------------------------------------------------
void ofApp::draw(){
	// what do the circles you draw look like ? 
	for(int i=0; i<circles.size(); i++) {
		ofFill();
		ofSetHexColor(0x90d4e3);
		circles[i].get()->draw();
	}
	// what do the boxed you draw look like ? 
	for(int i=0; i<boxes.size(); i++) {
		ofFill();
		ofSetHexColor(0xe63b8b);
		boxes[i].get()->draw();
	}
	// what do your friends look like and what do they sound like? 
	for(int i=0; i<friends.size(); i++) {
		ofFill();
		SoundData * data = (SoundData*)friends[i].get()->getData();
		
		if(data && data->bHit) friends[i].get()->displayMouth();
		else ofSetHexColor(0x4ccae9);
		
		friends[i].get()->draw();
		friends[i].get()->displayEyeWhiteLeft();
		friends[i].get()->displayEyeBlackLeft();
		friends[i].get()->displayEyeWhiteRight();
		friends[i].get()->displayEyeBlackRight();
		

	}
	
	ofNoFill();
	ofSetHexColor(0x444342);
	if(drawing.size()==0) {
        edgeLine.updateShape();
        edgeLine.draw();
    }
	else drawing.draw();
	
	// make some instructions for the screen
	string info = "";
	info += "Press [s] to draw a line strip ["+ofToString(bDrawLines)+"]\n"; 
	info += "Press [f] to become popular ["+ofToString(bMouseForce)+"]\n"; 
	info += "Press [z] to make friends\n";
	info += "Number of Friends: "+ofToString(box2d.getBodyCount())+"\n";
	info += "Total Joints: "+ofToString(box2d.getJointCount())+"\n\n";
	info += "FPS: "+ofToString(ofGetFrameRate())+"\n";
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 30, 30);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// press c to make circles 
	if(key == 'c') {
		float r = ofRandom(4, 20);		// a random radius 4px - 20px
		circles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
		circles.back().get()->setPhysics(3.0, 0.53, 0.1);
		circles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, r);
		
	}
	// press b to make boxes 
	if(key == 'b') {
		float w = ofRandom(4, 20);	
		float h = ofRandom(4, 20);	
		boxes.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
		boxes.back().get()->setPhysics(3.0, 0.53, 0.1);
		boxes.back().get()->setup(box2d.getWorld(), mouseX, mouseY, w, h);
	}
	// press z to make friends
	if(key == 'z') {
        
		friends.push_back(ofPtr<Friends>(new Friends));
       Friends * p = friends.back().get();
		float r = ofRandom(20, 80);		// a random radius 4px - 20px
		p->setPhysics(0.4, 0.53, 0.31);
		p->setup(box2d.getWorld(), mouseX, mouseY, r);
		p->color.r = ofRandom(0, 255);
		p->color.g = ofRandom(0, 255);
		p->color.b = ofRandom(0, 255);

		p-> setData(new SoundData());
    SoundData * sd = (SoundData*)p->getData();
    sd->bHit	= false;
	}	
	// press f to be popular	
	if(key == 'f') bMouseForce = !bMouseForce;
	if(key == 't') ofToggleFullscreen();
	
	
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
	drawing.addVertex(x, y);

}

//--------------------------------------------------------------
// Whne you press the mouse it will start drawing the line
void ofApp::mousePressed(int x, int y, int button) {
	
	if(edgeLine.isBody()) {
		drawing.clear();
		edgeLine.destroy();
	}
	
	drawing.addVertex(x, y);
}

//--------------------------------------------------------------
// when you release the mouse it will stop darwind and simplify the vertices
void ofApp::mouseReleased(int x, int y, int button){

	drawing.setClosed(false);
	drawing.simplify();
	
	edgeLine.addVertexes(drawing);
	//polyLine.simplifyToMaxVerts(); // this is based on the max box2d verts
	edgeLine.setPhysics(0.0, 0.5, 0.5);
	edgeLine.create(box2d.getWorld());
		
	drawing.clear();


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
