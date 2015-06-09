#include "Landscape.h"


CLandscape::CLandscape()
{
}


CLandscape::~CLandscape()
{
}

void CLandscape::Init()
{
	m_pzgLandscape = m_zgLandscape.LoadGeo("meshes\\enviroment\\Landscape_reduced.obj");
	m_pzgTreeFir = m_zgTreeFir.LoadGeo("meshes\\enviroment\\Landscape_TreeFir_reduced.obj");
	m_pzgTreeRound = m_zgTreeRound.LoadGeo("meshes\\enviroment\\Landscape_TreeRound_reduced.obj");
	m_pzgTreeBobblig = m_zgTreeBobblig.LoadGeo("meshes\\enviroment\\Landscape_TreeBobblig_reduced.obj");
	m_pzgTreeLog = m_zgTreeLog.LoadGeo("meshes\\enviroment\\Landscape_Log_reduced.obj");

	m_zmLandscape.MakeTextureDiffuse("textures\\natur\\Gras_512.png");
	m_zmTreeFir.MakeTextureDiffuse("textures\\natur\\Gras_512.png");
	m_zmTreeRound.MakeTextureDiffuse("textures\\natur\\Gras_512.png");
	m_zmTreeBobblig.MakeTextureDiffuse("textures\\natur\\Gras_512.png");
	m_zmTreeLog.MakeTextureDiffuse("textures\\image_black.jpg");

	m_pzgLandscape->SetMaterial(&m_zmLandscape);
	m_pzgTreeFir->SetMaterial(&m_zmTreeFir);
	m_pzgTreeRound->SetMaterial(&m_zmTreeRound);
	m_pzgTreeBobblig->SetMaterial(&m_zmTreeBobblig);
	m_pzgTreeLog->SetMaterial(&m_zmTreeLog);

	m_zpLandscape.AddGeo(m_pzgLandscape);
	m_zpTreeFir.AddGeo(m_pzgTreeFir);
	m_zpTreeRound.AddGeo(m_pzgTreeRound);
	m_zpTreeBobblig.AddGeo(m_pzgTreeBobblig);
	m_zpTreeLog.AddGeo(m_pzgTreeLog);

	m_zpOverallPlacement.AddPlacement(&m_zpLandscape);
	m_zpOverallPlacement.AddPlacement(&m_zpTreeFir);
	m_zpOverallPlacement.AddPlacement(&m_zpTreeRound);
	m_zpOverallPlacement.AddPlacement(&m_zpTreeBobblig);
	m_zpOverallPlacement.AddPlacement(&m_zpTreeLog);

	m_zpOverallPlacement.Fasten();

}

CPlacement* CLandscape::GetRootPlacement()
{
	return &m_zpOverallPlacement;
}