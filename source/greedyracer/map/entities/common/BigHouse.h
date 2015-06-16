#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CBigHouse : public CEntity
{
private:
	
public:
	CGeoWing m_zgBigHouse;
	CMaterial m_zmFacade;
	CMaterial m_zmRoof;
	CPlacement m_zpBigHouse;
	CPlacement* GetRootPlacement();

	void Init();
};

