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

	float TimePenalty;

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
	float countingDown;

	CScene* scene;
	CHud* hud;
	CMap* map;
	CPlacement* mapPlacement;
	CPlacement* cameraPlacement;
	CDeviceKeyboard *m_pkeyboard;
	CDeviceGameController* Contr1;
	CDeviceGameController* Contr2;
	CAudio countdownAudio;
	CAudio carsoundAudio;

	int playerCount = 2;
	PlayerData players[2];
	CHVector avLastPlacement[2];
	
	CAudio backgroundAudio;

	void ToggleCameraMode();
public:
	~CMatch();

	void Init(CDeviceKeyboard* keyboard, CMap* map, CPlacement* cameraPlacement, CHud* hud, CScene* scene, CDeviceGameController* Controller1, CDeviceGameController* Controller2);
	void Start();
	void Tick(float fTime, float fTimeDelta);
	void Stop();
};


