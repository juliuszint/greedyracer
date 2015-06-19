#include "StdAfx.h"
#include "Game.h"
#include <Windows.h>

// Todo (julius): neue engine herunterladen (bug mit leerem Szenegraphen gefixed)
// blender lieber als .obj exportieren und dann importieren 


CGame::CGame(void)
{
	// Hier eventuelle Vorinitialisierungen Deiner Vektoria-Objekte einfügen:
	this->m_InitFinished = false;
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
	this->currentMatch = NULL;

	// Hier die Initialisierung Deiner Vektoria-Objekte einfügen:
	this->m_zroot.Init(psplash);
	this->m_zcamera.Init();

	this->m_zframe.Init(hwnd, eApiRender_DirectX11_Shadermodel50);
	this->m_zviewport.InitFull(&m_zcamera);

	this->m_zframe.AddDeviceKeyboard(&this->keyboard);
	this->m_zframe.AddDeviceCursor(&this->cursor);

	this->keyboard.SetWASDTranslationSensitivity(15);

	this->m_zlight.Init(CHVector(0.5, 1, 0), CColor(1, 1, 1));

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

	this->hud.InitHud();
	this->hud.SetVisible(false);
	this->m_zviewport.AddOverlay(this->hud.GetRootOverlay());
	
	m_zscene.AddPlacement(&m_zpCamera);
	m_zscene.AddParallelLight(&m_zlight);
	m_zpCamera.AddCamera(&m_zcamera);
	m_zviewport.SetWireframeOff();

	this->m_InitFinished = true;
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Hier die Echtzeit-Veränderungen einfügen:
	m_zroot.Tick(fTimeDelta);

	if (this->gameMenu.GetIsVisible())
	{
		this->CleanCurrentMatch();

		EGameMenuButton result = this->gameMenu.Tick();
		switch (result)
		{
		case EGameMenuButtonQuit:
			PostQuitMessage(0);
			break;
		case EGameMenuButtonStart:
			// Todo: game starten
			this->gameMenu.SetIsVisible(false);
			this->CleanCurrentMatch();
			this->currentMatch = new CMatch(&keyboard);
			this->currentMatch->Init(this->currentMap, &this->m_zpCamera, &this->hud);
			this->currentMatch->Start();

			break;
		}
	}

	else if (this->keyboard.KeyPressed(DIK_ESCAPE))
	{
		this->gameMenu.SetIsVisible(true);
	}

	if (this->currentMatch != NULL)
	{
		this->currentMatch->Tick(fTimeDelta);
	}
}
void CGame::CleanCurrentMatch()
{
	if (this->currentMatch != NULL)
	{
		this->currentMatch->Stop();
		free(this->currentMatch);
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
	if (this->m_InitFinished)
	{
		this->m_zframe.ReSize(iNewWidth, iNewHeight);
	}
}
