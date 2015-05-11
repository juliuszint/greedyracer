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

	
	////Note(Peter): Ab hier kommt nun die Init. für die Häuser
	////House1
	m_zmFacadeH1.MakeTextureDiffuse("textures\\brickwall_notFinal.jpg");
	m_zmFacadeH1.MakeTextureBump("textures\\brickwall_Bump_notFinal.jpg");
	m_zmRoofH1.MakeTextureDiffuse("textures\\dachplatten_notFinal.jpg");
	m_zmRoofH1.MakeTextureBump("textures\\dachplatten_Bump_notFinal.jpg");

	m_zmFacadeH1.SetBumpStrength(7.0f);
	m_zmRoofH1.SetBumpStrength(5.0f);
	m_zgHouseH1.SetTextureRepeat(10.0f, 5.0f);

	m_zgHouseH1.SetMaterialFacade(&m_zmFacadeH1);
	m_zgHouseH1.SetMaterialRoof(&m_zmRoofH1);
	m_zgHouseH1.SetMaterialCeiling(&m_zmFacadeH1);

	m_zgHouseH1.OpenSesamy("P@VGSVAABSC");
	m_zgHouseH1.SetSizeRect(5.0f, 10.0f, 2.0f);
	m_zgHouseH1.SetHeightRoof(1.5f);
	m_zgHouseH1.SetOverroof(0.0f, 0.0f);
	m_zgHouseH1.InitRectSaddle();

	m_zpHouseH1.AddGeo(&m_zgHouseH1);
	//m_zscene.AddPlacement(&m_zpHouseH1);
	m_zpHouseH1.Scale(0.08f);
	m_zpHouseH1.RotateYDelta(-0.88f);
	m_zpHouseH1.TranslateXDelta(1.0f);
	m_zpHouseH1.TranslateZDelta(-5.8f);
	//House2
	m_zmFacadeH2.MakeTextureDiffuse("textures\\brickwall_notFinal.jpg");
	m_zmFacadeH2.MakeTextureBump("textures\\brickwall_Bump_notFinal.jpg");
	m_zmRoofH2.MakeTextureDiffuse("textures\\dachplatten_notFinal.jpg");
	m_zmRoofH2.MakeTextureBump("textures\\dachplatten_Bump_notFinal.jpg");

	m_zmFacadeH2.SetBumpStrength(7.0f);
	m_zmRoofH2.SetBumpStrength(5.0f);
	m_zgHouseH2.SetTextureRepeat(10.0f, 5.0f);

	m_zgHouseH2.SetMaterialFacade(&m_zmFacadeH2);
	m_zgHouseH2.SetMaterialRoof(&m_zmRoofH2);
	m_zgHouseH2.SetMaterialCeiling(&m_zmFacadeH2);

	m_zgHouseH2.OpenSesamy("P@VGSVAABSC");
	m_zgHouseH2.SetSizeRect(5.0f, 5.0f, 2.0f);
	m_zgHouseH2.SetDepthMans(1.0f);
	m_zgHouseH2.SetHeightRoof(0.7f);
	m_zgHouseH2.SetOverroof(0.2f, 0.0f);
	m_zgHouseH2.InitRectMans();
	
	m_zpHouseH2.AddGeo(&m_zgHouseH2);
	//m_zscene.AddPlacement(&m_zpHouseH2);
	m_zpHouseH2.Scale(0.08f);
	m_zpHouseH2.TranslateZDelta(-5.5f);
	m_zpHouseH2.TranslateXDelta(2.2f);
	//Brewery
	m_zmFacadeBrewery.MakeTextureDiffuse("textures\\brickwall_notFinal.jpg");
	m_zmFacadeBrewery.MakeTextureBump("textures\\brickwall_Bump_notFinal.jpg");
	m_zmRoofBrewery.MakeTextureDiffuse("textures\\dachplatten_notFinal.jpg");
	m_zmRoofBrewery.MakeTextureBump("textures\\dachplatten_Bump_notFinal.jpg");

	m_zmFacadeBrewery.SetBumpStrength(7.0f);
	m_zmRoofBrewery.SetBumpStrength(5.0f);
	m_zgBrewery.SetTextureRepeat(10.0f, 5.0f);

	m_zgBrewery.SetMaterialFacade(&m_zmFacadeBrewery);
	m_zgBrewery.SetMaterialRoof(&m_zmRoofBrewery);
	m_zgBrewery.SetMaterialCeiling(&m_zmFacadeBrewery);

	m_zgBreweryDoor.InitRoman(CFloatRect(1.0f, 0.0f, 1.5f, 1.2f), true);
	m_zgBrewery.AddGeoWindow(&m_zgBreweryDoor, 0);
	m_zgBreweryDoor.HideBottom();

	m_zgBrewery.OpenSesamy("P@VGSVAABSC");
	m_zgBrewery.SetSizeRect(5.0f, 12.0f, 2.0f);
	m_zgBrewery.InitRectSaddle();
	m_zpBrewery.AddGeo(&m_zgBrewery);
	m_zpBrewery.Scale(0.05f);
	//BreweryTower
	m_zmFacadeBreweryTower.MakeTextureDiffuse("textures\\brickwall_notFinal.jpg");
	m_zmFacadeBreweryTower.MakeTextureBump("textures\\brickwall_Bump_notFinal.jpg");
	m_zmRoofBreweryTower.MakeTextureDiffuse("textures\\dachplatten_notFinal.jpg");
	m_zmRoofBreweryTower.MakeTextureBump("textures\\dachplatten_Bump_notFinal.jpg");

	m_zmFacadeBreweryTower.SetBumpStrength(7.0f);
	m_zmRoofBreweryTower.SetBumpStrength(5.0f);
	m_zgBreweryTower.SetTextureRepeat(10.0f, 5.0f);

	m_zgBreweryTower.SetMaterialFacade(&m_zmFacadeBreweryTower);
	m_zgBreweryTower.SetMaterialRoof(&m_zmRoofBreweryTower);

	m_zgBreweryTower.OpenSesamy("P@VGSVAABSC");
	m_zgBreweryTower.SetSizeTower(1.0f, 6.0f);
	m_zgBreweryTower.SetHeightRoof(0.0f);
	m_zgBreweryTower.InitRoundTower();
	m_zpBreweryTower.AddGeo(&m_zgBreweryTower);
	m_zpBreweryTower.Scale(0.05f);
	m_zpBreweryTower.TranslateZDelta(0.1f);
	m_zpBreweryTower.TranslateXDelta(-0.2f);
	//BreweryTower2
	m_zpBreweryTower2.AddGeo(&m_zgBreweryTower);
	m_zpBreweryTower2.Scale(0.05f);
	m_zpBreweryTower2.TranslateXDelta(-0.2f);
	//BrewerySupply
	m_zmFacadeBrewerySupply.MakeTextureDiffuse("textures\\brickwall_notFinal.jpg");
	m_zmFacadeBrewerySupply.MakeTextureBump("textures\\brickwall_Bump_notFinal.jpg");
	m_zmFacadeBrewerySupply.SetBumpStrength(7.0f);

	m_zgBrewerySupply.SetMaterial(&m_zmFacadeBrewerySupply);
	m_zgBrewerySupply.SetTextureRepeat(1.0f, 6.0f);
	m_zgBrewerySupply.SetTextureRepeat(1.0f, 6.0f);

	m_zgBrewerySupply.InitArc(0.9f, 1.0f, 10.0f, HALFPI, &m_zmFacadeBrewerySupply);
	m_zpBrewerySupply.AddGeo(&m_zgBrewerySupply);
	m_zpBrewerySupply.Scale(0.01f);
	m_zpBrewerySupply.RotateZDelta(PI);
	m_zpBrewerySupply.TranslateZDelta(0.15f);
	m_zpBrewerySupply.TranslateXDelta(-0.1f);
	m_zpBrewerySupply.TranslateYDelta(0.055f);
	//BrewerySupply2
	m_zpBrewerySupply2.AddGeo(&m_zgBrewerySupply);
	m_zpBrewerySupply2.Scale(0.01f);
	m_zpBrewerySupply2.RotateZDelta(PI);
	m_zpBrewerySupply2.TranslateZDelta(0.15f);
	m_zpBrewerySupply2.TranslateXDelta(-0.1f);
	m_zpBrewerySupply2.TranslateYDelta(0.02f);
	//BreweryChimney
	m_zmFacadeBreweryChimney.MakeTextureDiffuse("textures\\brickwall_notFinal.jpg");
	m_zmFacadeBreweryChimney.MakeTextureBump("textures\\brickwall_Bump_notFinal.jpg");
	m_zmFacadeBreweryChimney.SetBumpStrength(7.0f);

	m_zgBreweryChimney.SetMaterial(&m_zmFacadeBreweryChimney);
	m_zgBreweryChimney.SetTextureRepeat(1.0f, 6.0f);
	m_zgBreweryChimney.SetTextureRepeat(1.0f, 6.0f);

	m_zgBreweryChimney.InitTubeSine(3.0f, 1.5f, 40.0f, 0.5f, &m_zmFacadeBreweryChimney);
	m_zpBreweryChimney.AddGeo(&m_zgBreweryChimney);
	m_zpBreweryChimney.Scale(0.01f);
	m_zpBreweryChimney.TranslateXDelta(0.07f);
	m_zpBreweryChimney.TranslateZDelta(0.2f);

	//BreweryManage
	m_zpBreweryAll.AddPlacement(&m_zpBrewery);
	m_zpBreweryAll.AddPlacement(&m_zpBreweryTower);
	m_zpBreweryAll.AddPlacement(&m_zpBreweryTower2);
	m_zpBreweryAll.AddPlacement(&m_zpBrewerySupply);
	m_zpBreweryAll.AddPlacement(&m_zpBrewerySupply2);
	m_zpBreweryAll.AddPlacement(&m_zpBreweryChimney);

	m_zpBreweryAll.Scale(1.4f);
	m_zpBreweryAll.RotateYDelta(HALFPI/1.5f);
	m_zpBreweryAll.TranslateXDelta(1.9f);
	m_zpBreweryAll.TranslateZDelta(-6.6f);

	//ManageAllHouses
	m_zpAllHouses.AddPlacement(&m_zpHouseH1);
	m_zpAllHouses.AddPlacement(&m_zpHouseH2);
	m_zpAllHouses.AddPlacement(&m_zpBreweryAll);

	//m_zpAllHouses.(1.4f);
	m_zscene.AddPlacement(&m_zpAllHouses);
	/*m_zpBrewery.InitBrewery();
	m_zscene.AddPlacement(&m_zpBrewery.GetBreweryPlacement());*/
	//Note(Peter): Ende der Init der Häuser

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

