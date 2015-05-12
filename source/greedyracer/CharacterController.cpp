

#include "CharacterController.h"


CCharacterController::CCharacterController()
{
	this->Character = NULL;
	this->Vehicle = NULL;
}


CCharacterController::~CCharacterController()
{
}

void CCharacterController::addKeyboard(CDeviceKeyboard * GameKeyboard)
{
	playerKeyboard = GameKeyboard;
}


//void CCharacterController::addCharacter(CPlacement * pCharacter)
//{
//	Character = &pCharacter;
//}

//void CCharacterController::addKeyboard()
//{
//	this->kc_Cont = Controller;
//}

//TODO	Tastenzuweisung einfügen


void CCharacterController::Move(float DeltaTime)
{

	//		| C  0  D |			| 1  0  0 |			| E -F  0 |			| 0  1  2  3 |		| fx00 fx01 fx02 fx03 |
	//	Y = | 0  1  0 |		X =	| 0  A -B |		Z = | F  E  0 |		M = | 4  5  6  7 |	=	| fx10 fx11 fx12 fx13 |
	//		|-D  0  C |			| 0  B  A |			| 0  0  1 |			| 8  9 10 11 |		| fx20 fx21 fx22 fx23 |
	//																	|12 13 14 15 |		| fx30 fx31 fx32 fx33 |

static float angle_y = 0; 

//Winkel aus Matrix rechnen (unnötig)
//	float fradians = 180 / PI;
//  static float angle_y = asin(Character->m_mLocal.m_fx02);	//Y-Winkel berechnen
//	float C = cos(angle_y);
//	
//	float tr_x;
//	float tr_y;
//	float angle_x;
//	float angle_z;
//	
//	angle_y *= fradians;
//	if (fabs(C) > 0.005)								//Abfrage ob Gimbal Lock auftritt
//	{
//		tr_x = Character->m_mLocal.m_fx22 / C;			//x-Achsen Winkel berechnen
//		tr_y = -(Character->m_mLocal.m_fx12) / C;
//		angle_x = atan2(tr_y, tr_x) * fradians;
//		tr_x = Character->m_mLocal.m_fx00 / C;			//z-Achsen Winkel berechnen
//		tr_y = -(Character->m_mLocal.m_fx01) / C;
//		angle_z = atan2(tr_y, tr_x) * fradians;
//	}
//	else												//Gimbal Lock aufgetreten
//	{
//		angle_x = 0;									//x-Achse auf Null setzen
//		tr_x = Character->m_mLocal.m_fx11;				// und z-Achsen Winkel berechnen
//		tr_y = Character->m_mLocal.m_fx10;
//		angle_z = atan2(tr_y, tr_x) * fradians;
//	}
//
//	
//	
//	//Winkel in Bogenmaß umrechnen
//	angle_x *= (PI / 180);
//	angle_y *= (PI / 180);
//	angle_z *= (PI / 180);
//
//	CHVector Meins = Character->GetTranslation();
//
//	float angle_y_dec = angle_y * (PI / 180);
//
//
	if (this->playerKeyboard->KeyPressed(DIK_U))
	{
		Character->TranslateDelta(sin(angle_y), 0.0f, cos(angle_y));
		//Character->TranslateDelta(fxRot * 10 * DeltaTime, fyRot * 10 * DeltaTime, fzRot * 10 * DeltaTime);
	}

	if (this->playerKeyboard->KeyPressed(DIK_J))
	{
		
		Character->TranslateDelta(-sin(angle_y), 0.0f, -cos(angle_y));
		//Character->TranslateDelta(-fxRot * 10 * DeltaTime, -fyRot * 10 * DeltaTime, -fzRot * 10 * DeltaTime);
	}

	if (this->playerKeyboard->KeyPressed(DIK_H))
	{
		angle_y += 0.2  *DeltaTime;
	}

	if (this->playerKeyboard->KeyPressed(DIK_K))
	{
		angle_y -= 0.2  *DeltaTime;
		/*
		CHVector buffer;
		buffer = Character->GetTranslation();
		Character->TranslateDelta(-buffer);
			Character->RotateYDelta(-0.1);
		Character->TranslateDelta(buffer);
		//Character->Rotate(0.0f, 1.0f, 0.0f, -(DeltaTime * 1));
		*/
	}

}