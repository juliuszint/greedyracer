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
#include "LittleHouse.h"
#include "BigHouse.h"
#include "Porsche.h"
#include "Camaro.h"
#include "Tree.h"
#include "Track.h"

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

	//Note(Peter): Inizialisierung der Häuser
	CBigHouse m_zgBigHouse;
	CBigHouse m_zgBigHouse2;
	CBigHouse m_zgBigHouse3;
	CBigHouse m_zgBigHouse4;
	CLittleHouse m_zgLittleHouse;
	CLittleHouse m_zgLittleHouse2;
	CLittleHouse m_zgLittleHouse3;
	CBrewery m_zgBrewery;
	//Note(Peter): Inizialisierung Autos
	CPorsche m_zgPorsche;
	CCamaro m_zgCamaro;
	//Note(Peter): Inizialisierung Enviroment
	CTree m_zgTree;
	CTree m_zgTree2;
	CTree m_zgTree3;
	CTree m_zgTree4;
	CTree m_zgTreeBush;
	CTree m_zgTreeBush2;
	CTree m_zgTreeBush3;
	CTree m_zgTreeBush4;
	//CTree m_zgTreeRound;


	CTrack m_zgTrack;
	CGeoQuad m_zgGround;
	CPlacement m_zpGround;
	CMaterial m_zmGrass;
	CMaterial m_zmLog;

	CGeo* m_pzgLandscape;
	CGeo* m_pzgTreeFir;
	CGeo* m_pzgTreeRound;
	CGeo* m_pzgTreeBobblig;
	CGeo* m_pzgLog;
	CFileWavefront m_zgLandscape;
	CFileWavefront m_zgTreeFir;
	CFileWavefront m_zgTreeRound;
	CFileWavefront m_zgTreeBobblig;
	CFileWavefront m_zgLog;

	CPlacement m_zpLandscape;


	CGeoCube m_zgSkybox;
	CPlacement m_zpSkybox;
	CMaterial m_zmSkybox;
	// Ray
	CRay m_zrRay;

};


