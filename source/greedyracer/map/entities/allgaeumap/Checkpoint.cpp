#include "Checkpoint.h"

void CCheckpoint::Init(){

}

void CCheckpoint::Init( char * GeoPath){

	m_pzgCheckpoint = m_zgCheckpoint.LoadGeo(GeoPath);
	m_zmCheckpoint.MakeTextureDiffuse("textures\\allgaeumap\\strecke\\Rennstrecke_4098.jpg");
	m_zmCheckpoint.MakeTextureSpecular("textures\\allgaeumap\\strecke\\Rennstrecke_4098_spec.jpg");
	m_pzgCheckpoint->SetMaterial(&m_zmCheckpoint);
	m_zpCheckpoint.AddGeo(m_pzgCheckpoint);


}

CPlacement* CCheckpoint::GetRootPlacement(){
	return &m_zpCheckpoint;
}

CGeo * CCheckpoint::GetGeo(){
	return m_pzgCheckpoint;
}
