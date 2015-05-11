#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;
class CPorsche
{
public:
	CPorsche();
	~CPorsche();

	CGeo* m_pzgBodywork;
	CGeo* m_pzgFrontHeadlights;
	CGeo* m_pzgRearLights;
	CGeo* m_pzgWindows;
	CGeo* m_pzgFrontTires; // Trennen in Links und Rechts f. steuerung
	CGeo* m_pzgRearTires;

	CFileWavefront m_zgBodywork;
	CFileWavefront m_zgFrontHeadlights;
	CFileWavefront m_zgRearLights;
	CFileWavefront m_zgWindows;
	CFileWavefront m_zgFrontTires;
	CFileWavefront m_zgRearTires;

	CPlacement m_zpBodywork;
	CPlacement m_zpFrontHeadlights;
	CPlacement m_zpRearLights;
	CPlacement m_zpWindows;
	CPlacement m_zpFrontTires;
	CPlacement m_zpRearTires;
	CPlacement m_zpPorsche;

	CMaterial m_zmBodywork;
	CMaterial m_zmWindow;
	CMaterial m_zmFrontHeadlights;
	CMaterial m_zmRearLights;
	CMaterial m_zmTires;

	void InitPorsche();

	CPlacement* GetPlacement();


};

