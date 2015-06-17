#include "Porsche.h"


void CPorsche::Init(){


	m_pzgBodywork = m_zgBodywork.LoadGeo("meshes\\Porsche\\PorscheBodywork_reduced.obj");
	m_pzgFrontHeadlights = m_zgFrontHeadlights.LoadGeo("meshes\\Porsche\\PorscheFrontHeadlights_reduced.obj");
	m_pzgRearLights = m_zgRearLights.LoadGeo("meshes\\Porsche\\PorscheRearLights_reduced.obj");
	m_pzgFrontTires = m_zgFrontTires.LoadGeo("meshes\\Porsche\\PorscheFrontTires.obj");
	m_pzgRearTires = m_zgRearTires.LoadGeo("meshes\\Porsche\\PorscheRearTires.obj");
	m_pzgWindows = m_zgWindows.LoadGeo("meshes\\Porsche\\PorscheWindows_reduced.obj");
	m_pzgExhaust = m_zgExhaust.LoadGeo("meshes\\Porsche\\PorscheExhaust_reduced.obj");

	m_zmBodywork.MakeTextureDiffuse("textures\\black_image.jpg");
	m_zmFrontHeadlights.MakeTextureDiffuse("textures\\blue_image.jpg");
	m_zmRearLights.MakeTextureDiffuse("textures\\red_image.jpg");
	m_zmTires.MakeTextureDiffuse("textures\\black_image.jpg");
	m_zmWindow.MakeTextureDiffuse("textures\\black_image.jpg");
	m_zmExhaust.MakeTextureDiffuse("textures\\black_image.jpg");

	m_pzgBodywork->SetMaterial(&m_zmBodywork);
	m_pzgFrontHeadlights->SetMaterial(&m_zmFrontHeadlights);
	m_pzgRearLights->SetMaterial(&m_zmRearLights);
	m_pzgFrontTires->SetMaterial(&m_zmTires);
	m_pzgRearTires->SetMaterial(&m_zmTires);
	m_pzgWindows->SetMaterial(&m_zmWindow);
	m_pzgExhaust->SetMaterial(&m_zmExhaust);

	m_zpBodywork.AddGeo(m_pzgBodywork);
	m_zpFrontHeadlights.AddGeo(m_pzgFrontHeadlights);
	m_zpRearLights.AddGeo(m_pzgRearLights);
	m_zpFrontTires.AddGeo(m_pzgFrontTires);
	m_zpRearTires.AddGeo(m_pzgRearTires);
	m_zpWindows.AddGeo(m_pzgWindows);
	m_zpExhaust.AddGeo(m_pzgExhaust);
	
	m_zpPorsche.AddPlacement(&m_zpBodywork);
	m_zpPorsche.AddPlacement(&m_zpFrontHeadlights);
	m_zpPorsche.AddPlacement(&m_zpRearLights);
	m_zpPorsche.AddPlacement(&m_zpFrontTires);
	m_zpPorsche.AddPlacement(&m_zpRearTires);
	m_zpPorsche.AddPlacement(&m_zpWindows);
	m_zpPorsche.AddPlacement(&m_zpExhaust);

	m_zpPorsche.Fasten();

	m_zpPorsche.TranslateDelta(CHVector(0, 2.5, 0));

	m_zpPorsche.Scale(0.1f);
}

CPlacement* CPorsche::GetRootPlacement(){
	return &m_zpPorsche;
}