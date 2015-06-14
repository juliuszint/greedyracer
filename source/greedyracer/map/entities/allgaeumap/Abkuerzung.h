#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CAbkuerzung : public CEntity
{
private:
	CGeo* m_pzgAbkuerzung;

	CFileWavefront m_zgAbkuerzung;
	CPlacement m_zpAbkuerzung;
	CMaterial m_zmAbkuerzung;

public:
	void Init();
	void Init(char* GeoPath);
	CPlacement* GetRootPlacement();
	CGeo * GetGeo();
	void Translate(CHVector Vektor);
};