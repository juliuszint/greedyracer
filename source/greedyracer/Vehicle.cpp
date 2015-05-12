#include "Vehicle.h"


CVehicle::CVehicle(int imass, float fLeistung)
{
	iMasse = imass;
	fMotorleistung = fLeistung;
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

int CVehicle::UpdateSpeed()
{
	return 0;
}
