#include "FallenTree.h"

void CFallenTree::Init()
{
	m_pzgTrigger = m_zgTrigger.LoadGeo("meshes\\enviroment\\TreeTrigger.obj");
	m_zmTrigger.MakeTextureDiffuse("textures\\image_black.jpg");
	m_pzgTrigger->SetMaterial(&m_zmTrigger);
	m_zpTrigger.AddGeo(m_pzgTrigger);
}

CPlacement* CFallenTree::GetRootPlacement()
{
	return &this->m_zpTrigger;
}
