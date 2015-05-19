#pragma once

#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CTree : public Entity
{
private:
	CGeoWall m_zgTip;
	CGeoWall m_zgMiddle;
	CGeoWall m_zgBottom;
	CGeoWall m_zgLog;

	CPlacement m_zpTip;
	CPlacement m_zpMiddle;
	CPlacement m_zpBottom;
	CPlacement m_zpLog;
	CPlacement m_zpTree;

	CMaterial m_zmLeafs;
	CMaterial m_zmLog;
public:
	void Init();
	CPlacement* GetRootPlacement();
};

