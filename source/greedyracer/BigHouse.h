#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;

class CBigHouse
{
public:
	CBigHouse();
	~CBigHouse();

	CGeoWing m_zgBigHouse;
	CPlacement m_zpBigHouse;
	CMaterial m_zmFacade;
	CMaterial m_zmRoof;

	CPlacement* GetBigHousePlacement();

	void InitBigHouse();
};

