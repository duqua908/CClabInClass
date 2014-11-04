
#include "Marbles.h"


Marbles::Marbles()
{
	posX = ofGetWindowWidth() * 0.5;
	posY = ofGetWindowWidth()* 0.5; 
}

void Marbles:: setup(){
	size = ofRandom(5,30); 

	velX = ofRandom(-4,4);
	velY = ofRandom(-4,-1);

	r = ofRandom(255);
	g = ofRandom(255); 
	b = ofRandom(255);

}

void Marbles::move(){
	posX= posX +velX; 
	posY+= velY;

	if (posX> ofGetWindowWidth() || posX<0){
		velX = velX*(-1);
	}
	if (posY> ofGetWindowWidth() || posY<0){
		velY= velY*(-1);
	}
}

void Marbles::display(float newPosX, float newPosY){

	ofSetColor(r,g,b);
	ofCircle(posX,posY, size);
}

void Marbles::reset(float newPosX, float newPosY){
	posX= newPosX ;
	posY= newPosY + 50;
}


