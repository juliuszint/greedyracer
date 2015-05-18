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

private:
	//CKeyboardController *kc_Cont;
	CPlacement * Character;
	CVehicle * Vehicle;
	CDeviceKeyboard * playerKeyboard;

};

