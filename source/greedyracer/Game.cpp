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

	m_zlight.Init(CHVector(0, 1, 0), CColor(1, 1, 1));

	//m_zgSphere.Init(1.1F, &m_zm, 20, 20);
	//m_zm.MakeTextureGlow("textures\\earth.jpg");

	// Note(julius): mit der neusten blender version (2.47) funktioniert der import nicht!
	// mit der version (2.59) scheint alles zu klappen
	this->worldGeo = this->importer.LoadGeo("..\\..\\models\\map.obj");
	this->worldPlacement.AddGeo(this->worldGeo);
	this->worldGeo->ReduceRedundancy();
	this->worldPlacement.Translate(CHVector(0, 0, -3));
	this->worldMaterial.MakeTextureDiffuse("textures\\mapTexture.jpg");
	this->worldMaterial.SetTextureGlowBlack();
	this->worldGeo->SetMaterial(&this->worldMaterial);
	this->worldGeo->MapPlanarY();
	this->m_zscene.AddPlacement(&worldPlacement);

	this->carMaterial.MakeTextureDiffuse("textures\\green_image.jpg");
	this->carGeo.Init(0.05f, &this->carMaterial, 50, 50);
	this->carPlacement.AddGeo(&this->carGeo);
	this->carPlacement.Translate(CHVector(0, 0.1, -3));
	this->m_zscene.AddPlacement(&this->carPlacement);

	m_zroot.AddFrameHere(&m_zframe);
	m_zframe.AddViewport(&m_zviewport);
	m_zroot.AddScene(&m_zscene);
	//m_zscene.AddPlacement(&m_zpSphere);

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
	this->keyboard.PlaceWASD(this->m_zpCamera, res);
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

