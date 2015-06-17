#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CPorsche : public CEntity
{
private:
	CGeo* m_pzgBodywork;
	CGeo* m_pzgFrontHeadlights;
	CGeo* m_pzgRearLights;
	CGeo* m_pzgWindows;
	CGeo* m_pzgFrontTires; // Trennen in Links und Rechts f. steuerung
	CGeo* m_pzgRearTires;
	CGeo* m_pzgExhaust;

	CFileWavefront m_zgBodywork;
	CFileWavefront m_zgFrontHeadlights;
	CFileWavefront m_zgRearLights;
	CFileWavefront m_zgWindows;
	CFileWavefront m_zgFrontTires;
	CFileWavefront m_zgRearTires;
	CFileWavefront m_zgExhaust;

	CPlacement m_zpBodywork;
	CPlacement m_zpFrontHeadlights;
	CPlacement m_zpRearLights;
	CPlacement m_zpWindows;
	CPlacement m_zpFrontTires;
	CPlacement m_zpRearTires;
	CPlacement m_zpPorsche;
	CPlacement m_zpExhaust;

	CMaterial m_zmBodywork;
	CMaterial m_zmWindow;
	CMaterial m_zmFrontHeadlights;
	CMaterial m_zmRearLights;
	CMaterial m_zmTires;
	CMaterial m_zmExhaust;
public:
	void Init();

	CPlacement* GetRootPlacement();


};

