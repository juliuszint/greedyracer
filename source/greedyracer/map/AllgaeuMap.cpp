#include "AllgaeuMap.h"


CAllgaeuMap::~CAllgaeuMap()
{
	free(this->ground);
	free(this->water);
	free(this->strecke);
}

void CAllgaeuMap::Init()
{
	this->water = new CWater();
	this->ground = new CGround();
	this->strecke = new CStrecke();

	this->ground->Configure(10, 10, 60, 40);
	this->ground->Init();
	this->placement.AddPlacement(this->ground->GetRootPlacement());
	
	this->water->Configure(20, 80);
	this->water->Init();
	this->water->GetRootPlacement()->TranslateYDelta(0.1);
	this->water->GetRootPlacement()->TranslateDelta(CHVector(300, 0, 300));
	this->placement.AddPlacement(this->water->GetRootPlacement());

	this->strecke->Init();
	this->placement.AddPlacement(this->strecke->GetRootPlacement());
	//Strecke über die Klasse Strecke verschieben
}
CPlacement* CAllgaeuMap::GetRootPlacement()
{
	return &this->placement;
}

CHVector CAllgaeuMap::GetStartPosition()
{
	return strecke->GetStartPosition();
}


int CAllgaeuMap::IsOnCheckpoint(CHVector position)
{
	return strecke->IsOnCheckpoint(position);
}

CHVector CAllgaeuMap::IsOnTrack(CHVector position)
{
	return strecke->IsOnTrack(position);
}

bool CAllgaeuMap::IsOnFinish(CHVector position)
{
	return strecke->IsOnFinish(position);
}
