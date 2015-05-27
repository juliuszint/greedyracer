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
	free(this->currentMap);
}

void CGame::Init(HWND hwnd, CSplash * psplash)
{
	this->m_hwnd = hwnd;
	this->m_bReSized = false;
	this->fixedCameraMode = false;
	this->cKeyReleased = true;

	// Hier die Initialisierung Deiner Vektoria-Objekte einfügen:
	this->m_zroot.Init(psplash);
	this->m_zcamera.Init();
	this->m_zframe.Init(hwnd, eApiRender_DirectX11_Shadermodel50);
	this->m_zviewport.InitFull(&m_zcamera);

	this->m_zframe.AddDeviceKeyboard(&this->keyboard);
	this->m_zframe.AddDeviceCursor(&this->cursor);

	this->keyboard.SetWASDTranslationSensitivity(20);

	this->m_zlight.Init(CHVector(0, 1, 0), CColor(1, 1, 1));

	this->m_zroot.AddFrameHere(&m_zframe);
	this->m_zframe.AddViewport(&m_zviewport);
	this->m_zroot.AddScene(&m_zscene);

	// Note (julius): lade die startmap (in dem fall die allgaeuMap weils die einzige ist ^^
	// zu dem zeitpunkt läuft noch kein gamecode nur de map wird in den szene graphen geladen
	// um das menue anzuzeigen was etwas transparent angezeigt wird
	this->currentMap = new CAllgaeuMap();
	this->currentMap->Init();
	this->m_zscene.AddPlacement(this->currentMap->GetRootPlacement());

	// Note (julius): das game menu wird direkt am start angezeigt deswegen wirds hier direkt
	// eingehängt und anschließend kann man es über die funktion CGameMenu.MakeVisible() wieder 
	// sichtbar machen
	this->gameMenu.Init(&this->cursor);
	this->m_zviewport.AddOverlay(this->gameMenu.GetRootOverlay());
	
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

	if (this->gameMenu.GetIsVisible())
	{
		this->gameMenu.Tick();
	}
	else if (this->keyboard.KeyPressed(DIK_ESCAPE))
	{
		this->gameMenu.SetIsVisible(true);
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

