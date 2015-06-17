#include "Camaro.h"


void CCamaro::Init(){


	m_pzgBodywork = m_zgBodywork.LoadGeo("meshes\\Camaro\\CamaroBodywork.obj");
	m_pzgWindows = m_zgWindows.LoadGeo("meshes\\Camaro\\CamaroWindow.obj");
	m_pzgCoolerPaneling = m_zgWindows.LoadGeo("meshes\\Camaro\\CamaroCoolerPaneling.obj");
	m_pzgExhaustPaneling = m_zgWindows.LoadGeo("meshes\\Camaro\\CamaroExhaustPaneling.obj");
	//m_pzgFrontHeadlights = m_zgFrontHeadlights.LoadGeo("meshes\\PorscheFrontHeadlights.obj");
	//m_pzgRearLights = m_zgRearLights.LoadGeo("meshes\\PorscheRearLights.obj");
	m_pzgFrontTires = m_zgFrontTires.LoadGeo("meshes\\Camaro\\CamaroTires.obj");
	//m_pzgRearTires = m_zgRearTires.LoadGeo("meshes\\PorscheRearTires.obj");

	m_zmBodywork.MakeTextureDiffuse("textures\\blue_image.jpg");
	m_zmPlastic.MakeTextureDiffuse("textures\\black_image.jpg");
	m_zmWindow.MakeTextureDiffuse("textures\\black_image.jpg");
	//m_zmFrontHeadlights.MakeTextureDiffuse("textures\\blue_image.jpg");
	//m_zmRearLights.MakeTextureDiffuse("textures\\red_image.jpg");
	m_zmTires.MakeTextureDiffuse("textures\\black_image.jpg");

	m_pzgBodywork->SetMaterial(&m_zmBodywork);
	m_pzgWindows->SetMaterial(&m_zmWindow);
	m_pzgCoolerPaneling->SetMaterial(&m_zmPlastic);
	m_pzgExhaustPaneling->SetMaterial(&m_zmPlastic);
	//m_pzgFrontHeadlights->SetMaterial(&m_zmFrontHeadlights);
	//m_pzgRearLights->SetMaterial(&m_zmRearLights);
	m_pzgFrontTires->SetMaterial(&m_zmTires);
	//m_pzgRearTires->SetMaterial(&m_zmTires);

	m_zpBodywork.AddGeo(m_pzgBodywork);
	m_zpCoolerPaneling.AddGeo(m_pzgCoolerPaneling);
	m_zpExhaustPaneling.AddGeo(m_pzgExhaustPaneling);
	m_zpWindows.AddGeo(m_pzgWindows);
	//m_zpFrontHeadlights.AddGeo(m_pzgFrontHeadlights);
	//m_zpRearLights.AddGeo(m_pzgRearLights);
	m_zpFrontTires.AddGeo(m_pzgFrontTires);
	//m_zpRearTires.AddGeo(m_pzgRearTires);

	m_zpCamaro.AddPlacement(&m_zpBodywork);
	m_zpCamaro.AddPlacement(&m_zpCoolerPaneling);
	m_zpCamaro.AddPlacement(&m_zpExhaustPaneling);
	m_zpCamaro.AddPlacement(&m_zpWindows);
	//m_zpCamaro.AddPlacement(&m_zpFrontHeadlights);
	//m_zpCamaro.AddPlacement(&m_zpRearLights);
	m_zpCamaro.AddPlacement(&m_zpFrontTires);
	m_zpCamaro.TranslateDelta(CHVector(0, 2.5, 0));
	m_zpCamaro.Scale(0.1f);
	//m_zpCamaro.AddPlacement(&m_zpRearTires);

	//m_zpCamaro.ScaleDelta(0.1f);
	
}

CPlacement* CCamaro::GetRootPlacement(){
	return &m_zpCamaro;
}

//CVehicle** CCamaro::GetVehicle()
//{
//	return &m_zvAuto;
//}
