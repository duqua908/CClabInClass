#include "Skeleton.h"


Skeleton::Skeleton()
{ posX=ofGetWindowWidth() *0.5;
posY = ofGetWindowWidth() * 0.5; 
}

void Skeleton :: setup(){
}

void Skeleton :: display(){

// mouth background 
	ofSetColor(0);
	ofRect(posX-25, posY+35, 40,30);

// Skull 
	ofSetColor(200);
	ofCircle(posX, posY, 60);
// eyes

	ofSetColor(0);
	ofCircle(posX+25, posY-5, 20);
	ofCircle(
		posX-25, posY-5, 20);

// jawbone 
	ofSetColor(200);
ofRect(posX-25, posY+55+mouthY, 50,30);
}
void Skeleton::reset(float newPosX, float newPosY){
	posX = newPosX;
	posY = newPosY;
}
