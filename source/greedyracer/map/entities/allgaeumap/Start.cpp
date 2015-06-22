#include "Start.h"


void CStart::Init(){

	m_pzgStart = m_zgStart.LoadGeo("meshes\\allgaeumap\\strecke\\01_Start.obj");
	m_zmStart.MakeTextureDiffuse("textures\\allgaeumap\\strecke\\Rennstrecke_4098.jpg");
	m_zmStart.MakeTextureSpecular("textures\\allgaeumap\\strecke\\Rennstrecke_4098_spec.jpg");
	m_pzgStart->SetMaterial(&m_zmStart);
	m_zpStart.AddGeo(m_pzgStart);


}

CPlacement* CStart::GetRootPlacement(){
	return &m_zpStart;
}

CGeo * CStart::GetGeo(){
	return m_pzgStart;
}

void CStart::Translate(CHVector Vektor){
	m_zpStart.Translate(Vektor);
}

void CStart::setRespawnAngle(float fAngle){
	RespawnAngle = fAngle;
}

float CStart::getRespawnAngle(){
	return RespawnAngle;
}