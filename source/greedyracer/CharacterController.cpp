

#include "CharacterController.h"


CCharacterController::CCharacterController()
{
	this->Character = NULL;
	this->Vehicle = NULL;
	this->faktSpeed = 0;
}


CCharacterController::~CCharacterController()
{
}

void CCharacterController::addKeyboard(CDeviceKeyboard * GameKeyboard)
{
	playerKeyboard = GameKeyboard;
}


void CCharacterController::addVehicle(CVehicle * Fahrzeug)
{
	this->Auto = Fahrzeug;
}

void CCharacterController::setKeybinding(int KeyUP, int KeyDOWN, int KeyLEFT, int KeyRIGHT)
{
	this->keyUP = KeyUP;
	this->keyDOWN = KeyDOWN;
	this->keyLEFT = KeyLEFT;
	this->keyRIGHT = KeyRIGHT;
}




void CCharacterController::Move(float DeltaTime)
{
	//int iSpeed = this->Auto->getaktSpeed();
	float fSpeed = this->getaktSpeed();


	static float angle_y = 0; 

	
	if (this->playerKeyboard->KeyPressed(keyUP))
	{
		if (fSpeed <= 20)
		{
			fSpeed += 1;
		}
		Character->TranslateDelta(sin(angle_y) * (fSpeed / 10), 0.0f, cos(angle_y) * (fSpeed / 10));

	}

	if (this->playerKeyboard->KeyPressed(keyDOWN))
	{
		if (fSpeed >= -7)
		{
			fSpeed -= 2.5;
		}
		Character->TranslateDelta(sin(angle_y) * (fSpeed / 10), 0.0f, cos(angle_y) * (fSpeed / 10));
		
	}

	if (!(this->playerKeyboard->KeyPressed(keyUP)) && !(this->playerKeyboard->KeyPressed(keyDOWN)))
	{
		if (fSpeed < 0){ fSpeed += 0.5; }
		else if (fSpeed > 0){ fSpeed -= 1; }
		Character->TranslateDelta(sin(angle_y) * (fSpeed / 10), 0.0f, cos(angle_y) *(fSpeed / 10));
	}

	this->UpdateSpeed(fSpeed);
	//this->Auto->UpdateSpeed(iSpeed);

	if (this->playerKeyboard->KeyPressed(keyLEFT) && (fSpeed != 0))
	{
		angle_y += 2  *DeltaTime;
		CHVector buffer;
		buffer = Character->GetTranslation();
		Character->TranslateDelta(-buffer);
		Character->RotateY((angle_y));
		Character->TranslateDelta(buffer);
	}

	if (this->playerKeyboard->KeyPressed(keyRIGHT)&&(fSpeed != 0))
	{
		angle_y -= 2  *DeltaTime;
		
		CHVector buffer;
		buffer = Character->GetTranslation();
		Character->TranslateDelta(-buffer);
			Character->RotateY((angle_y));
		Character->TranslateDelta(buffer);
		
	}

}