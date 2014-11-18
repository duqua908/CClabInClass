
#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

// Create the sound class and declare the variables of the event listener
class SoundData {
public:
	int	 soundID;
	bool bHit;
	
};

// Design your friends. Based of the box2dCircle (my friends will be round) 
// I will include my friends characteristics here
class Friends : public ofxBox2dCircle {
	
public:
	Friends() {
	}
	ofColor color;
	void draw() {
		float radius = getRadius();
		glPushMatrix();
		glTranslatef(getPosition().x, getPosition().y, 0);

		ofSetColor(color.r, color.g, color.b);
		ofFill();
		ofCircle(0, 0, radius);	
		
		glPopMatrix();
		
	}
	// Make the left eye 
	void displayEyeWhiteLeft(){
		float radius = getRadius();
		glPushMatrix();
		glTranslatef(getPosition().x -15, getPosition().y-10, 0);
		
		ofSetColor(255);
		ofFill();
		ofCircle(0, 0, radius/4);
		
		glPopMatrix();
	}
	void displayEyeBlackLeft(){
		float radius = getRadius();
		glPushMatrix();
		glTranslatef(getPosition().x -12, getPosition().y-10, 0);
		
		ofSetColor(0);
		ofFill();
		ofCircle(0, 0, radius/16);
		
		glPopMatrix();
	}

	// Make the Right Eye 
	void displayEyeWhiteRight(){
		float radius = getRadius();
		glPushMatrix();
		glTranslatef(getPosition().x +15, getPosition().y-10, 0);
		
		ofSetColor(255);
		ofFill();
		ofCircle(0, 0, radius/4);
		
		glPopMatrix();
	}

	void displayEyeBlackRight(){
		float radius = getRadius();
		glPushMatrix();
		glTranslatef(getPosition().x +12, getPosition().y-10, 0);
		
		ofSetColor(0);
		ofFill();
		ofCircle(0, 0, radius/16);
		
		glPopMatrix();
	}
	// Make the mouth (this will only appear when your friend gets bumped) 
	void displayMouth() {
		float radius = getRadius();
		glPushMatrix();
		glTranslatef(getPosition().x, getPosition().y, 0);
		
		ofSetColor(0); 
		ofFill();
		ofCircle(0, 15, radius/8);
	}
};

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		
		//Add the function of the contact event listern from box2d. This will make my friends react when they get bumped
	void contactStart(ofxBox2dContactArgs &e);
	void contactEnd(ofxBox2dContactArgs &e);
		
		// declare my variables
		ofSoundPlayer		ow;
	
		ofxBox2d                                box2d;			  //	the box2d world
	ofPolyline                              drawing;		  //	we draw with this first
	ofxBox2dEdge                            edgeLine;		  //	the box2d edge/line shape (min 2 points)
	vector		<ofPtr<ofxBox2dCircle> >	circles;		  //	default box2d circles
	vector		<ofPtr<ofxBox2dRect> >		boxes;			  //	defalut box2d rects
	vector		<ofPtr<Friends> >    friends;  //	this is a custom particle the extends a cirlce
		
	// Draw a rectangle to enable bouncing off the wall:
		float 				px, py;
		bool                bDrawLines;
		bool                bMouseForce;

		int nBandsToGet;
		
};
