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

	m_zmAsphalt.MakeTextureDiffuse("textures\\black_image.jpg");
	m_zmAsphaltMarks.MakeTextureDiffuse("textures\\white_image.jpg");

	m_pzgAsphalt->SetMaterial(&m_zmAsphalt);
	m_pzgAsphaltMarks->SetMaterial(&m_zmAsphaltMarks);

	m_zpAsphalt.AddGeo(m_pzgAsphalt);
	m_zpAsphalt.AddGeo(m_pzgAsphaltMarks);

	m_zpTrack.AddPlacement(&m_zpAsphalt);
	m_zpTrack.AddPlacement(&m_zpAsphaltMarks);

}

CPlacement* CTrack::GetPlacement(){
	return &m_zpTrack;
}