#include "Track.h"


CTrack::CTrack()
{
}


CTrack::~CTrack()
{
}

void CTrack::InitTrack(){
	
	m_pzgAsphalt = m_zgAsphalt.LoadGeo("meshes\\Track\\Track.obj");
	m_pzgAsphaltMarks = m_zgAsphaltMarks.LoadGeo("meshes\\Track\\TrackMarks.obj");
	m_pzgRennstrecke = m_zgRennstrecke.LoadGeo("meshes\\Track\\Rennstrecke.obj");

	m_zmAsphalt.MakeTextureDiffuse("textures\\black_image.jpg");
	m_zmAsphaltMarks.MakeTextureDiffuse("textures\\white_image.jpg");
	m_zmRennstrecke.MakeTextureDiffuse("textures\\Rennstrecke.jpg");


	m_pzgAsphalt->SetMaterial(&m_zmAsphalt);
	m_pzgAsphaltMarks->SetMaterial(&m_zmAsphaltMarks);
	m_pzgRennstrecke->SetMaterial(&m_zmRennstrecke);

	m_zpAsphalt.AddGeo(m_pzgAsphalt);
	m_zpAsphalt.AddGeo(m_pzgAsphaltMarks);
	m_zpRennstrecke.AddGeo(m_pzgRennstrecke);

	m_zpTrack.AddPlacement(&m_zpAsphalt);
	m_zpTrack.AddPlacement(&m_zpAsphaltMarks);
	m_zpTrack.AddPlacement(&m_zpRennstrecke);

}

CPlacement* CTrack::GetPlacement(){
	return &m_zpTrack;
}