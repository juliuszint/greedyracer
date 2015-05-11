#include "StdAfx.h"
#include "Game.h"

// Todo (julius): neue engine herunterladen (bug mit leerem Szenegraphen gefixed)
// blender lieber als .obj exportieren und dann importieren 


CGame::CGame(void)
{
	//Hier eventuelle Vorinitialisierungen Deiner Vektoria-Objekte einfügen:
	
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
	this->worldMaterial.MakeTextureSpecular("textures\\mapReflection.jpg");
	this->worldMaterial.SetTextureGlowBlack();
	this->worldGeo->SetMaterial(&this->worldMaterial);
	this->worldGeo->MapPlanarY();
	this->m_zscene.AddPlacement(&worldPlacement);

	this->carMaterial.MakeTextureDiffuse("textures\\green_image.jpg");
	this->carGeo.Init(0.05f, &this->carMaterial, 50, 50);
	this->carPlacement.AddGeo(&this->carGeo);
	this->carPlacement.Translate(CHVector(0, 0.1, -3));
	this->m_zscene.AddPlacement(&this->carPlacement);

	//Note(Peter): Ab hier kommt nun die Init. für die Häuser
	m_zgBigHouse.InitBigHouse();
	m_zgBigHouse.GetBigHousePlacement()->ScaleDelta(1.0f);
	m_zgBigHouse.GetBigHousePlacement()->TranslateZDelta(-4.0f);

	m_zgLittleHouse.InitLittleHouse();
	m_zgLittleHouse.GetLittleHousePlacement()->ScaleDelta(1.0f);
	m_zgLittleHouse.GetLittleHousePlacement()->TranslateZDelta(-3.0f);

	m_zgBrewery.InitBrewery();
	m_zgBrewery.GetBreweryPlacement()->ScaleDelta(1.0f);
	m_zgBrewery.GetBreweryPlacement()->TranslateZDelta(-5.0f);

	m_zscene.AddPlacement(m_zgBigHouse.GetBigHousePlacement());
	m_zscene.AddPlacement(m_zgLittleHouse.GetLittleHousePlacement());
	m_zscene.AddPlacement(m_zgBrewery.GetBreweryPlacement());
	//Note(Peter): Ende der Init der Häuser
	//Note(Peter): Aufruf des Porschemeshes
	m_zgPorsche.InitPorsche();
	m_zgPorsche.GetPlacement()->Scale(0.1f);
	m_zgPorsche.GetPlacement()->TranslateZDelta(-5.0f);
	m_zgPorsche.GetPlacement()->TranslateXDelta(1.0f);
	m_zgPorsche.GetPlacement()->TranslateYDelta(0.3f);

	m_zscene.AddPlacement(m_zgPorsche.GetPlacement());
	//Camaro
	m_zgCamaro.InitCamaro();
	m_zgCamaro.GetPlacement()->Scale(0.1f);
	m_zgCamaro.GetPlacement()->RotateYDelta(HALFPI);
	m_zgCamaro.GetPlacement()->TranslateZDelta(-6.0f);
	m_zgCamaro.GetPlacement()->TranslateXDelta(2.0f);
	m_zgCamaro.GetPlacement()->TranslateYDelta(0.3f);

	m_zscene.AddPlacement(m_zgCamaro.GetPlacement());
	//Tree
	m_zgTree.InitTree();
	m_zgTree.GetPlacement()->Scale(0.5f);
	
	m_zscene.AddPlacement(m_zgTree.GetPlacement());
	//Track
	m_zgTrack.InitTrack();
	m_zgTrack.GetPlacement()->Scale(0.2f);
	m_zgTrack.GetPlacement()->TranslateYDelta(0.1f);


	m_zscene.AddPlacement(m_zgTrack.GetPlacement());

	m_zroot.AddFrameHere(&m_zframe);
	m_zframe.AddViewport(&m_zviewport);
	m_zroot.AddScene(&m_zscene);
	//m_zscene.AddPlacement(&m_zpSphere);

	m_zscene.AddPlacement(&m_zpCamera);
	m_zscene.AddParallelLight(&m_zlight);
	m_zpCamera.Translate(0.0f,0.5f,-3.0f);
	m_zpCamera.AddCamera(&m_zcamera);

	//m_zpSphere.Translate(CHVector(0, 0, -3));
	//m_zpSphere.AddGeo(&m_zgSphere);

	m_zviewport.SetBackfaceCullingOn();
}


void CGame::Tick(float fTime, float fTimeDelta)
{
	// Hier die Echtzeit-Veränderungen einfügen:
	m_zroot.Tick(fTimeDelta);
	float res = fTimeDelta * 5;
	this->keyboard.PlaceWASD(this->m_zpCamera, res, true);
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

