#include "Sektor.h"

void CSektor::Init(){

}

void CSektor::Init(char* GeoPath){

	m_pzgSektor = m_zgSektor.LoadGeo(GeoPath);
	//m_zmSektor.MakeTextureDiffuse("textures\\allgaeumap\\strecke\\Rennstrecke_4098.jpg");
	//m_zmSektor.MakeTextureSpecular("textures\\allgaeumap\\strecke\\Rennstrecke_4098_spec.jpg");
	m_pzgSektor->SetMaterial(&m_zmSektor);
	m_zpSektor.AddGeo(m_pzgSektor);


}

CPlacement* CSektor::GetRootPlacement(){
	return &m_zpSektor;
}

CGeo * CSektor::GetGeo(){
	
	return m_pzgSektor;
	//return 0;
}

void CSektor::Translate(CHVector Vektor){
	m_zpSektor.Translate(Vektor);
}

void CSektor::setRespawnAngle(float fAngle){
	RespawnAngle = fAngle;
}

float CSektor::getRespawnAngle(){
	return RespawnAngle;
}