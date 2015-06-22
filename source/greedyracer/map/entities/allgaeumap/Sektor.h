#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CSektor : public CEntity
{
private:
	CGeo* m_pzgSektor;

	CFileWavefront m_zgSektor;
	CPlacement m_zpSektor;
	CMaterial m_zmSektor;

	float RespawnAngle;

public:
	void Init();
	void Init(char* GeoPath);
	CPlacement* GetRootPlacement();
	CGeo * GetGeo();
	void Translate(CHVector Vektor);
	void setRespawnAngle(float fAngle);
	float getRespawnAngle();
};