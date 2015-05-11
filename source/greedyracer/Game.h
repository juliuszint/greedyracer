#pragma once


#ifdef _WIN64
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug64.lib")
#pragma comment (lib, "VektoriaMath_Debug64.lib")
#pragma comment (lib, "ApiUtils_Debug64.lib")
#pragma comment (lib, "ApiNullRenderer_Debug64.lib")
#pragma comment (lib, "ApiDirectX11Basic_Debug64.lib")
#pragma comment (lib, "ApiDirectInput08_Debug64.lib")
#pragma comment (lib, "ApiDirectX11FP_Debug64.lib")
#pragma comment (lib, "ApiOpenGL40_Debug64.lib")
#pragma comment (lib, "ApiNullSound_Debug64.lib")
#pragma comment (lib, "ApiDirectSound_Debug64.lib")
#else
#pragma comment (lib, "Vektoria_Release64.lib")
#pragma comment (lib, "VektoriaMath_Release64.lib")
#pragma comment (lib, "ApiUtils_Release64.lib")
#pragma comment (lib, "ApiNullRenderer_Release64.lib")
#pragma comment (lib, "ApiDirectX11Basic_Release64.lib")
#pragma comment (lib, "ApiDirectInput08_Release64.lib")
#pragma comment (lib, "ApiDirectX11FP_Release64.lib")
#pragma comment (lib, "ApiOpenGL40_Release64.lib")
#pragma comment (lib, "ApiNullSound_Release64.lib")
#pragma comment (lib, "ApiDirectSound_Release64.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug.lib")
#pragma comment (lib, "VektoriaMath_Debug.lib")
#pragma comment (lib, "ApiUtils_Debug.lib")
#pragma comment (lib, "ApiNullRenderer_Debug.lib")
#pragma comment (lib, "ApiDirectX11Basic_Debug.lib")
#pragma comment (lib, "ApiDirectInput08_Debug.lib")
#pragma comment (lib, "ApiDirectX11FP_Debug.lib")
#pragma comment (lib, "ApiOpenGL40_Debug.lib")
#pragma comment (lib, "ApiNullSound_Debug.lib")
#pragma comment (lib, "ApiDirectSound_Debug.lib")
#else
#pragma comment (lib, "Vektoria_Release.lib")
#pragma comment (lib, "VektoriaMath_Release.lib")
#pragma comment (lib, "ApiUtils_Release.lib")
#pragma comment (lib, "ApiNullRenderer_Release.lib")
#pragma comment (lib, "ApiDirectX11Basic_Release.lib")
#pragma comment (lib, "ApiDirectInput08_Release.lib")
#pragma comment (lib, "ApiDirectX11FP_Release.lib")
#pragma comment (lib, "ApiOpenGL40_Release.lib")
#pragma comment (lib, "ApiNullSound_Release.lib")
#pragma comment (lib, "ApiDirectSound_Release.lib")
#endif
#endif




#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "Brewery.h"

using namespace Vektoria;


class CGame
{
public:
    CGame(void);
    ~CGame(void);

	void Init(HWND hwnd, CSplash * psplash);
	void Tick(float fTime, float fTimeDelta);
	void Fini();

	void WindowReSize(int iNewWidth, int iNewHeight); // WindowsReSize wird immer dann aufgerufen, wenn der Benutzer die Fenstergröße verändert hat

private:
	HWND m_hwnd;
	bool m_bReSized;
	// Hier ist Platz für Deine Vektoriaobjekte:
	CRoot m_zroot;
	CScene m_zscene;
	CHardware m_zh;
	CFrame m_zframe;
	CViewport m_zviewport;

	CDeviceKeyboard keyboard;
	
	//CPlacement m_zpSphere;
	//CGeoSphere m_zgSphere;
	//CMaterial m_zm;

	CFileWavefront importer;
	CGeo * worldGeo;
	CPlacement worldPlacement;
	CMaterial worldMaterial;

	CGeoSphere carGeo;
	CPlacement carPlacement;
	CMaterial carMaterial;

	CPlacement m_zpCamera;
	CCamera m_zcamera;
	CParallelLight m_zlight;

	//Häuser
		//Windows
	
		//Gebäude
	CGeoWing m_zgHouseH1;
	CGeoWing m_zgHouseH2;
	CGeoWing m_zgBrewery;
	CGeoWindow m_zgBreweryDoor;
	CGeoWing m_zgBreweryTower;
	CGeoTube m_zgBrewerySupply;
	CGeoWall m_zgBreweryChimney;

		//Placements
	CPlacement m_zpHouseH1;
	CPlacement m_zpHouseH2;
	CPlacement m_zpBrewery;
	CPlacement m_zpBreweryAll;
	CPlacement m_zpBreweryTower;
	CPlacement m_zpBreweryTower2;
	CPlacement m_zpBrewerySupply;
	CPlacement m_zpBrewerySupply2;
	CPlacement m_zpBreweryChimney;
	CPlacement m_zpAllHouses;

		//Materials
	CMaterial m_zmFacadeH1;
	CMaterial m_zmRoofH1;
	CMaterial m_zmFacadeH2;
	CMaterial m_zmRoofH2;
	CMaterial m_zmFacadeBrewery;
	CMaterial m_zmRoofBrewery;
	CMaterial m_zmFacadeBreweryTower;
	CMaterial m_zmRoofBreweryTower;
	CMaterial m_zmFacadeBrewerySupply;
	CMaterial m_zmFacadeBreweryChimney;

	//CBrewery m_zpBrewery;

};


