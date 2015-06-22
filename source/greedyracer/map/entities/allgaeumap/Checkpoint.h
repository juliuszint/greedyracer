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

	float RespawnAngle;

public:
	void Init();
	void Init( char * GeoPath);
	CPlacement* GetRootPlacement();
	CGeo * GetGeo();
	void Translate(CHVector Vektor);
	void setRespawnAngle(float fAngle);
	float getRespawnAngle();
};