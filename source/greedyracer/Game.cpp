#include "StdAfx.h"
#include "Game.h"
#include <Windows.h>

// Todo (julius): neue engine herunterladen (bug mit leerem Szenegraphen gefixed)
// blender lieber als .obj exportieren und dann importieren 


CGame::CGame(void)
{
	// Hier eventuelle Vorinitialisierungen Deiner Vektoria-Objekte einfügen:
}

CGame::~CGame(void)
{
	// Hier eventuelle Nachinitialisierungen Deiner Vektoria-Objekte einfügen:
}

void CGame::Init(HWND hwnd, CSplash * psplash)
{
	m_hwnd = hwnd;
	m_bReSized = false;
	fixedCameraMode = false;
	cKeyReleased = true;

	// Hier die Initialisierung Deiner Vektoria-Objekte einfügen:
	m_zroot.Init(psplash);
	m_zcamera.Init();
	m_zframe.Init(hwnd, eApiRender_DirectX11_Shadermodel50);
	m_zviewport.InitFull(&m_zcamera);

	m_zframe.AddDeviceKeyboard(&this->keyboard);
	this->keyboard.SetWASDTranslationSensitivity(20);

	m_zlight.Init(CHVector(0, 1, 0), CColor(1, 1, 1));

	m_zroot.AddFrameHere(&m_zframe);
	m_zframe.AddViewport(&m_zviewport);
	m_zroot.AddScene(&m_zscene);

	// Note (julius): lade die startmap (in dem fall die allgaeuMap weils die einzige ist ^^
	// zu dem zeitpunkt läuft noch kein gamecode nur de map wird in den szene graphen geladen
	// um das menue anzuzeigen was etwas transparent angezeigt wird
	this->currentMap = new AllgaeuMap();
	this->currentMap->Init();
	this->m_zscene.AddPlacement(this->currentMap->GetRootPlacement());

	m_zscene.AddPlacement(&m_zpCamera);
	m_zscene.AddParallelLight(&m_zlight);
	m_zpCamera.AddCamera(&m_zcamera);
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Hier die Echtzeit-Veränderungen einfügen:
	m_zroot.Tick(fTimeDelta);
	float res = fTimeDelta * 5;

	// Note (julius): für debug zwecke hab ich hier ein kleine code schnipsel reingemacht
	// der es möglich macht das man zwischen 2 kamera modi hin und her springt. 1 der freie modus
	// für die entwicklung und 2 der feste modus wo die kamera fix ausgerichtet ist. 
	// getoggeld wird das ganze mit C
	if (this->keyboard.KeyPressed(DIK_C))
	{
		if (cKeyReleased)
		{
			cKeyReleased = false;
			this->ToggleCameraMode();
			OutputDebugStringA("C Pressed Toggled Camera mode\n");
		}
	}
	else
	{
		if (!cKeyReleased)
		{
			cKeyReleased = true;
			OutputDebugStringA("C Released\n");
		}
	}

	if (!fixedCameraMode)
	{
		this->keyboard.PlaceWASD(this->m_zpCamera, res, true);
	}
}

void CGame::Fini()
{
	// Hier die Finalisierung Deiner Vektoria-Objekte einfügen:
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergröße verändert wurde.
	// Hier kannst Du dann die Auflösung des Viewports neu einstellen:

}

void CGame::ToggleCameraMode()
{
	if (fixedCameraMode)
	{
		this->m_zpCamera.SetPointingOff();
	}
	else
	{
		this->m_zpCamera.Translate(CHVector(300, 150, 300));
		this->m_zpCamera.SetPointing(new CHVector(300, 1, 300));
	}
	fixedCameraMode = !fixedCameraMode;
}

