#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CCheckpoint : public CEntity
{
private:
	CGeo* m_pzgCheckpoint;

	CFileWavefront m_zgCheckpoint;
	CPlacement m_zpCheckpoint;
	CMaterial m_zmCheckpoint;

public:
	void Init();
	void Init( char * GeoPath);
	CPlacement* GetRootPlacement();
};