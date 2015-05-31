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

	m_zlight.Init(CHVector(1, 1, 0), CColor(1, 1, 1));

	////skyBox
	//m_zmSkybox.MakeTextureSky("textures\\Day_Skybox.jpg");
	//m_zgSkybox.Init(45.0f, &m_zmSkybox, 1.0f, true);
	//m_zpSkybox.TranslateY(19.0f);
	//m_zpSkybox.AddGeo(&m_zgSkybox);

	//m_zscene.AddPlacement(&m_zpSkybox);

	//Note(Peter): Ab hier kommt nun die Init. für die Häuser
	m_zgBigHouse.InitBigHouse();
	m_zgBigHouse.GetBigHousePlacement()->ScaleDelta(11.0f);
	m_zgBigHouse.GetBigHousePlacement()->RotateYDelta(PI + 0.35f);
	m_zgBigHouse.GetBigHousePlacement()->TranslateXDelta(13.0f);
	m_zgBigHouse.GetBigHousePlacement()->TranslateZDelta(-2.0f);

	m_zgBigHouse2.InitBigHouse();
	m_zgBigHouse2.GetBigHousePlacement()->ScaleDelta(11.0f);
	m_zgBigHouse2.GetBigHousePlacement()->RotateYDelta(HALFPI+0.5f);
	m_zgBigHouse2.GetBigHousePlacement()->TranslateXDelta(14.0f);
	m_zgBigHouse2.GetBigHousePlacement()->TranslateZDelta(2.0f);

	m_zgBigHouse3.InitBigHouse();
	m_zgBigHouse3.GetBigHousePlacement()->ScaleDelta(11.0f);
	m_zgBigHouse3.GetBigHousePlacement()->RotateYDelta(HALFPI-0.9f);
	m_zgBigHouse3.GetBigHousePlacement()->TranslateXDelta(5.0f);
	m_zgBigHouse3.GetBigHousePlacement()->TranslateZDelta(3.0f);

	m_zgBigHouse4.InitBigHouse();
	m_zgBigHouse4.GetBigHousePlacement()->ScaleDelta(11.0f);
	m_zgBigHouse4.GetBigHousePlacement()->RotateYDelta(HALFPI - 0.5f);
	m_zgBigHouse4.GetBigHousePlacement()->TranslateXDelta(6.0f);
	m_zgBigHouse4.GetBigHousePlacement()->TranslateZDelta(-4.5f);

	m_zgLittleHouse.InitLittleHouse();
	m_zgLittleHouse.GetLittleHousePlacement()->ScaleDelta(11.0f);
	m_zgLittleHouse.GetLittleHousePlacement()->RotateYDelta(HALFPI - 0.5f);
	m_zgLittleHouse.GetLittleHousePlacement()->TranslateXDelta(8.0f);
	m_zgLittleHouse.GetLittleHousePlacement()->TranslateZDelta(-8.0f);

	m_zgLittleHouse2.InitLittleHouse();
	m_zgLittleHouse2.GetLittleHousePlacement()->ScaleDelta(11.0f);
	m_zgLittleHouse2.GetLittleHousePlacement()->RotateYDelta(HALFPI);
	m_zgLittleHouse2.GetLittleHousePlacement()->TranslateXDelta(10.0f);
	m_zgLittleHouse2.GetLittleHousePlacement()->TranslateZDelta(5.0f);

	m_zgLittleHouse3.InitLittleHouse();
	m_zgLittleHouse3.GetLittleHousePlacement()->ScaleDelta(11.0f);
	m_zgLittleHouse3.GetLittleHousePlacement()->RotateYDelta(HALFPI - 0.5f);
	m_zgLittleHouse3.GetLittleHousePlacement()->TranslateXDelta(4.0f);
	m_zgLittleHouse3.GetLittleHousePlacement()->TranslateZDelta(-1.0f);

	m_zgBrewery.InitBrewery();
	m_zgBrewery.GetBreweryPlacement()->ScaleDelta(10.0f);
	m_zgBrewery.GetBreweryPlacement()->RotateYDelta(PI-0.15f);
	m_zgBrewery.GetBreweryPlacement()->TranslateXDelta(12.0f);
	m_zgBrewery.GetBreweryPlacement()->TranslateZDelta(-8.0f);

	m_zscene.AddPlacement(m_zgBigHouse.GetBigHousePlacement());
	m_zscene.AddPlacement(m_zgBigHouse2.GetBigHousePlacement());
	m_zscene.AddPlacement(m_zgBigHouse3.GetBigHousePlacement());
	m_zscene.AddPlacement(m_zgBigHouse4.GetBigHousePlacement());
	m_zscene.AddPlacement(m_zgLittleHouse.GetLittleHousePlacement());
	m_zscene.AddPlacement(m_zgLittleHouse2.GetLittleHousePlacement());
	m_zscene.AddPlacement(m_zgLittleHouse3.GetLittleHousePlacement());
	m_zscene.AddPlacement(m_zgBrewery.GetBreweryPlacement());
	//Note(Peter): Aufruf Tree
	m_zgTree.InitTree();
	m_zgTree.GetPlacementTree()->Scale(0.2f);
	m_zgTree.GetPlacementTree()->TranslateXDelta(12.0f);
	m_zgTree.GetPlacementTree()->TranslateZDelta(1.0f);

	m_zgTree2.InitTree();
	m_zgTree2.GetPlacementTree()->Scale(0.2f);
	m_zgTree2.GetPlacementTree()->TranslateXDelta(8.0f);
	m_zgTree2.GetPlacementTree()->TranslateZDelta(-1.0f);

	m_zgTree3.InitTree();
	m_zgTree3.GetPlacementTree()->Scale(0.2f);
	m_zgTree3.GetPlacementTree()->TranslateXDelta(7.0f);
	m_zgTree3.GetPlacementTree()->TranslateZDelta(2.0f);

	m_zgTree4.InitTree();
	m_zgTree4.GetPlacementTree()->Scale(0.2f);
	m_zgTree4.GetPlacementTree()->TranslateXDelta(8.0f);
	m_zgTree4.GetPlacementTree()->TranslateZDelta(5.0f);

	m_zgTreeRound.InitTreeRound();
	m_zgTreeRound.GetPlacementTree()->Scale(0.2f);
	m_zgTreeRound.GetPlacementTree()->TranslateXDelta(14.0f);
	m_zgTreeRound.GetPlacementTree()->TranslateZDelta(4.5f);

	m_zgTreeBush.InitTreeBush();
	m_zgTreeBush.GetPlacementTree()->Scale(0.2f);
	m_zgTreeBush.GetPlacementTree()->TranslateXDelta(17.0f);
	m_zgTreeBush.GetPlacementTree()->TranslateZDelta(3.0f);

	m_zscene.AddPlacement(m_zgTree.GetPlacementTree());
	m_zscene.AddPlacement(m_zgTree2.GetPlacementTree());
	m_zscene.AddPlacement(m_zgTree3.GetPlacementTree());
	m_zscene.AddPlacement(m_zgTree4.GetPlacementTree());
	m_zscene.AddPlacement(m_zgTreeRound.GetPlacementTree());
	m_zscene.AddPlacement(m_zgTreeBush.GetPlacementTree());
	//Note(peter): Aufruf Track
	m_zgTrack.InitTrack();
	m_zgTrack.GetPlacement()->TranslateXDelta(3.0f);
	m_zgTrack.GetPlacement()->TranslateYDelta(0.1f);
	m_zgTrack.GetPlacement()->TranslateZDelta(-3.0f);

	m_zscene.AddPlacement(m_zgTrack.GetPlacement());
	//Note(Peter): Aufruf der Autos
	//m_zgPorsche.InitPorsche();
	//m_zgPorsche.GetPlacement()->Scale(0.04f);
	//m_zgPorsche.GetPlacement()->RotateYDelta(PI);
	//m_zgPorsche.GetPlacement()->TranslateZDelta(-1.0f);
	//m_zgPorsche.GetPlacement()->TranslateXDelta(2.7f);
	//m_zgPorsche.GetPlacement()->TranslateYDelta(0.2f);

	//m_zscene.AddPlacement(m_zgPorsche.GetPlacement());
	//Camaro
	/*m_zgCamaro.InitCamaro();
	m_zgCamaro.GetPlacement()->Scale(0.06f);
	m_zgCamaro.GetPlacement()->RotateYDelta(HALFPI);
	m_zgCamaro.GetPlacement()->TranslateZDelta(-4.0f);
	m_zgCamaro.GetPlacement()->TranslateXDelta(0.0f);
	m_zgCamaro.GetPlacement()->TranslateYDelta(0.2f);

	m_zscene.AddPlacement(m_zgCamaro.GetPlacement());*/
	//Note(peter): Ground
	m_zmGrass.MakeTextureDiffuse("textures\\Natur\\Gras_512.png");
	m_zgGround.Init(45.0f, 45.0f, &m_zmGrass,0.0f,0.0f,5.0f,5.0f);
	m_zpGround.AddGeo(&m_zgGround);
	m_zpGround.RotateX(-HALFPI);

	m_zscene.AddPlacement(&m_zpGround);
	//Note(peter): Ray
	/*m_zrRay.Init(CHVector(0, 1, -5, 1), CHVector(0, -1, 0,0));
	
	if (m_zgGround.IsIntersecting(m_zrRay) == true){
		m_zgGround.SetMaterial(&m_zmSkybox);
	}*/


	//Note(Peter): Ende :)
	m_zroot.AddFrameHere(&m_zframe);
	m_zframe.AddViewport(&m_zviewport);
	m_zroot.AddScene(&m_zscene);

	m_zscene.AddPlacement(&m_zpCamera);
	m_zscene.AddParallelLight(&m_zlight);
	m_zpCamera.Translate(12.0f,0.5f,10.0f);
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

