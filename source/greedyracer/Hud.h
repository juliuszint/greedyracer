#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include <string>

using namespace std;
using namespace Vektoria;

class CHud
{
private:
	COverlay m_zoHudRootOverlay;

	CWritingFont m_zwFont;

	CWriting m_zwPlayer1;
	CWriting m_zwPlayer2;
	CWriting m_zwRoundPlayer1;
	CWriting m_zwRoundPlayer2;
	CWriting m_zwTime;

	string m_zsNamePlayer1;
	string m_zsNamePlayer2;
	string m_zsRoundPlayer1;
	string m_zsRoundPlayer2;
	string m_zsTime;

public:
	COverlay* GetRootOverlay();
	void InitHud();
	void SetPlayerName1(string name1);
	void SetPlayerName2(string name2);
	void SetRoundPlayer1(string roundp1);
	void SetRoundPlayer2(string roundp2);
	void SetTime(string time);
	string GetPlayerName1();
	string GetPlayerName2();
	string GetRoundPlayer1();
	string GetRoundPlayer2();
	string GetTime();
	//void Tick();
};
