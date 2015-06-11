#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CStart : public CEntity
{
private:
	CGeo* m_pzgStart;

	CFileWavefront m_zgStart;
	CPlacement m_zpStart;
	CMaterial m_zmStart;

public:
	void Init();
	CPlacement* GetRootPlacement();
	CGeo * GetGeo();
};