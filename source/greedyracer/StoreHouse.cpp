#include "StoreHouse.h"


CStoreHouse::CStoreHouse()
{
}


CStoreHouse::~CStoreHouse()
{
}

void CStoreHouse::InitStoreHouse(){
	m_zmFacade.MakeTextureDiffuse("textures\\Haus\\Fassade_512.png");
	m_zmFacade.MakeTextureBump("textures\\Haus\\Fassade_512_n.png");
	m_zmFacade.MakeTextureDiffuse("textures\\Haus\\Dachziegel_Rot_512.png");
	m_zmFacade.MakeTextureBump("textures\\Haus\\Dachziegel_Rot_512_n.png");

	m_zmFacade.SetBumpStrength(2.0f);
	m_zmRoof.SetBumpStrength(0.1f);
	m_zgStoreHouse.SetTextureRepeat(3.0f, 1.0f);

	m_zgStoreHouse.SetMaterialFacade(&m_zmFacade);
	m_zgStoreHouse.SetMaterialRoof(&m_zmRoof);
	m_zgStoreHouse.SetMaterialCeiling(&m_zmFacade);

	m_zgStoreHouse.OpenSesamy("P@VGSVAABSC");
	m_zgStoreHouse.InitRectFlat();

}

CPlacement* CStoreHouse::GetStoreHousePlacement(){
	return &m_zpStoreHouse;
}