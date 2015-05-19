#include "StdAfx.h"
#include "Game.h"

// Todo (julius): neue engine herunterladen (bug mit leerem Szenegraphen gefixed)
// blender lieber als .obj exportieren und dann importieren 


CGame::CGame(void)
{
	// Hier eventuelle Vorinitialisierungen Deiner Vektoria-Objekte einf�gen:
}

CGame::~CGame(void)
{
	// Hier eventuelle Nachinitialisierungen Deiner Vektoria-Objekte einf�gen:
}

void CGame::Init(HWND hwnd, CSplash * psplash)
{
	m_hwnd = hwnd;
	m_bReSized = false;
	// Hier die Initialisierung Deiner Vektoria-Objekte einf�gen:
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
	// zu dem zeitpunkt l�uft noch kein gamecode nur de map wird in den szene graphen geladen
	// um das menue anzuzeigen was etwas transparent angezeigt wird
	this->currentMap = new AllgaeuMap();
	this->currentMap->Init();
	this->m_zscene.AddPlacement(this->currentMap->GetRootPlacement());


	//Cont1.addCharacter(camaro.GetPlacement());
	//Cont1.addKeyboard(&keyboard);


	m_zscene.AddPlacement(&m_zpCamera);
	m_zscene.AddParallelLight(&m_zlight);
	m_zpCamera.AddCamera(&m_zcamera);
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Hier die Echtzeit-Ver�nderungen einf�gen:
	m_zroot.Tick(fTimeDelta);
	float res = fTimeDelta * 5;
	this->keyboard.PlaceWASD(this->m_zpCamera, res, true);
	//Cont1.Move(10 * fTimeDelta);
}

void CGame::Fini()
{
	// Hier die Finalisierung Deiner Vektoria-Objekte einf�gen:
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergr��e ver�ndert wurde.
	// Hier kannst Du dann die Aufl�sung des Viewports neu einstellen:

}

