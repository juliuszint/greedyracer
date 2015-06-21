#include "Rocks.h"

void CRocks::Init()
{
	m_pzgTrigger = m_zgTrigger.LoadGeo("meshes\\enviroment\\RocksTrigger.obj");
	m_zmTrigger.MakeTextureDiffuse("textures\\image_black.jpg");
	m_pzgTrigger->SetMaterial(&m_zmTrigger);
	m_zpTrigger.AddGeo(m_pzgTrigger);
}

CPlacement* CRocks::GetRootPlacement()
{
	return &this->m_zpTrigger;
}
