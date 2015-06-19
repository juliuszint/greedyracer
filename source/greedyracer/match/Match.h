#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"

#include "..\stdafx.h"
#include "..\map\Map.h"
#include "..\map\entities\common\Camaro.h"
#include "..\map\entities\common\Porsche.h"
#include "..\CharacterController.h"
#include "..\Hud.h"
#include <string>

// #include "Game.h"

using namespace std;
using namespace Vektoria;

struct PlayerData
{
public:
	CPlacement* CarPosition;
	CEntity* CarEntity;
	CCharacterController* Controller;

	string PlayerName;
	int LatestShortcutTrigger;
	int LatestCheckpointHit;
	int CheckpointCount;
	int RoundCount;

	int TimePenalty;

	PlayerData()
	{
		this->CarPosition = NULL;
		this->CarEntity = NULL;
		this->Controller = NULL;

		this->CheckpointCount = 0;
		this->LatestCheckpointHit = 0;
		this->TimePenalty = 0;
		this->LatestShortcutTrigger = 0;
		this->RoundCount = 0;
	}
};

class CMatch
{
private:
	bool running;
	bool cKeyReleased;
	bool fixedCameraMode;
	bool ended;

	CHud* hud;
	CMap* map;
	CPlacement* mapPlacement;
	CPlacement* cameraPlacement;
	CDeviceKeyboard *m_pkeyboard;

	int playerCount = 2;
	PlayerData players[2];
	CHVector avLastPlacement[2];
	
	void ToggleCameraMode();
public:
	void Init(CMap* map, CPlacement* cameraPlacement, CHud* hud);
	void Start();
	void Tick(float fTimeDelta);
	void Stop();

	CMatch(CDeviceKeyboard * pkeyboard);
};


