#include "Camaro.h"


CCamaro::CCamaro()
{
}


CCamaro::~CCamaro()
{
}

void CCamaro::InitCamaro(){
	m_pzgBodywork = m_zgBodywork.LoadGeo("meshes\\Camaro\\CamaroBodywork.obj");
	m_pzgWindows = m_zgWindows.LoadGeo("meshes\\Camaro\\CamaroWindows.obj");
	m_pzgCoolerPaneling = m_zgWindows.LoadGeo("meshes\\Camaro\\CamaroRadiatorGrill.obj");
	m_pzgExhaustPaneling = m_zgWindows.LoadGeo("meshes\\Camaro\\CamaroExhaustPaneling.obj");
	m_pzgFrontHeadlights = m_zgFrontHeadlights.LoadGeo("meshes\\Camaro\\CamaroHeadLights.obj");
	m_pzgRearLights = m_zgRearLights.LoadGeo("meshes\\Camaro\\CamaroBackLights.obj");
	m_pzgFrontTireR = m_zgFrontTireR.LoadGeo("meshes\\Camaro\\CamaroTireRight.obj");
	m_pzgFrontRimR = m_zgFrontRimR.LoadGeo("meshes\\Camaro\\CamaroRimRight.obj");
	m_pzgFrontTireL = m_zgFrontTireL.LoadGeo("meshes\\Camaro\\CamaroTireLeft.obj");
	m_pzgFrontRimL = m_zgFrontRimL.LoadGeo("meshes\\Camaro\\CamaroRimLeft.obj");
	m_pzgRearTires = m_zgRearTires.LoadGeo("meshes\\Camaro\\CamaroTireRear.obj");
	m_pzgRearRim = m_zgRearRim.LoadGeo("meshes\\Camaro\\CamaroRimRear.obj");
	m_pzgMirrors = m_zgMirrors.LoadGeo("meshes\\Camaro\\CamaroMirrors.obj");
	m_pzgExhaust = m_zgExhaust.LoadGeo("meshes\\Camaro\\CamaroExhaust.obj");
	CHMat mUrsprung;
	mUrsprung.Translate(1.5f,-0.7,-3.0);
	m_pzgFrontRimL->Transform(mUrsprung);
	m_pzgFrontTireL->Transform(mUrsprung);

	m_zmBodywork.MakeTextureDiffuse("textures\\blue_image.jpg");
	m_zmPlastic.MakeTextureDiffuse("textures\\black_image.jpg");
	m_zmWindow.MakeTextureDiffuse("textures\\black_image.jpg");
	m_zmFrontHeadlights.MakeTextureDiffuse("textures\\blue_image.jpg");
	m_zmRearLights.MakeTextureDiffuse("textures\\red_image.jpg");
	m_zmTire.MakeTextureDiffuse("textures\\black_image.jpg");
	m_zmRim.MakeTextureDiffuse("textures\\white_image.jpg");
	m_zmExhaust.MakeTextureDiffuse("textures\\white_image.jpg");

	m_pzgBodywork->SetMaterial(&m_zmBodywork);
	m_pzgWindows->SetMaterial(&m_zmWindow);
	m_pzgCoolerPaneling->SetMaterial(&m_zmPlastic);
	m_pzgExhaustPaneling->SetMaterial(&m_zmPlastic);
	m_pzgFrontHeadlights->SetMaterial(&m_zmFrontHeadlights);
	m_pzgRearLights->SetMaterial(&m_zmRearLights);
	m_pzgFrontTireR->SetMaterial(&m_zmTire);
	m_pzgFrontRimR->SetMaterial(&m_zmRim);
	m_pzgFrontTireL->SetMaterial(&m_zmTire);
	m_pzgFrontRimL->SetMaterial(&m_zmRim);
	m_pzgRearTires->SetMaterial(&m_zmTire);
	m_pzgRearRim->SetMaterial(&m_zmRim);
	m_pzgMirrors->SetMaterial(&m_zmBodywork);
	m_pzgExhaust->SetMaterial(&m_zmExhaust);

	m_zpBodywork.AddGeo(m_pzgBodywork);
	m_zpBodywork.AddGeo(m_pzgMirrors);
	m_zpBodywork.AddGeo(m_pzgCoolerPaneling);
	m_zpBodywork.AddGeo(m_pzgExhaustPaneling);
	m_zpBodywork.AddGeo(m_pzgExhaust);
	m_zpBodywork.AddGeo(m_pzgWindows);
	m_zpBodywork.AddGeo(m_pzgFrontHeadlights);
	m_zpBodywork.AddGeo(m_pzgRearLights);
	m_zpFrontTireR.AddGeo(m_pzgFrontTireR);
	m_zpFrontTireR.AddGeo(m_pzgFrontRimR);
	m_zpFrontTireL.AddGeo(m_pzgFrontTireL);
	m_zpFrontTireL.AddGeo(m_pzgFrontRimL);
	m_zpRearTires.AddGeo(m_pzgRearTires);
	m_zpRearTires.AddGeo(m_pzgRearRim);


	//m_zpFrontTireR.TranslateZDelta(3.0f);
	//m_zpFrontTireR.TranslateYDelta(-0.7f);
	//m_zpFrontTireR.TranslateXDelta(-1.5f);
	m_zpFrontTireL.Translate(1.5f, -0.7f, -3.0f);
	/*
	m_zpFrontTireL.TranslateZ(3.0f);
	m_zpFrontTireL.TranslateY(-0.7f);
	m_zpFrontTireL.TranslateX(1.5f);*/
	//m_zpRearTires.TranslateZDelta(-2.8f);
	//m_zpRearTires.TranslateYDelta(-0.6f);

	m_zpCamaro.AddPlacement(&m_zpBodywork);
//	m_zpCamaro.AddPlacement(&m_zpFrontTireR);
	m_zpCamaro.AddPlacement(&m_zpFrontTireL);
	//m_zpCamaro.AddPlacement(&m_zpRearTires);
}

CPlacement* CCamaro::GetPlacement(){
	return &m_zpCamaro;
}

void CCamaro::RotateFrontTiresX(){
	//CHVector buffer;
	//buffer = m_zpFrontTireL.GetTranslation();

	//m_zpFrontTireL.Translate(-buffer);
	
	m_zpFrontTireR.RotateXDelta(HALFPI/4);
	m_zpFrontTireL.RotateXDelta(HALFPI/4);
	m_zpRearTires.RotateXDelta(HALFPI/4);
	//m_zpFrontTireL.Translate(buffer);
}

void CCamaro::RotateFrontTiresY(bool rotRight){
	CHVector bufferR;
	CHVector bufferL;
	bufferR = m_zpFrontTireR.GetTranslation();
	bufferL = m_zpFrontTireL.GetTranslation();
	m_zpFrontTireR.Translate(-bufferR);
	m_zpFrontTireL.Translate(-bufferL);

	if (rotRight == true){
		m_zpFrontTireR.RotateY(-HALFPI / 8);
		m_zpFrontTireL.RotateY(-HALFPI / 8);
	}
	else if (rotRight == false){
		m_zpFrontTireR.RotateY(HALFPI / 8);
		m_zpFrontTireL.RotateY(HALFPI / 8);
	}

	m_zpFrontTireR.Translate(bufferR);
	m_zpFrontTireL.Translate(bufferL);
}