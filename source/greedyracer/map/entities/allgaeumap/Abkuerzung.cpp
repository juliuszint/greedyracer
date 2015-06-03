#include "Abkuerzung.h"

void CAbkuerzung::Init(){

}

void CAbkuerzung::Init(char * GeoPath){

	m_pzgAbkuerzung = m_zgAbkuerzung.LoadGeo(GeoPath);
	m_zmAbkuerzung.MakeTextureDiffuse("textures\\allgaeumap\\strecke\\Rennstrecke_4098.jpg");
	m_zmAbkuerzung.MakeTextureSpecular("textures\\allgaeumap\\strecke\\Rennstrecke_4098_spec.jpg");
	m_pzgAbkuerzung->SetMaterial(&m_zmAbkuerzung);
	m_zpAbkuerzung.AddGeo(m_pzgAbkuerzung);


}

CPlacement* CAbkuerzung::GetRootPlacement(){
	return &m_zpAbkuerzung;
}
