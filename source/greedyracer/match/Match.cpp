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
		playerData->Controller->Move(fTimeDelta);

		// Note (julius): process movement
		int checkPoint = 0;
		if ((checkPoint = this->map->IsOnCheckpoint(playerPosition)) >= 0)
		{
			playerData->CheckpointCount++;
		}

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

		float zHeight = ((maxZCarDistance / 2) + 0.5) / tan(0.5625);
		float xHeight = ((maxXCarDistance / 2) + 0.5) / tan(1);
		float height = max(zHeight, xHeight);
		height = max(height, 5);

		float newCameraY = height - cameraPosition.y;

		this->cameraPlacement->TranslateYDelta(newCameraY);
	}
	else
	{
		this->m_pkeyboard->PlaceWASD(*this->cameraPlacement, fTimeDelta, true);
	}
	// Note (julius): player info update
	//char buffer[5];
	//sprintf(buffer, "%d", this->player1Data.CheckpointCount);
	//this->hud->SetRoundPlayer1(buffer);

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
		player->CarPosition->TranslateZDelta(startPosition.z);
		this->mapPlacement->AddPlacement(player->CarPosition);
	}

	this->cameraPlacement->Translate(CHVector(startPosition.x, 10, startPosition.z));
	this->cameraPlacement->SetPointing(new CHVector(startPosition.x, 1, startPosition.z));

	this->hud->SetPlayerName1("Player1");
	this->hud->SetPlayerName2("Player2");
	this->hud->SetRoundPlayer1("0");
	this->hud->SetRoundPlayer2("0");
	//this->hud->SetTime("00:05:00");
	this->hud->SetVisible(true);

	this->running = true;
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
	this->players[0].CarPosition = this->players[0].CarEntity->GetRootPlacement();
	this->players[0].Controller = new CCharacterController();
	this->players[0].Controller->addKeyboard(this->m_pkeyboard);
	this->players[0].Controller->setKeybinding(DIK_Z, DIK_H, DIK_G, DIK_J);
	this->players[0].Controller->addCharacter(this->players[0].CarPosition);

	this->players[1].CarEntity = new CPorsche();
	this->players[1].CarEntity->Init();
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