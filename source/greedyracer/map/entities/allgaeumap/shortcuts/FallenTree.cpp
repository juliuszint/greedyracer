#include "FallenTree.h"

void CFallenTree::Init()
{
	m_pzgTrigger = m_zgTrigger.LoadGeo("meshes\\enviroment\\TreeTrigger.obj");
	m_zmTrigger.MakeTextureDiffuse("textures\\image_black.jpg");
	m_pzgTrigger->SetMaterial(&m_zmTrigger);
	m_zpTrigger.AddGeo(m_pzgTrigger);
	m_zpTrigger.RotateZ(HALFPI);
	m_zpTrigger.TranslateXDelta(0.5f);
}

CPlacement* CFallenTree::GetRootPlacement()
{
	return &this->m_zpTrigger;
}