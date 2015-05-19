#pragma once

#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CLittleHouse : public Entity
{
private:
	CGeoWing m_zgLittleHouse;
	CPlacement m_zpLittleHouse;
	CMaterial m_zmFacade;
	CMaterial m_zmRoof;
public:
	CPlacement* GetRootPlacement();

	void Init();
};

