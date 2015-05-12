#pragma once

#include "Vektoria\Root.h"
using namespace Vektoria;

class CLittleHouse
{
public:
	CLittleHouse();
	~CLittleHouse();

	CGeoWing m_zgLittleHouse;
	CPlacement m_zpLittleHouse;
	CMaterial m_zmFacade;
	CMaterial m_zmRoof;

	CPlacement* GetLittleHousePlacement();

	void InitLittleHouse();
};

