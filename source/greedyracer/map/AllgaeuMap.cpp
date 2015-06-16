#include "AllgaeuMap.h"


CAllgaeuMap::~CAllgaeuMap()
{
	free(this->ground);
	free(this->landscape);
	free(this->water);
	free(this->strecke);
}

void CAllgaeuMap::Init()
{
	this->water = new CWater();
	//this->ground = new CGround();
	this->landscape = new CLandscape();
	this->strecke = new CStrecke();

	//this->ground->Configure(10, 10, 60, 40);
	//this->ground->Init();
	//this->placement.AddPlacement(this->ground->GetRootPlacement());

	this->landscape->Init();
	//this->placement.Fasten();
	this->placement.AddPlacement(this->landscape->GetRootPlacement());
	
	this->water->Configure(20, 80);
	this->water->Init();
	this->water->GetRootPlacement()->TranslateYDelta(0.1);
	this->water->GetRootPlacement()->TranslateDelta(CHVector(1, 0, 0));
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
	CHVector dir(0.0f, -1.0f, 0.0f, 0.0f);
	float dist = 10.0f;

	//Abfrage Intersect mit Checkpoints
	for (int i = 0; i < 5; i++)
	{
		CGeo* geo = this->strecke->getCheckpointGeo(i)->GetGeo();
		if (geo->Intersects(position, dir, &dist))
		{
			return i + 1;
		}
	}

}

CHVector CAllgaeuMap::IsOnTrack(CHVector position)
{
	//CRay raytoRoad;
	//raytoRoad.Init(position, CHVector(0.0f, -1.0f, 0.0f, 0.0f));
	CHVector dir(0.0f, -1.0f, 0.0f, 0.0f);
	float dist = 10.0f;

	//Abfrage Intersect mit Checkpoints
	for (int i = 0; i < 5; i++)
	{
		CGeo* geo = this->strecke->getCheckpointGeo(i)->GetGeo();
		if (geo->Intersects(position, dir, &dist))
		{
			return CHVector(0.0f, 0.0f, 0.0f);
		}
	}

	//Abfrage Intersect mit Sektoren
	for (int i = 0; i < 5; i++)
	{
		CGeo* geo = this->strecke->getSektorGeo(i)->GetGeo();
		if (geo->Intersects(position, dir, &dist))
		{
			return CHVector(0.0f, 0.0f, 0.0f);
		}
	}

	//Abfrage Intersect mit Abkürzungen
	for (int i = 0; i < 5; i++)
	{
		CGeo* geo = this->strecke->getAbkuerzungGeo(i)->GetGeo();
		if (geo->Intersects(position, dir, &dist))
		{
			return CHVector(0.0f, 0.0f, 0.0f);
		}
	}

	return CHVector(1.0f, 1.0f, 1.0f);

}

bool CAllgaeuMap::IsOnFinish(CHVector position)
{

	CHVector dir(0.0f, -1.0f, 0.0f, 0.0f);
	float dist = 10.0f;

	CGeo* geo = this->strecke->getStartGeo()->GetGeo();
	if (geo->Intersects(position, dir, &dist))
	{
		return true;
	}
	else
		return false;

}
