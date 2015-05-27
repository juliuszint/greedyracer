#pragma once



//#include "KeyboardController.h"
#include "Vektoria/Root.h"
#include "Vehicle.h"

using namespace Vektoria;


class CCharacterController
{
public:
	CCharacterController();
	~CCharacterController();

	void addCharacter(CPlacement *pCharacter){ Character = pCharacter; };
	void addKeyboard(CDeviceKeyboard *);
	void Move(float DeltaTime);
	void addVehicle(CVehicle * Fahrzeug);
	void setKeybinding(int KeyUP, int KeyDOWN, int KeyLEFT, int KeyRIGHT);
	float getaktSpeed(){ return faktSpeed; };
	void UpdateSpeed(int iNeue) { faktSpeed = iNeue; };

private:
	
	int keyUP;
	int keyDOWN;
	int keyLEFT;
	int keyRIGHT;

	float faktSpeed;


	CPlacement * Character;
	CVehicle * Vehicle;
	CDeviceKeyboard * playerKeyboard;
	CVehicle * Auto;

};

