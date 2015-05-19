#include "LittleHouse.h"

void CLittleHouse::Init(){
	m_zmFacade.MakeTextureDiffuse("textures\\brickwall_notFinal.jpg");
	m_zmFacade.MakeTextureBump("textures\\brickwall_Bump_notFinal.jpg");
	m_zmRoof.MakeTextureDiffuse("textures\\dachplatten_notFinal.jpg");
	m_zmRoof.MakeTextureBump("textures\\dachplatten_Bump_notFinal.jpg");

	m_zmFacade.SetBumpStrength(7.0f);
	m_zmRoof.SetBumpStrength(5.0f);
	m_zgLittleHouse.SetTextureRepeat(10.0f, 5.0f);

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

