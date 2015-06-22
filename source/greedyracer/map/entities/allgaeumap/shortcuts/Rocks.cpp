#include "Rocks.h"

void CRocks::Init()
{
	m_pzgTrigger = m_zgTrigger.LoadGeo("meshes\\enviroment\\RocksTrigger.obj");
	m_zmTrigger.MakeTextureDiffuse("textures\\Hindernisse\\Fels_512.jpg");
	m_zmTrigger.MakeTextureSpecular("textures\\Hindernisse\\Fels_512_spec.jpg");
	m_pzgTrigger->SetMaterial(&m_zmTrigger);
	m_zpTrigger.AddGeo(m_pzgTrigger);
}

CPlacement* CRocks::GetRootPlacement()
{
	return &this->m_zpTrigger;
}
