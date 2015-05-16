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

	//skyBox
	m_zmSkybox.MakeTextureSky("textures\\Day_Skybox.jpg");
	m_zgSkybox.Init(20.0f, &m_zmSkybox, 1.0f, true);
	m_zpSkybox.TranslateY(19.0f);
	m_zpSkybox.AddGeo(&m_zgSkybox);

	m_zscene.AddPlacement(&m_zpSkybox);

	//Note(Peter): Ab hier kommt nun die Init. für die Häuser
	/*m_zgBigHouse.InitBigHouse();
	m_zgBigHouse.GetBigHousePlacement()->ScaleDelta(7.0f);
	m_zgBigHouse.GetBigHousePlacement()->TranslateXDelta(5.5f);
	m_zgBigHouse.GetBigHousePlacement()->TranslateZDelta(-6.0f);

	m_zgLittleHouse.InitLittleHouse();
	m_zgLittleHouse.GetLittleHousePlacement()->ScaleDelta(6.0f);
	m_zgLittleHouse.GetLittleHousePlacement()->RotateYDelta(0.0f);
	m_zgLittleHouse.GetLittleHousePlacement()->TranslateXDelta(1.0f);
	m_zgLittleHouse.GetLittleHousePlacement()->TranslateZDelta(-10.0f);

	m_zgBrewery.InitBrewery();
	m_zgBrewery.GetBreweryPlacement()->ScaleDelta(6.0f);
	m_zgBrewery.GetBreweryPlacement()->RotateYDelta(HALFPI-0.5);
	m_zgBrewery.GetBreweryPlacement()->TranslateXDelta(5.0f);
	m_zgBrewery.GetBreweryPlacement()->TranslateZDelta(-10.0f);

	m_zscene.AddPlacement(m_zgBigHouse.GetBigHousePlacement());
	m_zscene.AddPlacement(m_zgLittleHouse.GetLittleHousePlacement());
	m_zscene.AddPlacement(m_zgBrewery.GetBreweryPlacement());*/
	//Note(Peter): Aufruf der Autos
	/*m_zgPorsche.InitPorsche();
	m_zgPorsche.GetPlacement()->Scale(0.04f);
	m_zgPorsche.GetPlacement()->RotateYDelta(PI);
	m_zgPorsche.GetPlacement()->TranslateZDelta(-1.0f);
	m_zgPorsche.GetPlacement()->TranslateXDelta(2.7f);
	m_zgPorsche.GetPlacement()->TranslateYDelta(0.2f);

	m_zscene.AddPlacement(m_zgPorsche.GetPlacement());*/
	//Camaro
	m_zgCamaro.InitCamaro();
	m_zgCamaro.GetPlacement()->Scale(0.05f);
	m_zgCamaro.GetPlacement()->RotateYDelta(PI);
	m_zgCamaro.GetPlacement()->TranslateZDelta(-1.0f);
	m_zgCamaro.GetPlacement()->TranslateXDelta(3.0f);
	m_zgCamaro.GetPlacement()->TranslateYDelta(0.2f);

	m_zscene.AddPlacement(m_zgCamaro.GetPlacement());
	//Note(Peter): Aufruf Tree
	/*m_zgTree.InitTree();
	m_zgTree.GetPlacementTree()->Scale(0.2f);
	m_zgTree.GetPlacementTree()->TranslateXDelta(0.0f);
	m_zgTree.GetPlacementTree()->TranslateZDelta(0.0f);

	m_zgTreeBush.InitTreeBush();
	m_zgTreeBush.GetPlacementTree()->Scale(0.2f);
	m_zgTreeBush.GetPlacementTree()->TranslateXDelta(1.0f);
	m_zgTreeBush.GetPlacementTree()->TranslateZDelta(1.0f);

	m_zscene.AddPlacement(m_zgTree.GetPlacementTree());
	m_zscene.AddPlacement(m_zgTreeBush.GetPlacementTree());*/
	//Note(peter): Aufruf Track
	/*m_zgTrack.InitTrack();
	m_zgTrack.GetPlacement()->Scale(0.2f);
	m_zgTrack.GetPlacement()->TranslateYDelta(0.1f);

	m_zscene.AddPlacement(m_zgTrack.GetPlacement());*/
	//Note(peter): Ground
	m_zmGrass.MakeTextureDiffuse("textures\\Natur\\Gras_512.png");
	m_zgGround.Init(20.0f, 20.0f, &m_zmGrass,0.0f,0.0f,5.0f,5.0f);
	m_zpGround.AddGeo(&m_zgGround);
	m_zpGround.RotateX(-HALFPI);

	m_zscene.AddPlacement(&m_zpGround);
	//Note(peter): Ray
	m_zrRay.Init(CHVector(0, 1, -5), CHVector(0, -8, 0));
	
	if (m_zgGround.IsIntersecting(m_zrRay) == true){
		m_zgGround.SetMaterial(&m_zmSkybox);
	}


	//Note(Peter): Ende :)
	m_zroot.AddFrameHere(&m_zframe);
	m_zframe.AddViewport(&m_zviewport);
	m_zroot.AddScene(&m_zscene);

	m_zscene.AddPlacement(&m_zpCamera);
	m_zscene.AddParallelLight(&m_zlight);
	m_zpCamera.Translate(0.0f,0.5f,-3.0f);
	m_zpCamera.AddCamera(&m_zcamera);

	m_zviewport.SetBackfaceCullingOn();
}


void CGame::Tick(float fTime, float fTimeDelta)
{
	// Hier die Echtzeit-Veränderungen einfügen:
	m_zroot.Tick(fTimeDelta);
	float res = fTimeDelta * 5;
	this->keyboard.PlaceWASD(this->m_zpCamera, res, true);
	//m_zgCamaro.RotateFrontTiresX();
	//m_zgCamaro.RotateFrontTiresY(true);
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

