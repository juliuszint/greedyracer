#include "Abkuerzung.h"

void CAbkuerzung::Init(){

}

void CAbkuerzung::Init(char * GeoPath){

	m_pzgAbkuerzung = m_zgAbkuerzung.LoadGeo(GeoPath);
	m_zmAbkuerzung.MakeTextureDiffuse("textures\\allgaeumap\\strecke\\Rennstrecke_4098.jpg");
	m_zmAbkuerzung.MakeTextureSpecular("textures\\allgaeumap\\strecke\\Rennstrecke_4098_spec.jpg");
	m_pzgAbkuerzung->SetMaterial(&m_zmAbkuerzung);
	m_zpAbkuerzung.AddGeo(m_pzgAbkuerzung);

	m_zgTrigger.Init(1.5f, 0.2f, &m_zmAbkuerzung);
	m_zpTrigger.AddGeo(&m_zgTrigger);

	m_zpAbkuerzung.AddPlacement(&m_zpTrigger);

}

CPlacement* CAbkuerzung::GetRootPlacement(){
	return &m_zpAbkuerzung;
}

CGeo * CAbkuerzung::GetGeo(){
	return m_pzgAbkuerzung;
}

void CAbkuerzung::Translate(CHVector Vektor){
	m_zpAbkuerzung.Translate(Vektor);
}

void CAbkuerzung::TranslateTrigger(CHVector Vektor){
	m_zpTrigger.TranslateDelta(Vektor);
}

void CAbkuerzung::RotateTrigger(float Rotate){
	m_zpTrigger.RotateX(Rotate);
}