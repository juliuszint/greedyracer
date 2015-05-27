#include "StdAfx.h"
#include "Game.h"

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
	// Hier die Initialisierung Deiner Vektoria-Objekte einfügen:
	m_zroot.Init(psplash);
	m_zcamera.Init();
	m_zframe.Init(hwnd, eApiRender_DirectX11_Shadermodel50);
	m_zviewport.InitFull(&m_zcamera);
	m_zframe.AddDeviceKeyboard(&this->keyboard);
	this->keyboard.SetWASDTranslationSensitivity(20);

	m_zlight.Init(CHVector(0, 1, 0), CColor(1, 1, 1));

	//m_zgSphere.Init(1.1F, &m_zm, 20, 20);
	//m_zm.MakeTextureGlow("textures\\earth.jpg");

	// Note(julius): mit der neusten blender version (2.47) funktioniert der import nicht!
	// mit der version (2.59) scheint alles zu klappen
	this->ground.Init(10, 10, 20, 20);
	this->track.InitTrack();
	this->camaro.InitCamaro();
	
	this->groundPlacement = this->ground.GetPlacement();
	this->trackPlacment = this->track.GetPlacement(); 
	this->camaroPlacment = this->camaro.GetPlacement();

	this->m_zpCamera.TranslateDelta(50, 30, 50);
	this->trackPlacment->TranslateDelta(CHVector(80, 0.01, 80));
	this->camaroPlacment->TranslateDelta(CHVector(40, 2, 30));

	this->m_zscene.AddPlacement(this->camaroPlacment);
	this->m_zscene.AddPlacement(this->groundPlacement);
	this->m_zscene.AddPlacement(this->trackPlacment);

	m_zroot.AddFrameHere(&m_zframe);
	m_zframe.AddViewport(&m_zviewport);
	m_zroot.AddScene(&m_zscene);
	//m_zscene.AddPlacement(&m_zpSphere);

	Cont1.addCharacter(camaro.GetPlacement());
	Cont1.addKeyboard(&keyboard);
//	camaro.addVehicle(&VCamaro);
	Cont1.setKeybinding(DIK_U, DIK_J, DIK_H, DIK_K);


	m_zscene.AddPlacement(&m_zpCamera);
	m_zscene.AddParallelLight(&m_zlight);
	m_zpCamera.AddCamera(&m_zcamera);
	
	//m_zpSphere.Translate(CHVector(0, 0, -3));
	//m_zpSphere.AddGeo(&m_zgSphere);
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Hier die Echtzeit-Veränderungen einfügen:
	m_zroot.Tick(fTimeDelta);
	float res = fTimeDelta * 5;
	this->keyboard.PlaceWASD(this->m_zpCamera, res, true);
	Cont1.Move(10 * fTimeDelta);
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

