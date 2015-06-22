#include "CharacterController.h"


CCharacterController::CCharacterController()
{
	this->Character = NULL;
	this->Vehicle = NULL;
	this->Controller = NULL;
	this->fAcceleration = 6.0;
	this->fBrake = 15.0;
	this->fDeceleration = 3;
	this->fSteering_fact = 0.3;
	this->angle_y = -0.05*PI;
	this->fSpeed = 0;
	this->snapshotIndex = -1;

	for (int i = 0; i < this->snapshotCount; i++)
	{
		this->snap[i].isValid = false;
	}
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
	float fDistance = 0;
	float fActAccel = 0;

	if (this->playerKeyboard != NULL)
	{
		if (this->playerKeyboard->KeyPressed(keyUP) || this->Controller->ButtonPressed(0))
		{
			//ULDebug("Key UP!");
			if (fSpeed < 10)
				fActAccel = fAcceleration;
		}

		else if (this->playerKeyboard->KeyPressed(keyDOWN) || this->Controller->ButtonPressed(1))
		{
			//ULDebug("Key DOWN!");
			if (fSpeed > -2)
				fActAccel = -fBrake;
		}

		else if ((!(this->playerKeyboard->KeyPressed(keyUP)) && !(this->playerKeyboard->KeyPressed(keyDOWN))) && (!(this->Controller->ButtonPressed(0)) && !(this->Controller->ButtonPressed(1))))

		{
			//ULDebug("NO Key!");

			if (fSpeed < 0)
				fActAccel = fDeceleration;
			else if (fSpeed > 0)
				fActAccel = -fDeceleration;
		}

		else{
			fActAccel = 0;
		}

		fSpeed += fActAccel * DeltaTime;
		fDistance = fSpeed * DeltaTime;

		CHVector translation(sin(angle_y) * (fDistance), 0.0f, cos(angle_y) * (fDistance));
		Character->TranslateXDelta(translation.x);
		Character->TranslateZDelta(translation.z);



		if (this->playerKeyboard->KeyPressed(keyLEFT) && ((fSpeed > 0.5) || (fSpeed < -0.5)))
		{
			float faAngle = UM_DEG2RAD(25);

			if (fSpeed > 0.5)
			{
				angle_y += faAngle / fSteering_fact * DeltaTime;
			}
			else if (fSpeed < -0.5)
			{
				angle_y -= faAngle / fSteering_fact * DeltaTime;
			}

			CHVector buffer;
			buffer = Character->GetTranslation();

			Character->TranslateDelta(-buffer);
			Character->RotateY((angle_y));
			Character->ScaleDelta(0.1f);
			Character->TranslateDelta(buffer);

		}

		if (this->playerKeyboard->KeyPressed(keyRIGHT) && ((fSpeed > 0.5) || (fSpeed < -0.5)))

		{
			float faAngle = -UM_DEG2RAD(25);

			if (fSpeed > 0.5)
			{
				angle_y += faAngle / fSteering_fact * DeltaTime;
			}
			else if (fSpeed < -0.5)
			{
				angle_y -= faAngle / fSteering_fact* DeltaTime;
			}

			CHVector buffer;
			buffer = Character->GetTranslation();

			Character->TranslateDelta(-buffer);
			Character->RotateY((angle_y));
			Character->ScaleDelta(0.1f);
			Character->TranslateDelta(buffer);
		}

		if (this->Controller != NULL)
		{
			//Links-Rechts

			if ((fSpeed > 0.5) || (fSpeed < -0.5))

			{
				float faAngle = this->Controller->GetRelativeX();
				if ((faAngle <= -0.2) || (faAngle >= 0.2))
				{
					if (fSpeed > 0.5)
					{
						angle_y -= faAngle / fSteering_fact * DeltaTime;
					}
					else if (fSpeed < 0.5)
					{
						angle_y += faAngle / fSteering_fact * DeltaTime;
					}

					CHVector buffer;
					buffer = Character->GetTranslation();

					Character->TranslateDelta(-buffer);
					Character->RotateY((angle_y));
					Character->ScaleDelta(0.1f);
					Character->TranslateDelta(buffer);
				}
			}

		}

	}
}

void CCharacterController::setSpeed(float fNewSpeed){
	fSpeed = fNewSpeed;
}

void CCharacterController::setAngle(float fNewAngle){
	angle_y = fNewAngle;
}


void CCharacterController::TakeSnapshot(float fTime)
{
	int newIndex = ++this->snapshotIndex % this->snapshotCount;
	this->snap[newIndex].angle = this->angle_y;
	this->snap[newIndex].speed = 0;//this->fSpeed;
	this->snap[newIndex].position = this->Character->GetTranslation();
	this->snap[newIndex].isValid = true;
	this->snap[newIndex].timeTaken = fTime;
}

void CCharacterController::Restore(float fTime)
{
	MovementSnapshot firstValid;
	firstValid.isValid = false;
	MovementSnapshot recoverSnap;
	recoverSnap.isValid = false;
	recoverSnap.timeTaken = fTime;

	for (int i = 1; i <= this->snapshotCount; i++)
	{
		int index = (this->snapshotIndex + i) % this->snapshotCount;
		if (this->snap[index].isValid)
		{
			if (!firstValid.isValid) firstValid = this->snap[index];

			if (((fTime - this->snap[index].timeTaken) * 1000) <= 700)
			{
				recoverSnap = this->snap[index];
				break;
			}
		}
	}
	if (!recoverSnap.isValid)
		recoverSnap = firstValid;

	this->angle_y = recoverSnap.angle;
	this->fSpeed = recoverSnap.speed;
	CHVector delta = recoverSnap.position - this->Character->GetTranslation();
	this->Character->TranslateDelta(delta);
}
