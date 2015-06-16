#include "Match.h"


CMatch::CMatch(CDeviceKeyboard * pkeyboard)
{
	m_pkeyboard = pkeyboard;
}

void CMatch::Tick(float fTimeDelta)
{
	Cont1.Move(fTimeDelta);
	Cont2.Move(fTimeDelta);

	MapCont = this->map->IsOnTrack(this->player1Placement->GetTranslation());
	Kontrollvar = this->map->IsOnCheckpoint(this->player1Placement->GetTranslation());
	Kontrollvar2 = 0;
}

void CMatch::Start()
{
	this->mapPlacement->AddPlacement(this->player1Placement);
	this->mapPlacement->AddPlacement(this->player2Placement);
	CHVector startPosition = this->map->GetStartPosition();

	this->player1Placement->TranslateDelta(startPosition);
	this->player2Placement->TranslateDelta(startPosition);
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
	//this->player1Placement->ScaleDelta(0.1f);
	this->player1Placement->TranslateYDelta(0.2f);

	this->player2Vehicle = new CPorsche();
	this->player2Vehicle->Init();
	this->player2Placement = this->player2Vehicle->GetRootPlacement();
	//this->player2Placement->ScaleDelta(0.1f);
	this->player2Placement->TranslateYDelta(0.2f);


	Cont1.addCharacter(this->player1Placement);
	Cont1.addKeyboard(m_pkeyboard);
	Cont1.setKeybinding(DIK_U, DIK_J, DIK_H, DIK_K);

	Cont2.addCharacter(this->player2Placement);
	Cont2.addKeyboard(m_pkeyboard);
	Cont2.setKeybinding(DIK_NUMPAD8, DIK_NUMPAD5, DIK_NUMPAD4, DIK_NUMPAD6);

}
