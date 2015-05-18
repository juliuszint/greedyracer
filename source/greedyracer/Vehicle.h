#pragma once



class CVehicle
{
public:
	//CVehicle(int imass, float fLeistung, float fO_IOODauer);
	CVehicle(int imass, float fLeistung);
	~CVehicle();

	int getaktSpeed();
	float getdeceleration();
	float getacceleration();
	int UpdateSpeed();


private:

	//Porsche 350PS, 257kW, a=5,7917 m/(s*s)
	// 1kW = 1,3596216PS -> P= AnzPS / 1,3596216

	int iMasse;
	float fMotorleistung;
	//float fBeschldauerO_IOO;
	

	int iaktSpeed;
	float fAcceleration;
	float fDeceleration;
	

};

