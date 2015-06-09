#include "Sektor.h"

void CSektor::Init(){

}

void CSektor::Init(char* GeoPath){

	m_pzgSektor = m_zgSektor.LoadGeo(GeoPath);
	m_zmSektor.MakeTextureDiffuse("textures\\allgaeumap\\strecke\\Rennstrecke_4098.jpg");
	m_zmSektor.MakeTextureSpecular("textures\\allgaeumap\\strecke\\Rennstrecke_4098_spec.jpg");
	m_pzgSektor->SetMaterial(&m_zmSektor);
	m_zpSektor.AddGeo(m_pzgSektor);


}

CPlacement* CSektor::GetRootPlacement(){
	return &m_zpSektor;
}
