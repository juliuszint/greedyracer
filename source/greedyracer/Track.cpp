#include "Track.h"


CTrack::CTrack()
{
}


CTrack::~CTrack()
{
}

void CTrack::InitTrack(){
	
	m_pzgRennstrecke = m_zgRennstrecke.LoadGeo("meshes\\Track\\Rennstrecke.obj");
	m_zmRennstrecke.MakeTextureDiffuse("textures\\Rennstrecke\\Rennstrecke.jpg");
	m_zmRennstrecke.MakeTextureSpecular("textures\\Rennstrecke\\Rennstrecke_Spec.jpg");
	m_pzgRennstrecke->SetMaterial(&m_zmRennstrecke);
	m_zpRennstrecke.AddGeo(m_pzgRennstrecke);
	m_zpTrack.AddPlacement(&m_zpRennstrecke);

}

CPlacement* CTrack::GetPlacement(){
	return &m_zpTrack;
}