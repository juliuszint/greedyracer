#include "Brewery.h"

void CBrewery::Init(){
	//Brewery
	m_zmFacade.MakeTextureDiffuse("textures\\haus\\Fassade_512.png");
	m_zmFacade.MakeTextureBump("textures\\haus\\Fassade_512_n.png");
	m_zmRoof.MakeTextureDiffuse("textures\\haus\\Dachziegel_Rot_512.png");
	m_zmRoof.MakeTextureBump("textures\\haus\\Dachziegel_Rot_512_n.png");

	m_zmFacade.SetBumpStrength(7.0f);
	m_zmRoof.SetBumpStrength(5.0f);
	m_zgBrewery.SetTextureRepeat(4.0f, 1.0f);

	m_zgBrewery.SetMaterialFacade(&m_zmFacade);
	m_zgBrewery.SetMaterialRoof(&m_zmRoof);
	m_zgBrewery.SetMaterialCeiling(&m_zmFacade);

	m_zgDoor.InitRoman(CFloatRect(1.0f, 0.0f, 1.5f, 1.2f), true);
	m_zgBrewery.AddGeoWindow(&m_zgDoor, 0);
	m_zgDoor.HideBottom();

	m_zgBrewery.OpenSesamy("P@VGSVAABSC");
	m_zgBrewery.SetSizeRect(5.0f, 12.0f, 2.0f);
	m_zgBrewery.InitRectSaddle();
	m_zpBrewery.AddGeo(&m_zgBrewery);
	m_zpBrewery.Scale(0.05f);
	//BreweryTower
	m_zmFacadeTower.MakeTextureDiffuse("textures\\sonstiges\\Metall_256.png");
	m_zmFacadeTower.MakeTextureBump("textures\\sonstiges\\Metall_256_n.png");
	m_zmRoofTower.MakeTextureDiffuse("textures\\sonstiges\\Metall_256.png");
	m_zmRoofTower.MakeTextureBump("textures\\sonstiges\\Metall_256_n.png");

	m_zmFacadeTower.SetBumpStrength(7.0f);
	m_zmRoofTower.SetBumpStrength(5.0f);
	m_zgTower.SetTextureRepeat(10.0f, 5.0f);

	m_zgTower.SetMaterialFacade(&m_zmFacadeTower);
	m_zgTower.SetMaterialRoof(&m_zmRoofTower);

	m_zgTower.OpenSesamy("P@VGSVAABSC");
	m_zgTower.SetSizeTower(1.0f, 6.0f);
	m_zgTower.SetHeightRoof(0.0f);
	m_zgTower.InitRoundTower();
	m_zpTower.AddGeo(&m_zgTower);
	m_zpTower.Scale(0.05f);
	m_zpTower.TranslateZDelta(0.1f);
	m_zpTower.TranslateXDelta(-0.2f);
	//BreweryTower2
	m_zpTower2.AddGeo(&m_zgTower);
	m_zpTower2.Scale(0.05f);
	m_zpTower2.TranslateXDelta(-0.2f);
	//BrewerySupply
	m_zmFacadeSupply.MakeTextureDiffuse("textures\\sonstiges\\Metall_256.png");
	m_zmFacadeSupply.MakeTextureBump("textures\\sonstiges\\Metall_256_n.png");
	m_zmFacadeSupply.SetBumpStrength(7.0f);

	m_zgSupply.SetMaterial(&m_zmFacadeSupply);
	m_zgSupply.SetTextureRepeat(1.0f, 6.0f);
	m_zgSupply.SetTextureRepeat(1.0f, 6.0f);

	m_zgSupply.InitArc(0.9f, 1.0f, 10.0f, HALFPI, &m_zmFacadeSupply);
	m_zpSupply.AddGeo(&m_zgSupply);
	m_zpSupply.Scale(0.01f);
	m_zpSupply.RotateZDelta(PI);
	m_zpSupply.TranslateZDelta(0.15f);
	m_zpSupply.TranslateXDelta(-0.1f);
	m_zpSupply.TranslateYDelta(0.055f);
	//BrewerySupply2
	m_zpSupply2.AddGeo(&m_zgSupply);
	m_zpSupply2.Scale(0.01f);
	m_zpSupply2.RotateZDelta(PI);
	m_zpSupply2.TranslateZDelta(0.15f);
	m_zpSupply2.TranslateXDelta(-0.1f);
	m_zpSupply2.TranslateYDelta(0.02f);
	//BreweryChimney
	m_zmFacadeChimney.MakeTextureDiffuse("textures\\brickwall_notFinal.jpg");
	m_zmFacadeChimney.MakeTextureBump("textures\\brickwall_Bump_notFinal.jpg");
	m_zmFacadeChimney.SetBumpStrength(7.0f);

	m_zgChimney.SetMaterial(&m_zmFacadeChimney);
	m_zgChimney.SetTextureRepeat(1.0f, 6.0f);
	m_zgChimney.SetTextureRepeat(1.0f, 6.0f);

	m_zgChimney.InitTubeSine(3.0f, 1.5f, 40.0f, 0.5f, &m_zmFacadeChimney);
	m_zpChimney.AddGeo(&m_zgChimney);
	m_zpChimney.Scale(0.01f);
	m_zpChimney.TranslateXDelta(0.07f);
	m_zpChimney.TranslateZDelta(0.2f);

	//BreweryManage
	m_zpAllPlacements.AddPlacement(&m_zpBrewery);
	m_zpAllPlacements.AddPlacement(&m_zpTower);
	m_zpAllPlacements.AddPlacement(&m_zpTower2);
	m_zpAllPlacements.AddPlacement(&m_zpSupply);
	m_zpAllPlacements.AddPlacement(&m_zpSupply2);
	m_zpAllPlacements.AddPlacement(&m_zpChimney);

	/*m_zpAllPlacements.Scale(1.4f);
	m_zpAllPlacements.RotateYDelta(HALFPI / 1.5f);
	m_zpAllPlacements.TranslateXDelta(1.9f);
	m_zpAllPlacements.TranslateZDelta(-6.6f);*/

}
CPlacement* CBrewery::GetRootPlacement(){
	return &m_zpAllPlacements;
}
