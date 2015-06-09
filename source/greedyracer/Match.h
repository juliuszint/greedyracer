#pragma once

#include "Vektoria\Root.h"
// #include "VektoriaMath\Util.h"
#include "stdafx.h"
#include "map\Map.h"
#include "map\entities\common\Camaro.h"
#include "CharacterController.h"
// #include "Game.h"


using namespace Vektoria;


class CMatch
{
private:
	
	CMap* map;
	CPlacement* mapPlacement;
	
	CCamaro* player1Vehicle;
	CGeo* player2Vehicle;

	CPlacement* player1Placement;
	CPlacement* player2Placement;


public:
	void Init(CMap* map);
	void Start();
	void Tick(float fTimeDelta);
	void Stop();

	CCharacterController Cont1;
	CDeviceKeyboard *m_pkeyboard;
	CMatch(CDeviceKeyboard * pkeyboard);
};

