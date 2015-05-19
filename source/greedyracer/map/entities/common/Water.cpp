#include "Water.h"


void CWater::Configure(int width, int height)
{
	this->width = width;
	this->height = height;
}

void CWater::Init()
{
	this->material.MakeTextureDiffuse("textures\\water02.jpg");
	this->material.SetTextureSpecularBlack();
	this->material.SetAni(4, 4, 10);

	this->quad.Init(this->width, this->height, &this->material);
	this->placement.AddGeo(&this->quad);
	this->placement.RotateXDelta(-HALFPI);
}

CPlacement* CWater::GetRootPlacement()
{
	return &this->placement;
}
