#include "Water.h"


void Water::Configure(int width, int height)
{
	this->width = width;
	this->height = height;
}

void Water::Init()
{
	this->material.MakeTextureDiffuse("textures\\water02.jpg");
	this->material.SetTextureSpecularBlack();
	this->material.SetAni(4, 4, 10);

	this->quad.Init(this->width, this->height, &this->material);
	this->placement.AddGeo(&this->quad);
	this->placement.RotateXDelta(-HALFPI);
}

CPlacement* Water::GetRootPlacement()
{
	return &this->placement;
}
