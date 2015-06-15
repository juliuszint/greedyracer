#include "Hud.h"

COverlay* CHud::GetRootOverlay()
{
	return &this->m_zoHudRootOverlay;
}

void CHud::InitHud()								//complete Hud Initialisation
{
	m_zwFont.Init("fonts\\FontArialShadow.png", false);							
	m_zwFont.SetTableSize(16, 6);												
	m_zwPlayer1.Init(CFloatRect(0.01f, 0.01f, 0.1f, 0.1f), 10, &m_zwFont);		
	m_zwPlayer2.Init(CFloatRect(0.02f, 0.02f, 0.1f, 0.1f), 10, &m_zwFont);		
	m_zwRoundPlayer1.Init(CFloatRect(0.11f, 0.11f, 0.1f, 0.1f), 2, &m_zwFont);	
	m_zwRoundPlayer2.Init(CFloatRect(0.21f, 0.21f, 0.1f, 0.1f), 2, &m_zwFont);	
	m_zwTime.Init(CFloatRect(0.95f, 0.95f, 0.1f, 0.1f), 6, &m_zwFont);			
	this->m_zoHudRootOverlay.AddOverlay(&this->m_zwPlayer1);
	this->m_zoHudRootOverlay.AddOverlay(&this->m_zwPlayer2);
	this->m_zoHudRootOverlay.AddOverlay(&this->m_zwRoundPlayer1);
	this->m_zoHudRootOverlay.AddOverlay(&this->m_zwRoundPlayer2);
	this->m_zoHudRootOverlay.AddOverlay(&this->m_zwTime);
}

//-------------------------------------------------------------------------------------
//Set Methoden
//-------------------------------------------------------------------------------------
void CHud::SetPlayerName1(string name1)
{
	this->m_zsNamePlayer1 = name1;					//setting the new Player 1 name
	this->m_zwPlayer1.PrintF(name1.data());			//printing the Player 1 name on Overlay
};

void CHud::SetPlayerName2(string name2)
{
	this->m_zsNamePlayer2 = name2;					//setting the new Player 2 name
	this->m_zwPlayer2.PrintF(name2.data());			//printing the Player 2 name on Overlay
};

void CHud::SetRoundPlayer1(string roundp1)
{
	this->m_zsRoundPlayer1 = roundp1;				//setting the current Player 1 lap count
	this->m_zwRoundPlayer1.PrintF(roundp1.data());	//printing the Player 1 round count on Overlay
};

void CHud::SetRoundPlayer2(string roundp2)
{
	this->m_zsRoundPlayer2 = roundp2;				//setting the current Player 2 lap count
	this->m_zwRoundPlayer2.PrintF(roundp2.data());	//printing the Player 1 round count on Overlay
};

void CHud::SetTime(string time)
{
	this->m_zsTime = time;							//setting the current time
	this->m_zwTime.PrintF(time.data());				//printing the current time on Overlay
};

//-------------------------------------------------------------------------------------
//Get Methoden
//-------------------------------------------------------------------------------------
string CHud::GetPlayerName1() //returns Player Name 1
{
	return m_zsNamePlayer1;
};

string CHud::GetPlayerName2() //returns Player Name 2
{
	return m_zsNamePlayer2;
};

string CHud::GetRoundPlayer1() //returns laps of Player 1
{
	return m_zsRoundPlayer1;
}

string CHud::GetRoundPlayer2() //returns laps of Player 2
{
	return m_zsRoundPlayer2;
}

string CHud::GetTime() //returns current time count
{
	return m_zsTime;
}

void CHud::SetVisible(bool visible)
{
	if (visible) this->m_zoHudRootOverlay.SwitchOn();
	else this->m_zoHudRootOverlay.SwitchOff();
}

//void CHud::Tick()
//{
//}