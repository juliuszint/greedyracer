#include "BigHouse.h"


void CBigHouse::Init(){
	m_zmFacade.MakeTextureDiffuse("textures\\haus\\Fassade_512.png");
	m_zmFacade.MakeTextureBump("textures\\haus\\Fassade_512_n.png");
	m_zmRoof.MakeTextureDiffuse("textures\\haus\\Dachziegel_Rot_512.png");
	m_zmRoof.MakeTextureBump("textures\\haus\\Dachziegel_Rot_512_n.png");

	m_zmFacade.SetBumpStrength(7.0f);
	m_zmRoof.SetBumpStrength(5.0f);
	m_zgBigHouse.SetTextureRepeat(5.0f, 1.0f);

	m_zgBigHouse.SetMaterialFacade(&m_zmFacade);
	m_zgBigHouse.SetMaterialRoof(&m_zmRoof);
	m_zgBigHouse.SetMaterialCeiling(&m_zmFacade);

	m_zgBigHouse.OpenSesamy("P@VGSVAABSC");
	m_zgBigHouse.SetSizeRect(5.0f, 10.0f, 2.0f);
	m_zgBigHouse.SetHeightRoof(1.5f);
	m_zgBigHouse.SetOverroof(0.0f, 0.0f);
	m_zgBigHouse.InitRectSaddle();

	m_zpBigHouse.AddGeo(&m_zgBigHouse);
	m_zpBigHouse.Scale(0.03f);
}

CPlacement* CBigHouse::GetRootPlacement(){
	return &m_zpBigHouse;
}