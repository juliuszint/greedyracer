#include "Landscape.h"


CLandscape::CLandscape()
{
}


CLandscape::~CLandscape()
{
}

void CLandscape::Init()
{
	m_pzgLandscape = m_zgLandscape.LoadGeo("meshes\\enviroment\\Landscape_reduced.obj");
	m_pzgTreeFir = m_zgTreeFir.LoadGeo("meshes\\enviroment\\Landscape_TreeFir_reduced.obj");
	m_pzgTreeRound = m_zgTreeRound.LoadGeo("meshes\\enviroment\\Landscape_TreeRound_reduced.obj");
	m_pzgTreeBobblig = m_zgTreeBobblig.LoadGeo("meshes\\enviroment\\Landscape_TreeBobblig_reduced.obj");
	m_pzgTreeLog = m_zgTreeLog.LoadGeo("meshes\\enviroment\\Landscape_Log_reduced.obj");

	m_zmLandscape.MakeTextureDiffuse("textures\\allgaeumap\\landscape\\Landscape_4098.jpg");
	m_zmLandscape.MakeTextureSpecular("textures\\allgaeumap\\landscape\\Landscape_4098_spec.jpg");
	m_zmTreeFir.MakeTextureDiffuse("textures\\allgaeumap\\landscape\\Tanne_512.jpg");
	m_zmTreeFir.MakeTextureSpecular("textures\\allgaeumap\\landscape\\Tanne_512_spec.jpg");
	m_zmTreeRound.MakeTextureDiffuse("textures\\allgaeumap\\landscape\\Lolli_Baum_512.jpg");
	m_zmTreeRound.MakeTextureSpecular("textures\\allgaeumap\\landscape\\Lolli_Baum_512_spec.jpg");
	m_zmTreeBobblig.MakeTextureDiffuse("textures\\allgaeumap\\landscape\\Baum_512.jpg");
	m_zmTreeBobblig.MakeTextureSpecular("textures\\allgaeumap\\landscape\\Baum_512_spec.jpg");
	m_zmTreeLog.MakeTextureDiffuse("textures\\allgaeumap\\landscape\\Holz_512.jpg");
	m_zmTreeLog.MakeTextureSpecular("textures\\allgaeumap\\landscape\\Holz_512_spec.jpg");

	m_pzgLandscape->SetMaterial(&m_zmLandscape);
	m_pzgTreeFir->SetMaterial(&m_zmTreeFir);
	m_pzgTreeRound->SetMaterial(&m_zmTreeRound);
	m_pzgTreeBobblig->SetMaterial(&m_zmTreeBobblig);
	m_pzgTreeLog->SetMaterial(&m_zmTreeLog);

	m_zpLandscape.AddGeo(m_pzgLandscape);
	m_zpTreeFir.AddGeo(m_pzgTreeFir);
	m_zpTreeRound.AddGeo(m_pzgTreeRound);
	m_zpTreeBobblig.AddGeo(m_pzgTreeBobblig);
	m_zpTreeLog.AddGeo(m_pzgTreeLog);

	m_zgBigHouse.Init();
	m_zgBigHouse.GetRootPlacement()->ScaleDelta(11.0f);
	m_zgBigHouse.GetRootPlacement()->RotateYDelta(PI + 0.35f);
	m_zgBigHouse.GetRootPlacement()->TranslateXDelta(10.0f);
	m_zgBigHouse.GetRootPlacement()->TranslateZDelta(1.0f);

	m_zgBigHouse2.Init();
	m_zgBigHouse2.GetRootPlacement()->ScaleDelta(11.0f);
	m_zgBigHouse2.GetRootPlacement()->RotateYDelta(HALFPI + 0.5f);
	m_zgBigHouse2.GetRootPlacement()->TranslateXDelta(11.0f);
	m_zgBigHouse2.GetRootPlacement()->TranslateZDelta(5.0f);

	m_zgBigHouse3.Init();
	m_zgBigHouse3.GetRootPlacement()->ScaleDelta(11.0f);
	m_zgBigHouse3.GetRootPlacement()->RotateYDelta(HALFPI - 0.9f);
	m_zgBigHouse3.GetRootPlacement()->TranslateXDelta(2.0f);
	m_zgBigHouse3.GetRootPlacement()->TranslateZDelta(6.0f);

	m_zgBigHouse4.Init();
	m_zgBigHouse4.GetRootPlacement()->ScaleDelta(11.0f);
	m_zgBigHouse4.GetRootPlacement()->RotateYDelta(HALFPI - 0.5f);
	m_zgBigHouse4.GetRootPlacement()->TranslateXDelta(3.0f);
	m_zgBigHouse4.GetRootPlacement()->TranslateZDelta(-1.5f);

	m_zgLittleHouse.Init();
	m_zgLittleHouse.GetRootPlacement()->ScaleDelta(11.0f);
	m_zgLittleHouse.GetRootPlacement()->RotateYDelta(HALFPI - 0.5f);
	m_zgLittleHouse.GetRootPlacement()->TranslateXDelta(5.0f);
	m_zgLittleHouse.GetRootPlacement()->TranslateZDelta(-5.0f);

	m_zgLittleHouse2.Init();
	m_zgLittleHouse2.GetRootPlacement()->ScaleDelta(11.0f);
	m_zgLittleHouse2.GetRootPlacement()->RotateYDelta(HALFPI);
	m_zgLittleHouse2.GetRootPlacement()->TranslateXDelta(7.0f);
	m_zgLittleHouse2.GetRootPlacement()->TranslateZDelta(8.0f);

	m_zgLittleHouse3.Init();
	m_zgLittleHouse3.GetRootPlacement()->ScaleDelta(11.0f);
	m_zgLittleHouse3.GetRootPlacement()->RotateYDelta(HALFPI - 0.5f);
	m_zgLittleHouse3.GetRootPlacement()->TranslateXDelta(1.0f);
	m_zgLittleHouse3.GetRootPlacement()->TranslateZDelta(2.0f);

	m_zgBrewery.Init();
	m_zgBrewery.GetRootPlacement()->ScaleDelta(10.0f);
	m_zgBrewery.GetRootPlacement()->RotateYDelta(PI - 0.15f);
	m_zgBrewery.GetRootPlacement()->TranslateXDelta(9.0f);
	m_zgBrewery.GetRootPlacement()->TranslateZDelta(-5.0f);


	m_zpOverallPlacement.AddPlacement(&m_zpLandscape);
	m_zpOverallPlacement.AddPlacement(&m_zpTreeFir);
	m_zpOverallPlacement.AddPlacement(&m_zpTreeRound);
	m_zpOverallPlacement.AddPlacement(&m_zpTreeBobblig);
	m_zpOverallPlacement.AddPlacement(&m_zpTreeLog);
	m_zpOverallPlacement.AddPlacement(m_zgBigHouse.GetRootPlacement());
	m_zpOverallPlacement.AddPlacement(m_zgBigHouse2.GetRootPlacement());
	m_zpOverallPlacement.AddPlacement(m_zgBigHouse3.GetRootPlacement());
	m_zpOverallPlacement.AddPlacement(m_zgBigHouse4.GetRootPlacement());
	m_zpOverallPlacement.AddPlacement(m_zgLittleHouse.GetRootPlacement());
	m_zpOverallPlacement.AddPlacement(m_zgLittleHouse2.GetRootPlacement());
	m_zpOverallPlacement.AddPlacement(m_zgLittleHouse3.GetRootPlacement());
	m_zpOverallPlacement.AddPlacement(m_zgBrewery.GetRootPlacement());


	m_zpOverallPlacement.Fasten();

}

CPlacement* CLandscape::GetRootPlacement()
{
	return &m_zpOverallPlacement;
}