

#include "CharacterController.h"


CCharacterController::CCharacterController()
{
	this->Character = NULL;
	this->Vehicle = NULL;
	this->Controller = NULL;
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

void CCharacterController::addGameController(CDeviceGameController * XBOX360Cont)
{
	this->Controller = XBOX360Cont;
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
	float fSpeed = this->getaktSpeed();
	float fTimeFact = (1 / DeltaTime) / 2;

	if (this->playerKeyboard != NULL)
	{
		if (this->playerKeyboard->KeyPressed(keyUP) || this->Controller->ButtonPressed(0))
		{
			if (fSpeed <= 45)
			{
				fSpeed += fTimeFact / 5;
			}
			float fRelSpeed = this->factor * fSpeed;
			CHVector translation(sin(angle_y) * (fRelSpeed / 80), 0.0f, cos(angle_y) * (fRelSpeed / 80));
			Character->TranslateXDelta(translation.x);
			Character->TranslateZDelta(translation.z);
		}

		if (this->playerKeyboard->KeyPressed(keyDOWN) || this->Controller->ButtonPressed(1))
		{
			if (fSpeed >= -7)
			{
				fSpeed -= fTimeFact / 2.5;
			}
			float fRelSpeed = this->factor * fSpeed;
			CHVector translation(sin(angle_y) * (fRelSpeed / 80), 0.0f, cos(angle_y) * (fRelSpeed / 80));
			Character->TranslateXDelta(translation.x);
			Character->TranslateZDelta(translation.z);
		}

		if ((!(this->playerKeyboard->KeyPressed(keyUP)) && !(this->playerKeyboard->KeyPressed(keyDOWN))) && (!(this->Controller->ButtonPressed(0)) && !(this->Controller->ButtonPressed(1))))
		{
			if (fSpeed < 0){ fSpeed += fTimeFact / 100; }
			else if (fSpeed > 0){ fSpeed -= 0.0001; }

			float fRelSpeed = this->factor * fSpeed;
			CHVector translation(sin(angle_y) * (fRelSpeed / 80), 0.0f, cos(angle_y) *(fRelSpeed / 80));

			Character->TranslateXDelta(translation.x);
			Character->TranslateZDelta(translation.z);
		}

		this->UpdateSpeed(fSpeed);

		if (this->playerKeyboard->KeyPressed(keyLEFT) && (fSpeed != 0))
		{
			float faAngle = UM_DEG2RAD(25 * this->factor);

			if (fSpeed > 0)
			{

				angle_y += faAngle / (fSpeed / (fTimeFact * 500) + 1);
			}
			else if (fSpeed < 0)
			{
				angle_y -= faAngle / (fSpeed / (fTimeFact * 500) + 1);

			}

			CHVector buffer;
			buffer = Character->GetTranslation();

			Character->TranslateDelta(-buffer);
			Character->RotateY((angle_y));
			Character->ScaleDelta(0.1f);
			Character->TranslateDelta(buffer);

		}

		if (this->playerKeyboard->KeyPressed(keyRIGHT) && (fSpeed != 0))
		{
			float faAngle = -UM_DEG2RAD(25 * this->factor);

			if (fSpeed > 0)
			{
				angle_y += faAngle / ((fSpeed / (fTimeFact * 500) + 1));
			}
			else if (fSpeed < 0)
			{
				angle_y -= faAngle / ((fSpeed / (fTimeFact * 500) + 1));
			}

			CHVector buffer;
			buffer = Character->GetTranslation();

			Character->TranslateDelta(-buffer);
			Character->RotateY((angle_y));
			Character->ScaleDelta(0.1f);
			Character->TranslateDelta(buffer);
		}
	}

	//ControllerSteuerung
	if (this->Controller != NULL)
	{
		//Links-Rechts

		float faAngle = this->Controller->GetRelativeX() * DeltaTime * 0.7;
		if (fSpeed > 0)
		{
			angle_y -= faAngle / ((fSpeed / (fTimeFact * 500) + 0.5));
		}
		else if (fSpeed < 0)
		{
			angle_y += faAngle / ((fSpeed / (fTimeFact * 500) + 0.5));
		}

		CHVector buffer;
		buffer = Character->GetTranslation();

		Character->TranslateDelta(-buffer);
		Character->RotateY((angle_y));
		Character->ScaleDelta(0.1f);
		Character->TranslateDelta(buffer);
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
