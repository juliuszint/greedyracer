

#include "CharacterController.h"


CCharacterController::CCharacterController()
{
	this->Character = NULL;
	this->Vehicle = NULL;
	this->faktSpeed = 0;
	this->factor = .08f;
	this->angle_y = 0;
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

	if (this->playerKeyboard->KeyPressed(keyUP))
	{
		if (fSpeed <= 20)
		{
			fSpeed += 1;
		}
		float fRelSpeed = this->factor * fSpeed;
		CHVector translation(sin(angle_y) * (fRelSpeed / 10), 0.0f, cos(angle_y) * (fRelSpeed / 10));
		Character->TranslateXDelta(translation.x);
		Character->TranslateZDelta(translation.z);
	}

	if (this->playerKeyboard->KeyPressed(keyDOWN))
	{
		if (fSpeed >= -7)
		{
			fSpeed -= 2.5;
		}
		float fRelSpeed = this->factor * fSpeed;
		CHVector translation(sin(angle_y) * (fRelSpeed / 10), 0.0f, cos(angle_y) * (fRelSpeed / 10));
		Character->TranslateXDelta(translation.x);
		Character->TranslateZDelta(translation.z);
	}

	if (!(this->playerKeyboard->KeyPressed(keyUP)) && !(this->playerKeyboard->KeyPressed(keyDOWN)))
	{
		if (fSpeed < 0){ fSpeed += 0.5; }
		else if (fSpeed > 0){ fSpeed -= 1; }

		float fRelSpeed = this->factor * fSpeed;
		CHVector translation(sin(angle_y) * (fRelSpeed / 10), 0.0f, cos(angle_y) *(fRelSpeed / 10));

		Character->TranslateXDelta(translation.x);
		Character->TranslateZDelta(translation.z);
	}

	this->UpdateSpeed(fSpeed);
	//this->Auto->UpdateSpeed(iSpeed);

	if (this->playerKeyboard->KeyPressed(keyLEFT) && (fSpeed != 0))
	{
		float faAngle = UM_DEG2RAD(25 * this->factor);
		
		if (fSpeed > 0)
		{
			angle_y += faAngle;
		}
		else if (fSpeed < 0)
		{
			angle_y -= faAngle;
		}

		CHVector buffer;
		buffer = Character->GetTranslation();

		Character->TranslateDelta(-buffer);
		Character->RotateY((angle_y));
		Character->ScaleDelta(0.1f);
		Character->TranslateDelta(buffer); 
		//Character->RotateYDelta(angle_y);
/*=======
		//Character->TranslateDelta(-buffer);

		Character->TranslateXDelta(-buffer.x);
		Character->TranslateZDelta(-buffer.z);

		Character->RotateYDelta(faAngle);

		Character->TranslateXDelta(buffer.x);
		Character->TranslateZDelta(buffer.z);

		//Character->TranslateDelta(buffer);
>>>>>>> origin/master*/
	}

	if (this->playerKeyboard->KeyPressed(keyRIGHT) && (fSpeed != 0))
	{
		float faAngle = -UM_DEG2RAD(25 * this->factor);
		
		if (fSpeed > 0)
		{
			angle_y += faAngle;
		}
		else if (fSpeed < 0)
		{
			angle_y -= faAngle;
		}

		CHVector buffer;
		buffer = Character->GetTranslation();

		Character->TranslateDelta(-buffer);
		Character->RotateY((angle_y));
		Character->ScaleDelta(0.1f);
		Character->TranslateDelta(buffer); 
		//Character->RotateYDelta(angle_y);
		
/*=======
		// Character->TranslateDelta(-buffer);

		Character->TranslateXDelta(-buffer.x);
		Character->TranslateZDelta(-buffer.z);

		Character->RotateYDelta(faAngle);

		Character->TranslateXDelta(buffer.x);
		Character->TranslateZDelta(buffer.z);
		//Character->TranslateDelta(buffer);

>>>>>>> origin/master*/
	}

}

void CCharacterController::UpdateAngle(int iChangeValueRAD)
{
	this->angle_y += iChangeValueRAD;
}

void CCharacterController::UpdateFactor(float factor)
{
	this->factor = factor;
}
