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
#include "map\entities\common\Ground.h";
#include "map\entities\allgaeumap\Track.h"
#include "map\entities\common\Camaro.h"
#include "CharacterController.h"
#include "Vehicle.h"
#include "map\Map.h"
#include "map\AllgaeuMap.h"
#include "menu\GameMenu.h"
#include "Match.h"

using namespace Vektoria;


class CGame
{
public:
    CGame(void);
    ~CGame(void);

	void Init(HWND hwnd, CSplash * psplash);
	void Tick(float fTime, float fTimeDelta);
	void Fini();

	CMatch* currentMatch;
	CDeviceKeyboard keyboard;
	
	void WindowReSize(int iNewWidth, int iNewHeight); // WindowsReSize wird immer dann aufgerufen, wenn der Benutzer die Fenstergröße verändert hat

private:
	HWND m_hwnd;
	bool m_bReSized;
	bool fixedCameraMode;
	bool cKeyReleased;

	// Hier ist Platz für Deine Vektoriaobjekte:
	CRoot m_zroot;
	CScene m_zscene;
	CHardware m_zh;
	CFrame m_zframe;
	CViewport m_zviewport;
	CPlacement m_zpCamera;
	CCamera m_zcamera;
	CParallelLight m_zlight;

	
	CDeviceCursor cursor;

	CGameMenu gameMenu;
	CMap* currentMap;
	

	void ToggleCameraMode();
	void MakeGameMenuVisible();
	void PositionCamera();
	void CleanCurrentMatch();
	
};










