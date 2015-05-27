#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CCamaro : public CEntity
{
private:
	CGeo* m_pzgBodywork;
	CGeo* m_pzgCoolerPaneling;
	CGeo* m_pzgExhaustPaneling;
	CGeo* m_pzgFrontHeadlights;
	CGeo* m_pzgRearLights;
	CGeo* m_pzgWindows;
	CGeo* m_pzgFrontTires; // Trennen in Links und Rechts f. steuerung
	CGeo* m_pzgRearTires;

	CFileWavefront m_zgBodywork;
	CFileWavefront m_zgCoolerPaneling;
	CFileWavefront m_zgExhaustPaneling;
	CFileWavefront m_zgFrontHeadlights;
	CFileWavefront m_zgRearLights;
	CFileWavefront m_zgWindows;
	CFileWavefront m_zgFrontTires;
	CFileWavefront m_zgRearTires;

	CPlacement m_zpBodywork;
	CPlacement m_zpCoolerPaneling;
	CPlacement m_zpExhaustPaneling;
	CPlacement m_zpFrontHeadlights;
	CPlacement m_zpRearLights;
	CPlacement m_zpWindows;
	CPlacement m_zpFrontTires;
	CPlacement m_zpRearTires;
	CPlacement m_zpCamaro;

	CMaterial m_zmBodywork;
	CMaterial m_zmPlastic;
	CMaterial m_zmWindow;
	CMaterial m_zmFrontHeadlights;
	CMaterial m_zmRearLights;
	CMaterial m_zmTires;
public:

	void Init();

	CPlacement* GetRootPlacement();
//	CVehicle * m_zvAuto;


	void InitCamaro();
//	void addVehicle(CVehicle * Fahrzeug) { m_zvAuto = Fahrzeug; };

	CPlacement* GetPlacement();
//	CVehicle** GetVehicle();
};

