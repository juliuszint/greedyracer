#include "BigHouse.h"


CBigHouse::CBigHouse()
{
}


CBigHouse::~CBigHouse()
{
}

void CBigHouse::InitBigHouse(){
	m_zmFacade.MakeTextureDiffuse("textures\\Haus\\Fassade_512.png");
	m_zmFacade.MakeTextureBump("textures\\Haus\\Fassade_512_n.png");
	m_zmRoof.MakeTextureDiffuse("textures\\Haus\\Dachziegel_Rot_512.png");
	m_zmRoof.MakeTextureBump("textures\\Haus\\Dachziegel_Rot_512_n.png");

	m_zmFacade.SetBumpStrength(2.0f);
	m_zmRoof.SetBumpStrength(0.1f);
	m_zgBigHouse.SetTextureRepeat(3.0f, 1.0f);

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

CPlacement* CBigHouse::GetBigHousePlacement(){
	return &m_zpBigHouse;
}