#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class COptischeStrecke : public CEntity
{
private:
	CGeo* m_pzgOptStrecke;
	CFileWavefront m_zgOptStrecke;
	CPlacement m_zpOptStrecke;
	CMaterial m_zmOptStrecke;


public:
	void Init();
	CPlacement* GetRootPlacement();
};