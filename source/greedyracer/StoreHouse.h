#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;

class CStoreHouse
{
public:
	CStoreHouse();
	~CStoreHouse();

	CGeoWing m_zgStoreHouse;
	CPlacement m_zpStoreHouse;
	CMaterial m_zmFacade;
	CMaterial m_zmRoof;

	void InitStoreHouse();
	CPlacement* GetStoreHousePlacement();


};

