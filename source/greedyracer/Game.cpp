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
	this->m_zframe.AddDeviceGameController(&this->Controller1);
	this->m_zframe.AddDeviceGameController(&this->Controller2);

	this->keyboard.SetWASDTranslationSensitivity(15);

	this->m_zlight.Init(CHVector(0.5, 1, 0), CColor(1, 1, 1));
	this->m_zlight2.Init(CHVector(0, 1, 0.3), CColor(0.5, 0.5, 0.5));

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
	this->m_zscene.AddAudio(this->gameMenu.GetAudio());
	this->m_zviewport.AddOverlay(this->gameMenu.GetRootOverlay());

	this->hud.InitHud();
	this->hud.SetVisible(false);
	this->m_zviewport.AddOverlay(this->hud.GetRootOverlay());

	m_zscene.AddPlacement(&m_zpCamera);
	m_zscene.AddParallelLight(&m_zlight);
	m_zscene.AddParallelLight(&m_zlight2);
	m_zpCamera.AddCamera(&m_zcamera);
	m_zviewport.SetWireframeOff();

	srand(time(NULL));

	this->m_InitFinished = true;
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	bool ignoreTick = false;
	if (this->gameMenu.GetIsVisible())
	{
		EGameMenuButton result = this->gameMenu.Tick();
		switch (result)
		{
		case EGameMenuButtonQuit:
			PostQuitMessage(0);
			break;
		case EGameMenuButtonCredits:
			this->gameMenu.CreditsSwitch(true);
			break;
		case EGameMenuButtonStart:
			// Todo: game starten
			this->gameMenu.SetIsVisible(false);

			this->currentMatch = new CMatch();
			this->currentMatch->Init(&this->keyboard, this->currentMap, &this->m_zpCamera, &this->hud, &this->m_zscene, &Controller1, &Controller2);
			this->currentMatch->Start();

			break;
		}
	}

	if (this->keyboard.KeyPressed(DIK_ESCAPE))
	{
		if (this->gameMenu.GetIsVisible())
		{
			this->gameMenu.CreditsSwitch(false);
		}
		else
		{
			this->currentMatch->Stop();
			// Note (julius): der tick wird hier aufgerufen und dann unten ignoriert 
			// weil sobald man placments rausnimmt aus der map was in stop passiert
			// muss einmal geticked werden bevor man den speicherplatz freigeben kann
			// sonst kommts zur AccessViolation
			m_zroot.Tick(fTimeDelta);
			ignoreTick = true;

			free(this->currentMatch);
			this->currentMatch = NULL;

			this->gameMenu.SetIsVisible(true);
		}
	}

	if (this->currentMatch != NULL)
	{
		this->currentMatch->Tick(fTime, fTimeDelta);
	}

	// Hier die Echtzeit-Veränderungen einfügen:
	if (!ignoreTick)
	{
		m_zroot.Tick(fTimeDelta);
	}
	else
	{
		ignoreTick = false;
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
