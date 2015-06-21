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
	this->ShortcutCount = 3;

	// Note (julius): abkürzung im waldgebiet
	this->shortCuts[0].ChancePrecentage = 38;
	this->shortCuts[0].MaxActiveTime = 15;
	this->shortCuts[0].ActiveTime = 0;

	this->shortCuts[0].CollisionEntity = new CFallenTree();
	this->shortCuts[0].CollisionEntity->Init();
	this->shortCuts[0].CollisionPlacement = shortCuts[0].CollisionEntity->GetRootPlacement();
	this->shortCuts[0].CollisionPlacement->TranslateDelta(CHVector(-17.9, 0.1, 14));
	this->shortCuts[0].CollisionPlacement->SwitchOff();
	this->placement.AddPlacement(this->shortCuts[0].CollisionPlacement);

	// Note (julius): abkürzung in den bergen
	this->shortCuts[1].ChancePrecentage = 50;
	this->shortCuts[1].MaxActiveTime = 2;
	this->shortCuts[1].ActiveTime = 0;
	this->shortCuts[1].CollisionEntity = new CRocks();
	this->shortCuts[1].CollisionEntity->Init();
	this->shortCuts[1].CollisionPlacement = shortCuts[1].CollisionEntity->GetRootPlacement();
	this->shortCuts[1].CollisionPlacement->TranslateDelta(CHVector(11, .1, -36.5));
	this->shortCuts[1].CollisionPlacement->SwitchOff();
	this->placement.AddPlacement(this->shortCuts[1].CollisionPlacement);

	// Note (julius): abkürzung im dorf
	this->shortCuts[2].ChancePrecentage = 68;
	this->shortCuts[2].MaxActiveTime = 6;
	this->shortCuts[2].ActiveTime = 0;

	this->shortCuts[2].CollisionEntity = new CBarrel();
	this->shortCuts[2].CollisionEntity->Init();
	this->shortCuts[2].CollisionPlacement = shortCuts[2].CollisionEntity->GetRootPlacement();
	this->shortCuts[2].CollisionPlacement->TranslateDelta(CHVector(5.3, .2, -0.5));
	this->shortCuts[2].CollisionPlacement->SwitchOff();
	this->placement.AddPlacement(this->shortCuts[2].CollisionPlacement);

	this->water = new CWater();
	//this->ground = new CGround();
	this->landscape = new CLandscape();
	this->strecke = new CStrecke();

	/*this->ground->Configure(10, 10, 60, 40);
	this->ground->Init();
	this->placement.AddPlacement(this->ground->GetRootPlacement());*/

	//this->landscape->Init();
	//// Note (julius): fasten klappt den kompletten unteren baum zu sodass
	//// einzelen placements nicht mehr abgeschaltet werden können was gebraucht wird
	//// für die abkürzungs ereignisse
	//this->placement.Fasten();
	//this->placement.AddPlacement(this->landscape->GetRootPlacement());

	/*this->water->Configure(20, 80);
	this->water->Init();
	this->water->GetRootPlacement()->TranslateYDelta(0.1);
	this->water->GetRootPlacement()->TranslateDelta(CHVector(1, 0, 0));
	this->placement.AddPlacement(this->water->GetRootPlacement());*/

	this->strecke->Init();
	this->placement.AddPlacement(this->strecke->GetRootPlacement());
	//Strecke über die Klasse Strecke verschieben
}
CPlacement* CAllgaeuMap::GetRootPlacement()
{
	return &this->placement;
}

CShortcutData* CAllgaeuMap::GetShortcut(int index)
{
	return &this->shortCuts[index];
}

MapPositions CAllgaeuMap::GetStartPosition()
{
	return strecke->GetStartPosition();
}

int CAllgaeuMap::IsOnShortcutTrigger(CHVector position)
{
	return this->strecke->IsOnShortcutTrigger(position);
}

int CAllgaeuMap::IsOnCheckpoint(CHVector position)
{
	CRay raytoRoad(position + CHVector(0.0f, 1.0f, 0.0f), CHVector(0.0f, -1.0f, 0.0f, 0.0f), QUASI_ZERO, F_MAX);

	//Abfrage Intersect mit Checkpoints
	for (int i = 0; i < 5; i++)
	{
		CGeo* geo = this->strecke->getCheckpointGeo(i)->GetGeo();
		CTriangleList* List = (CTriangleList*)geo;
		if (List->IsIntersecting(raytoRoad))
		{
			return i + 1;
		}
	}
	return -1;
}

CHVector CAllgaeuMap::IsOnTrack(CHVector position)
{
	position.y + 1;
	CRay raytoRoad(position, CHVector(0.0f, -1.0f, 0.0f, 0.0f), QUASI_ZERO, F_MAX);
	
	//Abfrage Intersect mit Sektoren
	for (int i = 0; i < 3; i++)
	{
		CGeo* geo = this->strecke->getSektorGeo(i)->GetGeo();
		CTriangleList* List = (CTriangleList*)geo;
		
		if (List->IsIntersecting(raytoRoad))
		{
			CHVector Hilfsvar = this->strecke->getSektorGeo(i)->GetRootPlacement()->GetTranslation();
			return this->strecke->getSektorGeo(i)->GetRootPlacement()->GetTranslation();
		}
	}
	
	//Abfrage Intersect mit Abkürzungen
	for (int i = 0; i < 5; i++)
	{
		CGeo* geo = this->strecke->getAbkuerzungGeo(i)->GetGeo();
		CTriangleList* List = (CTriangleList*)geo;
		if (List->IsIntersecting(raytoRoad))
		{
			return this->strecke->getAbkuerzungGeo(i)->GetRootPlacement()->GetTranslation();
		}
	}

	return CHVector(1.0f, 1.0f, 1.0f);
}

bool CAllgaeuMap::IsOnFinish(CHVector position)
{
	CRay raytoRoad(position + CHVector(0.0f, 1.0f, 0.0f), CHVector(0.0f, -1.0f, 0.0f, 0.0f), QUASI_ZERO, F_MAX);

	CGeo* geo = this->strecke->getStartGeo()->GetGeo();
	CTriangleList* List = (CTriangleList*)geo;
	if (List->IsIntersecting(raytoRoad))
	{
		return true;
	}
	else
		return false;

}
