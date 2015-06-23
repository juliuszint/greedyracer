#include "Match.h"

CMatch::~CMatch()
{
	for (int i = 0; i < this->playerCount; i++)
	{
		free(this->players[i].Controller);
		free(this->players[i].CarEntity);
	}
}

void CMatch::Tick(float fTime, float fTimeDelta)
{
	static bool firstTickAfterCountdown = false;
	if (this->running == false) return;
	if (fTimeDelta > 1) return;

	// Note (julius): da muss irgendwo noch ein komischer bug drin
	// sein wenns um die fTimeDelta geht weil wenn die überprüfung auf <0
	// nicht drin ist endet der timer softort
	if (this->countingDown > 0)
	{
		int timer = (int)this->countingDown + 1;
		char buffer[3];
		sprintf(buffer, "%d", timer);
		this->hud->SetCountdown(buffer);

		this->countingDown -= fTimeDelta;
	}
	else
	{
		if (!firstTickAfterCountdown)
		{
			this->countdownAudio.Stop();
			this->backgroundAudio.Start();
			this->hud->SetCountdown("");

			for (int i = 0; i < this->playerCount; i++)
				this->players[i].Controller->TakeSnapshot(fTime);

			firstTickAfterCountdown = true;
		}

		CHVector carCenterPosition;
		float maxXCarDistance = 0;
		float maxZCarDistance = 0;
		for (int i = 0; i < this->playerCount; i++)
		{
			PlayerData* playerData = &this->players[i];
			CHVector playerPosition = playerData->CarPosition->GetTranslation();


			// Note (julius): move
			if (!ended && playerData->TimePenalty <= 0)
			{
				playerData->Controller->Move(fTimeDelta);
			}
			if (playerData->TimePenalty > 0)
			{
				playerData->TimePenalty -= fTimeDelta;
			}

			CHVector isOnTrack;
			int checkPoint = 0;
			bool validPosition = false;
			int shortCutTrigger = this->map->IsOnShortcutTrigger(playerPosition);

			// Note (julius): is on shortcutTrigge?
			if (shortCutTrigger > 0 && shortCutTrigger != playerData->LatestShortcutTrigger)
			{
				CShortcutData* data = this->map->GetShortcut(shortCutTrigger - 1);

				if (data->ActiveTime <= 0)
				{
					// Note (julius): trigger wasnt active 
					int chance = rand() % 100 + 1;
					if (chance <= data->ChancePrecentage)
					{
						data->CollisionPlacement->SwitchOn();
						data->ActiveTime = data->MaxActiveTime;
					}
				}
				playerData->TimePenalty = data->ActiveTime;
				if (data->ActiveTime > 0)
				{
					playerData->Controller->setSpeed(0);
				}
				playerData->LatestShortcutTrigger = shortCutTrigger;
			}

			// Note (julius): is on checkpoint?
			else if ((checkPoint = this->map->IsOnCheckpoint(playerPosition)) >= 0)
			{
				if (checkPoint > playerData->CheckpointCount)
				{
					playerData->CheckpointCount++;
				}
				validPosition = true;
			}

			// Note (julius): is on start?
			else if (this->map->IsOnFinish(playerPosition))
			{
				if (playerData->CheckpointCount >= 5)
				{
					playerData->RoundCount++;
					playerData->CheckpointCount = 0;
					playerData->LatestShortcutTrigger = 0;
				}
				validPosition = true;
			}

			// Note (julius): is on track?
			else if ((isOnTrack = this->map->IsOnTrack(playerPosition)) == CHVector(1, 1, 1))
			{
				// Note (julius): spieler befindet sich nichtmehr auf der zulässigen strecke
				// wiederherstellen auf vorherige position
				playerData->Controller->Restore(fTime);
			}
			else
			{
				validPosition = true;
			}

			if (validPosition)
			{
				if (((int)(fTime * 1000) % 200) < 30)
				{
					// Note (julius): alle 200ms wenn der spieler auf der Strecke
					// ist n snapshot machen von aktuellen position den spielers
					playerData->Controller->TakeSnapshot(fTime);
				}
			}

			// Note (julius): process movement

			if (playerData->RoundCount == 3)
			{
				ended = true;
				char buff[100];
				sprintf(buff, "%s gewinnt", playerData->PlayerName.data());
				this->hud->SetWinningBanner(buff);
			}

			// Note (julius): player info update
			char buffer[100];
			sprintf(buffer, "%d", playerData->RoundCount);
			this->hud->SetRound(buffer, i);

			// Note (julius): camera support code
			carCenterPosition.SetX(carCenterPosition.x + playerPosition.x + i);
			carCenterPosition.SetZ(carCenterPosition.z + playerPosition.z);

			CHVector flatPPosi(playerPosition.x, 0, playerPosition.z);
			for (int i = 0; i < this->playerCount; i++)
			{
				CHVector testPosi = this->players[i].CarPosition->GetTranslation();
				CHVector flatTestPosi(testPosi.x, 0, testPosi.z);
				maxXCarDistance = max(maxXCarDistance, (flatPPosi.x - flatTestPosi.x));
				maxZCarDistance = max(maxZCarDistance, (flatPPosi.z - flatTestPosi.z));
			}
		}

		// Note (julius) reposition camera
		carCenterPosition.SetX(carCenterPosition.x / this->playerCount);
		carCenterPosition.SetZ(carCenterPosition.z / this->playerCount);
		static int counter = 0;
		if (fixedCameraMode)
		{
			CHVector cameraPosition = this->cameraPlacement->GetTranslation();
			CHVector flatCamPosition = CHVector(cameraPosition.x, 0, cameraPosition.z);
			CHVector dist = carCenterPosition - flatCamPosition;

			this->cameraPlacement->TranslateXDelta(dist.x);
			this->cameraPlacement->TranslateZDelta(dist.z);
			CHVector newCameraP = this->cameraPlacement->GetTranslation();
			this->cameraPlacement->SetPointing(new CHVector(newCameraP.x, 1, newCameraP.z));

			float zHeight = ((maxZCarDistance / 2) + 5) / tan(0.5625);
			float xHeight = ((maxXCarDistance / 2) + 5) / tan(1);
			float height = max(zHeight, xHeight);
			height = max(height, 5);

			float newCameraY = height - cameraPosition.y;

			this->cameraPlacement->TranslateYDelta(newCameraY);
		}
		else
		{
			this->m_pkeyboard->PlaceWASD(*this->cameraPlacement, fTimeDelta, true);
		}
	}

	// Note (julius): bei jedem tick timer für die abkürzungen runter zu zählen

	for (int i = 0; i < this->map->ShortcutCount; i++)
	{
		CShortcutData* data = this->map->GetShortcut(i);
		data->ActiveTime -= fTimeDelta;

		if (data->ActiveTime <= 0)
		{
			data->CollisionPlacement->SwitchOff();
		}
	}



	// Note (julius): für debug zwecke hab ich hier ein kleine code schnipsel reingemacht
	// der es möglich macht das man zwischen 2 kamera modi hin und her springt. 1 der freie modus
	// für die entwicklung und 2 der feste modus wo die kamera fix ausgerichtet ist. 
	// getoggeld wird das ganze mit C
	if (this->m_pkeyboard->KeyPressed(DIK_C))
	{
		if (cKeyReleased)
		{
			cKeyReleased = false;
			this->ToggleCameraMode();
			OutputDebugStringA("C Pressed Toggled Camera mode\n");
		}
	}
	else
	{
		if (!cKeyReleased)
		{
			cKeyReleased = true;
			OutputDebugStringA("C Released\n");
		}
	}
}

void CMatch::Start()
{
	// Note (julius): add player placements
	MapPositions startPositions = this->map->GetStartPosition();
	float camX;
	float camZ;
	for (int i = 0; i < this->playerCount; i++)
	{
		PlayerData* player = &this->players[i];
		MapPosition* p = &startPositions.Positions[i];

		camX = p->position.x;
		camZ = p->position.z;

		player->CarPosition->RotateYDelta(p->directionAngle);
		player->CarPosition->TranslateXDelta(p->position.x);
		player->CarPosition->TranslateYDelta(p->position.y);
		player->CarPosition->TranslateZDelta(p->position.z);

		this->mapPlacement->AddPlacement(player->CarPosition);
	}

	this->cameraPlacement->Translate(CHVector(camX, 8, camZ));
	this->cameraPlacement->SetPointing(new CHVector(camX, 1, camZ));

	this->hud->SetPlayerName1(this->players[0].PlayerName);
	this->hud->SetPlayerName2(this->players[1].PlayerName);
	this->hud->SetRoundPlayer1("0");
	this->hud->SetRoundPlayer2("0");
	this->hud->SetVisible(true);

	this->countdownAudio.Start();

	this->countingDown = 4;
	this->running = true;
	this->ended = false;
}

void CMatch::Stop()
{
	this->running = false;

	this->hud->SetVisible(false);
	this->hud->SetPlayerName1("");
	this->hud->SetPlayerName2("");
	this->hud->SetRoundPlayer1("");
	this->hud->SetRoundPlayer2("");
	this->hud->SetWinningBanner("");

	// Todo (julius): cleanup abkürzungen

	for (int i = 0; i < this->playerCount; i++)
	{
		this->mapPlacement->SubPlacement(this->players[i].CarPosition);
	}
	this->scene->SubAudio(&this->backgroundAudio);
	this->scene->SubAudio(&this->countdownAudio);
}



void CMatch::Init(CDeviceKeyboard* keyboard, CMap* map, CPlacement* cameraPlacement, CHud* hud, CScene* scene, CDeviceGameController* Controller1, CDeviceGameController* Controller2)
{
	this->m_pkeyboard = keyboard;
	this->scene = scene;
	this->hud = hud;
	this->map = map;
	this->cameraPlacement = cameraPlacement;
	this->mapPlacement = this->map->GetRootPlacement();
	this->Contr1 = Controller1;
	this->Contr2 = Controller2;

	this->fixedCameraMode = true;
	this->cKeyReleased = true;

	this->players[0].CarEntity = new CCamaro();
	this->players[0].CarEntity->Init();
	this->players[0].PlayerName = "Player 1";
	this->players[0].CarPosition = this->players[0].CarEntity->GetRootPlacement();
	this->players[0].Controller = new CCharacterController();
	this->players[0].Controller->addKeyboard(this->m_pkeyboard);
	this->players[0].Controller->addGameController(Contr1);
	//this->players[0].Controller->setKeybinding(DIK_W, DIK_S, DIK_A, DIK_D);
	this->players[0].Controller->setKeybinding(DIK_Y, DIK_H, DIK_G, DIK_J);
	this->players[0].Controller->addCharacter(this->players[0].CarPosition);

	this->players[1].CarEntity = new CPorsche();
	this->players[1].CarEntity->Init();
	this->players[1].PlayerName = "Player 2";
	this->players[1].CarPosition = this->players[1].CarEntity->GetRootPlacement();
	this->players[1].Controller = new CCharacterController();
	this->players[1].Controller->addKeyboard(this->m_pkeyboard);
	this->players[1].Controller->addGameController(Contr2);
	this->players[1].Controller->setKeybinding(DIK_O, DIK_L, DIK_K, DIK_SEMICOLON);
	this->players[1].Controller->addCharacter(this->players[1].CarPosition);

	this->countdownAudio.Init("sound\\countdown.wav");
	this->countdownAudio.SetVolume(.7f);
	this->scene->AddAudio(&this->countdownAudio);

	this->backgroundAudio.Init("sound\\IngameSound.WAV");
	this->backgroundAudio.SetVolume(.8f);
	this->scene->AddAudio(&this->backgroundAudio);

	this->running = false;
}

void CMatch::ToggleCameraMode()
{
	if (fixedCameraMode)
	{
		this->cameraPlacement->SetPointingOff();
	}
	fixedCameraMode = !fixedCameraMode;
}