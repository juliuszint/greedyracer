#include "LittleHouse.h"

void CLittleHouse::Init(){
	m_zmFacade.MakeTextureDiffuse("textures\\haus\\Fassade_512.png");
	m_zmFacade.MakeTextureBump("textures\\haus\\Fassade_512_n.png");
	m_zmRoof.MakeTextureDiffuse("textures\\haus\\Dachziegel_Rot_512.png");
	m_zmRoof.MakeTextureBump("textures\\haus\\Dachziegel_Rot_512_n.png");

	m_zmFacade.SetBumpStrength(7.0f);
	m_zmRoof.SetBumpStrength(5.0f);
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

CPlacement* CLittleHouse::GetRootPlacement(){
	return &m_zpLittleHouse;
}

