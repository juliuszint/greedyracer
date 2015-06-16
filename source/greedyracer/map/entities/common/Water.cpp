#include "Water.h"


void CWater::Configure(int width, int height)
{
	this->width = width;
	this->height = height;
}

void CWater::Init()
{
	this->material.MakeTextureDiffuse("textures\\water02.jpg");
	this->material.SetTextureSpecularBlack();
	this->material.SetAni(4, 4, 10);

	//this->quad.Init(this->width, this->height, &this->material);
	this->m_pzgBay = m_zgBay.LoadGeo("meshes\\enviroment\\Bay.obj");
	this->m_pzgBay->SetMaterial(&material);
	this->placement.AddGeo(this->m_pzgBay);
	//this->placement.RotateXDelta(-HALFPI);
}

CPlacement* CWater::GetRootPlacement()
{
	return &this->placement;
}
