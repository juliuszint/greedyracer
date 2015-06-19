#include "Match.h"


CMatch::CMatch(CDeviceKeyboard * pkeyboard)
{
	m_pkeyboard = pkeyboard;
}

void CMatch::Tick(float fTimeDelta)
{
	if (this->running == false) return;

	CHVector carCenterPosition;
	float maxXCarDistance = 0;
	float maxZCarDistance = 0;
	for (int i = 0; i < this->playerCount; i++)
	{
		PlayerData* playerData = &this->players[i];
		CHVector playerPosition = playerData->CarPosition->GetTranslation();

		// Note (julius): move
		if (!ended)
		{
			playerData->Controller->Move(fTimeDelta);
		}

		/*
		// Note (Michael): Collision detection among cars
		for (int j = 0; j < this->playerCount; j++)
		{
			PlayerData* otherPlayer = &this->players[j];
			if (playerData->CarPosition->IsColliding(otherPlayer->CarPosition))
			{
				CHVector vPos = playerData->CarPosition->m_amGlobal[0].GetTranslation();
				CHVector vDirFront = playerData->CarPosition->m_amGlobal[0] * CHVector(0.0f, 0.0f, -1.0, 0.0f);
				CHVector vDirRear = playerData->CarPosition->m_amGlobal[0] * CHVector(0.0f, 0.0f, 1.0f, 0.0f);
				CHVector vDirLeft = playerData->CarPosition->m_amGlobal[0] * CHVector(-1.0f, 0.0f, 0.0f, 0.0f);
				CHVector vDirRight = playerData->CarPosition->m_amGlobal[0] * CHVector(1.0f, 0.0f, 0.0f, 0.0f);

				CRay rFront(vPos, vDirFront, QUASI_ZERO, F_MAX);
				CRay rRear(vPos, vDirFront, QUASI_ZERO, F_MAX);
				CRay rLeft(vPos, vDirFront, QUASI_ZERO, F_MAX);
				CRay rRight(vPos, vDirFront, QUASI_ZERO, F_MAX);

				if (otherPlayer->CarPosition->IsIntersecting(rFront))
				{
					float fSpeedbuffer = playerData->Controller->getaktSpeed();
					playerData->Controller->UpdateSpeed(otherPlayer->Controller->getaktSpeed());
					otherPlayer->Controller->UpdateSpeed(fSpeedbuffer);
				}
				else if (otherPlayer->CarPosition->IsIntersecting(rRear))
				{
					float fSpeedbuffer = otherPlayer->Controller->getaktSpeed();
					otherPlayer->Controller->UpdateSpeed(playerData->Controller->getaktSpeed());
					playerData->Controller->UpdateSpeed(fSpeedbuffer);
				}
				else if (otherPlayer->CarPosition->IsIntersecting(rLeft))
				{
					otherPlayer->Controller->UpdateAngle(0.2);
					playerData->Controller->UpdateAngle(-0.2);
				}
				else if (otherPlayer->CarPosition->IsIntersecting(rRight))
				{
					otherPlayer->Controller->UpdateAngle(-0.2);
					playerData->Controller->UpdateAngle(0.2);
				}

			}
		}*/

		// Note (julius): process movement
		CHVector isOnTrack = this->map->IsOnTrack(playerPosition);
		
		if (isOnTrack != CHVector(1.0f, 1.0f, 1.0f))
		{
			this->avLastPlacement[i] = isOnTrack;
		}
		
		if (isOnTrack == CHVector(1.0f, 1.0f, 1.0f))
		{
			//CHVector delta = isOnTrack - playerPosition;
			CHVector delta = avLastPlacement[i] - playerPosition;
			playerData->CarPosition->TranslateDelta(delta + +CHVector(0.0f, 0.255f, 0.0f, 0.0f));
			
		}

		int checkPoint = 0;
		if ((checkPoint = this->map->IsOnCheckpoint(playerPosition)) >= 0 &&
			checkPoint > playerData->CheckpointCount)
		{
			playerData->CheckpointCount++;
		}

		if (playerData->CheckpointCount >= 5 && this->map->IsOnFinish(playerPosition))
		{
			playerData->RoundCount++;
			playerData->CheckpointCount = 0;
		}
		if (playerData->RoundCount == 3)
		{
			ended = true;
			this->hud->SetWinningBanner(playerData->PlayerName);
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
	CHVector startPosition = this->map->GetStartPosition();
	for (int i = 0; i < this->playerCount; i++)
	{
		PlayerData* player = &this->players[i];
		player->CarPosition->TranslateXDelta(startPosition.x + i);
		player->CarPosition->TranslateYDelta(startPosition.y);
		player->CarPosition->TranslateZDelta(startPosition.z);
		this->mapPlacement->AddPlacement(player->CarPosition);
	}
	
	this->cameraPlacement->Translate(CHVector(startPosition.x, 10, startPosition.z));
	this->cameraPlacement->SetPointing(new CHVector(startPosition.x, 1, startPosition.z));

	this->hud->SetPlayerName1(this->players[0].PlayerName);
	this->hud->SetPlayerName2(this->players[1].PlayerName);
	this->hud->SetRoundPlayer1("0");
	this->hud->SetRoundPlayer2("0");
	//this->hud->SetTime("00:05:00");
	this->hud->SetVisible(true);

	this->running = true;
	this->ended = false;
}

void CMatch::Stop()
{
	this->running = false;

	this->hud->SetVisible(false);

	for (int i = 0; i < this->playerCount; i++)
	{
		this->mapPlacement->SubPlacement(this->players[i].CarPosition);
		free(this->players[i].CarEntity);
	}
}

void CMatch::Init(CMap* map, CPlacement* cameraPlacement, CHud* hud)
{
	this->hud = hud;
	this->map = map;
	this->cameraPlacement = cameraPlacement;
	this->mapPlacement = this->map->GetRootPlacement();

	this->fixedCameraMode = true;
	this->cKeyReleased = true;

	this->players[0].CarEntity = new CCamaro();
	this->players[0].CarEntity->Init();
	this->players[0].PlayerName = "Player 1";
	this->players[0].CarPosition = this->players[0].CarEntity->GetRootPlacement();
	this->players[0].Controller = new CCharacterController();
	this->players[0].Controller->addKeyboard(this->m_pkeyboard);
	this->players[0].Controller->setKeybinding(DIK_Y, DIK_H, DIK_G, DIK_J);
	this->players[0].Controller->addCharacter(this->players[0].CarPosition);

	this->players[1].CarEntity = new CPorsche();
	this->players[1].CarEntity->Init();
	this->players[1].PlayerName = "Player 2";
	this->players[1].CarPosition = this->players[1].CarEntity->GetRootPlacement();
	this->players[1].Controller = new CCharacterController();
	this->players[1].Controller->addKeyboard(this->m_pkeyboard);
	this->players[1].Controller->setKeybinding(DIK_O, DIK_L, DIK_K, DIK_SEMICOLON);
	this->players[1].Controller->addCharacter(this->players[1].CarPosition);

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