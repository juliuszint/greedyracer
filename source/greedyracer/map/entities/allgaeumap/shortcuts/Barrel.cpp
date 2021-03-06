#include "Barrel.h"

void CBarrel::Init()
{
	m_pzgTrigger = m_zgTrigger.LoadGeo("meshes\\enviroment\\BeerbarrelTrigger.obj");
	m_zmTrigger.MakeTextureDiffuse("textures\\Hindernisse\\Bierfass.jpg");
	m_zmTrigger.MakeTextureSpecular("textures\\Hindernisse\\Bierfass_spec.jpg");
	m_pzgTrigger->SetMaterial(&m_zmTrigger);
	m_zpTrigger.AddGeo(m_pzgTrigger);
}

CPlacement* CBarrel::GetRootPlacement()
{
	return &this->m_zpTrigger;
}
