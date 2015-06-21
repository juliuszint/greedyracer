#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include ".\..\..\Entity.h"

using namespace Vektoria;

class CRocks : public CEntity
{
private:
	CGeo* m_pzgTrigger;
	CFileWavefront m_zgTrigger;
	CPlacement m_zpTrigger;
	CMaterial m_zmTrigger;
public:
	void Init();
	CPlacement* GetRootPlacement();
};

