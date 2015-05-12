#include "Ground.h"


Ground::Ground()
{
}


Ground::~Ground()
{
	free(this->groundPlacements);
	free(this->quadGeos);
}

void Ground::Init(float quadWidth, float quadHeight, int width, int height)
{
	this->groundPlacements = (CPlacement*)malloc(sizeof(CPlacement) * width * height); 
	this->quadGeos = (CGeoQuad*)malloc(sizeof(CGeoQuad) * width * height); 
}

		
