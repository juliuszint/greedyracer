#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;
class CCamaro
{
public:
	CCamaro();
	~CCamaro();

	CGeo* m_pzgBodywork;
	CGeo* m_pzgCoolerPaneling;
	CGeo* m_pzgExhaustPaneling;
	CGeo* m_pzgFrontHeadlights;
	CGeo* m_pzgRearLights;
	CGeo* m_pzgWindows;
	CGeo* m_pzgFrontTireR; // Trennen in Links und Rechts f. steuerung
	CGeo* m_pzgFrontRimR;
	CGeo* m_pzgFrontTireL;
	CGeo* m_pzgFrontRimL;
	CGeo* m_pzgRearTires;
	CGeo* m_pzgRearRim;
	CGeo* m_pzgMirrors;
	CGeo* m_pzgExhaust;

	CFileWavefront m_zgBodywork;
	CFileWavefront m_zgCoolerPaneling;
	CFileWavefront m_zgExhaustPaneling;
	CFileWavefront m_zgFrontHeadlights;
	CFileWavefront m_zgRearLights;
	CFileWavefront m_zgWindows;
	CFileWavefront m_zgFrontTireR;
	CFileWavefront m_zgFrontRimR;
	CFileWavefront m_zgFrontTireL;
	CFileWavefront m_zgFrontRimL;
	CFileWavefront m_zgRearTires;
	CFileWavefront m_zgRearRim;
	CFileWavefront m_zgMirrors;
	CFileWavefront m_zgExhaust;

	CPlacement m_zpBodywork;
	CPlacement m_zpFrontTireR;
	CPlacement m_zpFrontTireL;
	CPlacement m_zpRearTires;
	CPlacement m_zpCamaro;

	CMaterial m_zmBodywork;
	CMaterial m_zmPlastic;
	CMaterial m_zmWindow;
	CMaterial m_zmFrontHeadlights;
	CMaterial m_zmRearLights;
	CMaterial m_zmTire;
	CMaterial m_zmExhaust;
	CMaterial m_zmRim;

	void InitCamaro();
	void RotateFrontTiresX();
	void RotateFrontTiresY(bool rotRight);
	CPlacement* GetPlacement();
};

