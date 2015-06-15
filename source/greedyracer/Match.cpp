#include "Match.h"


CMatch::CMatch(CDeviceKeyboard * pkeyboard)
{
	m_pkeyboard = pkeyboard;
}

void CMatch::Tick(float fTimeDelta)
{
	Cont1.Move(fTimeDelta);
}

void CMatch::Start()
{
	this->mapPlacement->AddPlacement(this->player1Placement);
	CHVector startPosition = this->map->GetStartPosition();

	this->player1Placement->TranslateDelta(startPosition);
}

void CMatch::Stop()
{
	this->mapPlacement->SubPlacement(this->player1Placement);
}

void CMatch::Init(CMap* map)
{
	this->map = map;
	this->mapPlacement = this->map->GetRootPlacement();

	this->player1Vehicle = new CCamaro();
	this->player1Vehicle->Init();
	this->player1Placement = this->player1Vehicle->GetRootPlacement();
	
	Cont1.addCharacter(this->player1Placement);
	Cont1.addKeyboard(m_pkeyboard);
	Cont1.setKeybinding(DIK_U, DIK_J, DIK_H, DIK_K);

}
