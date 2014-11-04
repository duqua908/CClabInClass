#pragma once
#include "ofMain.h"

class Skeleton
{
public:
	Skeleton();

	//variables
	float posX, posY;
	float mouthY;

	//methods
	void setup();
	void display();
	void reset(float newPosX , float newPosY);
};

