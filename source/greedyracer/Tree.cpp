#include "Tree.h"


CTree::CTree()
{
}


CTree::~CTree()
{
}

void CTree::InitTree(){
	m_zmLeafs.MakeTextureDiffuse("textures\\green_image.jpg");
	m_zmLog.MakeTextureDiffuse("textures\\black_image.jpg");

	m_pzgLeafs = m_zgLeafs.LoadGeo("meshes\\Enviroment\\Tree_Fir.obj");
	m_pzgLog = m_zgLog.LoadGeo("meshes\\Enviroment\\Tree_Log.obj");

	m_pzgLeafs->SetMaterial(&m_zmLeafs);
	m_pzgLog->SetMaterial(&m_zmLog);

	m_zpLeafs.AddGeo(m_pzgLeafs);
	m_zpLog.AddGeo(m_pzgLog);
	m_zpTree.AddPlacement(&m_zpLeafs);
	m_zpTree.AddPlacement(&m_zpLog);

}
void CTree::InitTreeRound(){
	m_zmLeafs.MakeTextureDiffuse("textures\\green_image.jpg");
	m_zmLog.MakeTextureDiffuse("textures\\black_image.jpg");

	m_pzgLeafs = m_zgLeafs.LoadGeo("meshes\\Enviroment\\Tree_Round.obj");
	m_pzgLog = m_zgLog.LoadGeo("meshes\\Enviroment\\Tree_Log.obj");

	m_pzgLeafs->SetMaterial(&m_zmLeafs);
	m_pzgLog->SetMaterial(&m_zmLog);

	m_zpLeafs.AddGeo(m_pzgLeafs);
	m_zpLog.AddGeo(m_pzgLog);
	m_zpTree.AddPlacement(&m_zpLeafs);
	m_zpTree.AddPlacement(&m_zpLog);

}

void CTree::InitTreeBush(){
	m_zmLeafs.MakeTextureDiffuse("textures\\green_image.jpg");
	m_zmLog.MakeTextureDiffuse("textures\\black_image.jpg");

	m_pzgLeafs = m_zgLeafs.LoadGeo("meshes\\Enviroment\\Tree_Bobbelig.obj");
	m_pzgLog = m_zgLog.LoadGeo("meshes\\Enviroment\\Tree_Log.obj");

	m_pzgLeafs->SetMaterial(&m_zmLeafs);
	m_pzgLog->SetMaterial(&m_zmLog);

	m_zpLeafs.AddGeo(m_pzgLeafs);
	m_zpLog.AddGeo(m_pzgLog);
	m_zpTree.AddPlacement(&m_zpLeafs);
	m_zpTree.AddPlacement(&m_zpLog);

}

void CTree::InitTreeRow(){
	

}

CPlacement* CTree::GetPlacementTree(){
	return &m_zpTree;
}

