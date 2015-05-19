#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CBigHouse : public Entity
{
private:
	CGeoWing m_zgBigHouse;
	CPlacement m_zpBigHouse;
	CMaterial m_zmFacade;
	CMaterial m_zmRoof;
public:

	CPlacement* GetRootPlacement();

	void Init();
};

