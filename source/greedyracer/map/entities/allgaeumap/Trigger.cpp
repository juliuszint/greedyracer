#include "Trigger.h"


CTrigger::CTrigger()
{
}


CTrigger::~CTrigger()
{
}

void CTrigger::InitTree(){
	m_pzgTrigger = m_zgTrigger.LoadGeo("meshes\\enviroment\\TreeTrigger.obj");
	m_zmTrigger.MakeTextureDiffuse("textures\\image_black.jpg");
	m_pzgTrigger->SetMaterial(&m_zmTrigger);
	//m_zpTrigger.AddGeo(m_pzgTrigger);

}

void CTrigger::InitRocks(){
	m_pzgTrigger = m_zgTrigger.LoadGeo("meshes\\enviroment\\RocksTrigger.obj");
	m_zmTrigger.MakeTextureDiffuse("textures\\image_black.jpg");
	m_pzgTrigger->SetMaterial(&m_zmTrigger);
	//m_zpTrigger.AddGeo(m_pzgTrigger);
}

void CTrigger::InitBeerbarrel(){
	m_pzgTrigger = m_zgTrigger.LoadGeo("meshes\\enviroment\\BeerbarrelTrigger.obj");
	m_zmTrigger.MakeTextureDiffuse("textures\\image_black.jpg");
	m_pzgTrigger->SetMaterial(&m_zmTrigger);
	//m_zpTrigger.AddGeo(m_pzgTrigger);
}

CPlacement* CTrigger::GetRootPlacement(){
	return &m_zpTrigger;
}

CGeo* CTrigger::GetGeo(){
	return m_pzgTrigger;
}