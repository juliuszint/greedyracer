#include "BigHouse.h"


void CBigHouse::Init(){
	m_zmFacade.MakeTextureDiffuse("textures\\brickwall_notFinal.jpg");
	m_zmFacade.MakeTextureBump("textures\\brickwall_Bump_notFinal.jpg");
	m_zmRoof.MakeTextureDiffuse("textures\\dachplatten_notFinal.jpg");
	m_zmRoof.MakeTextureBump("textures\\dachplatten_Bump_notFinal.jpg");

	m_zmFacade.SetBumpStrength(7.0f);
	m_zmRoof.SetBumpStrength(5.0f);
	m_zgBigHouse.SetTextureRepeat(10.0f, 5.0f);

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