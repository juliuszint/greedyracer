#include "LittleHouse.h"


CLittleHouse::CLittleHouse()
{
}


CLittleHouse::~CLittleHouse()
{
}

void CLittleHouse::InitLittleHouse(){
	m_zmFacade.MakeTextureDiffuse("textures\\Haus\\Fassade_512.png");
	m_zmFacade.MakeTextureBump("textures\\Haus\\Fassade_512_n.png");
	m_zmRoof.MakeTextureDiffuse("textures\\Haus\\Dachziegel_Rot_512.png");
	m_zmRoof.MakeTextureBump("textures\\Haus\\Dachziegel_Rot_512_n.png");

	m_zmFacade.SetBumpStrength(1.0f);
	m_zmRoof.SetBumpStrength(0.1f);
	m_zgLittleHouse.SetTextureRepeat(1.0f, 1.0f);

	m_zgLittleHouse.SetMaterialFacade(&m_zmFacade);
	m_zgLittleHouse.SetMaterialRoof(&m_zmRoof);
	m_zgLittleHouse.SetMaterialCeiling(&m_zmFacade);

	m_zgLittleHouse.OpenSesamy("P@VGSVAABSC");
	m_zgLittleHouse.SetSizeRect(5.0f, 5.0f, 2.0f);
	m_zgLittleHouse.SetDepthMans(1.0f);
	m_zgLittleHouse.SetHeightRoof(0.7f);
	m_zgLittleHouse.SetOverroof(0.2f, 0.0f);
	m_zgLittleHouse.InitRectMans();
	
	m_zpLittleHouse.AddGeo(&m_zgLittleHouse);
	m_zpLittleHouse.Scale(0.03f);
}

CPlacement* CLittleHouse::GetLittleHousePlacement(){
	return &m_zpLittleHouse;
}

