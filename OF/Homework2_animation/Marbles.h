#pragma once
#include "ofMain.h"

class Marbles
{
public:
	Marbles();

	float posX, posY;
	float velX, velY;
	int r,g,b;
	float size; 

	void setup(); 
	void move(); 
	void display(float newPosX; float newPosY);


	
};

