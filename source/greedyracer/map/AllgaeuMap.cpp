#include "AllgaeuMap.h"


CAllgaeuMap::~CAllgaeuMap()
{
	free(this->ground);
	free(this->water);
}

void CAllgaeuMap::Init()
{
	this->water = new CWater();
	this->ground = new CGround();

	this->ground->Configure(10, 10, 60, 40);
	this->ground->Init();
	this->placement.AddPlacement(this->ground->GetRootPlacement());
	
	this->water->Configure(20, 80);
	this->water->Init();
	this->water->GetRootPlacement()->TranslateYDelta(0.1);
	this->water->GetRootPlacement()->TranslateDelta(CHVector(300, 0, 300));
	this->placement.AddPlacement(this->water->GetRootPlacement());
}
CPlacement* CAllgaeuMap::GetRootPlacement()
{
	return &this->placement;
}
CHVector CAllgaeuMap::GetStartPosition()
{
	return CHVector(0, 0, 0);
}


int CAllgaeuMap::IsOnCheckpoint(CHVector position)
{
	return 0;
}

CHVector CAllgaeuMap::IsOnTrack(CHVector position)
{
	return CHVector(0, 0, 0);
}

bool CAllgaeuMap::IsOnFinish(CHVector position)
{
	return false;
}
