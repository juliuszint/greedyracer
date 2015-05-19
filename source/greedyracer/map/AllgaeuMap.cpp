#include "AllgaeuMap.h"


AllgaeuMap::~AllgaeuMap()
{
	free(this->ground);
	free(this->water);
}

void AllgaeuMap::Init()
{
	this->water = new Water();
	this->ground = new Ground();

	this->ground->Configure(10, 10, 60, 40);
	this->ground->Init();
	this->placement.AddPlacement(this->ground->GetRootPlacement());
	
	this->water->Configure(20, 80);
	this->water->Init();
	this->water->GetRootPlacement()->TranslateYDelta(0.1);
	this->water->GetRootPlacement()->TranslateDelta(CHVector(300, 0, 300));
	this->placement.AddPlacement(this->water->GetRootPlacement());
}
CPlacement* AllgaeuMap::GetRootPlacement()
{
	return &this->placement;
}
CHVector AllgaeuMap::GetStartPosition()
{
	return CHVector(0, 0, 0);
}
