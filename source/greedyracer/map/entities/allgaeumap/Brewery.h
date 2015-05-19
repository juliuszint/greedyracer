#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CBrewery : public CEntity
{
private: 
	CGeoWing m_zgBrewery;
	CGeoWing m_zgTower;
	CGeoWindow m_zgDoor;
	CGeoTube m_zgSupply;
	CGeoWall m_zgChimney;

	CPlacement m_zpBrewery;
	CPlacement m_zpTower;
	CPlacement m_zpTower2;
	CPlacement m_zpDoor;
	CPlacement m_zpSupply;
	CPlacement m_zpSupply2;
	CPlacement m_zpChimney;
	CPlacement m_zpAllPlacements;

	CMaterial m_zmFacade;
	CMaterial m_zmRoof;
	CMaterial m_zmFacadeTower;
	CMaterial m_zmRoofTower;
	CMaterial m_zmFacadeSupply;
	CMaterial m_zmFacadeChimney;
public:
	void Init();

	CPlacement* GetRootPlacement();
};

