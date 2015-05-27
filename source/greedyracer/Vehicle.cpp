#include "Vehicle.h"


CVehicle::CVehicle()
{
	iMasse = 1700;
	fMotorleistung = 0;
	fAcceleration = 5.7917f;
	fDeceleration = 1.8f;
}


CVehicle::~CVehicle()
{
}

float CVehicle::getacceleration()
{
	return fAcceleration;
}

float CVehicle::getdeceleration()
{
	return fDeceleration;
}

int CVehicle::getaktSpeed()
{
	return iaktSpeed;
}

void CVehicle::UpdateSpeed(int iNeu)
{
	iaktSpeed = iNeu;
}
