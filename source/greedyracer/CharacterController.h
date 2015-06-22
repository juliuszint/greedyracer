#pragma once



//#include "KeyboardController.h"
#include "Vektoria/Root.h"
#include "Vehicle.h"

using namespace Vektoria;

struct MovementSnapshot
{
	float timeTaken;
	float speed;
	float angle;
	CHVector position;
};

class CCharacterController
{
public:
	CCharacterController();
	~CCharacterController();

	void addCharacter(CPlacement *pCharacter){ Character = pCharacter; };
	void addKeyboard(CDeviceKeyboard *);
	void Move(float DeltaTime);
	void addVehicle(CVehicle * Fahrzeug);
	void addGameController(CDeviceGameController * XBOX360Cont);
	void setKeybinding(int KeyUP, int KeyDOWN, int KeyLEFT, int KeyRIGHT);
	void setSpeed(float fNewSpeed);
	void setAngle(float fNewAngle);

	void TakeSnapshot(float fTime);
	void Restore(float fTime);
private:
	
	int keyUP;
	int keyDOWN;
	int keyLEFT;
	int keyRIGHT;

	float fAcceleration;
	float fBrake;
	float fDeceleration;
	float fSteering_fact;

	float fSpeed;
	float angle_y;

	CPlacement * Character;
	CVehicle * Vehicle;
	CDeviceKeyboard * playerKeyboard;
	CVehicle * Auto;
	CDeviceGameController * Controller;

	MovementSnapshot snap[20];
	int snapshotCount;
	int snapshotIndex;
};

