#include "OptischeStrecke.h"


void COptischeStrecke::Init(){

	m_pzgOptStrecke = m_zgOptStrecke.LoadGeo("meshes\\allgaeumap\\OptStrecke.obj");
	m_zmOptStrecke.MakeTextureDiffuse("textures\\allgaeumap\\strecke\\Rennstrecke_4098.jpg");
	m_zmOptStrecke.MakeTextureSpecular("textures\\allgaeumap\\strecke\\Rennstrecke_4098_spec.jpg");
	m_pzgOptStrecke->SetMaterial(&m_zmOptStrecke);
	m_zpOptStrecke.AddGeo(m_pzgOptStrecke);

	m_zpOptStrecke.Translate(CHVector(0, 0.1, 0));

}

CPlacement * COptischeStrecke::GetRootPlacement(){
	return &m_zpOptStrecke;
}