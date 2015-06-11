#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"
#include "Start.h"
#include "Checkpoint.h"
#include "Abkuerzung.h"
#include "Sektor.h"

using namespace Vektoria;

class CStrecke
{
private:
	CPlacement root;

	CStart * Start;
	CCheckpoint * CP1;
	CCheckpoint * CP2;
	CCheckpoint * CP3;
	CCheckpoint * CP4;
	CCheckpoint * CP5;
	CAbkuerzung * Cut1_1;
	CAbkuerzung * Cut1_2;
	CAbkuerzung * Cut2_1;
	CAbkuerzung * Cut2_2;
	CAbkuerzung * Cut3;
	CSektor * Sektor1;
	CSektor * Sektor2;
	CSektor * Sektor3;

public:
	~CStrecke();

	void Init();

	CPlacement* GetRootPlacement();


	//Felix Die Funktionen muss man noch implementieren, ich weiﬂ nicht, was genau damit passieren soll :)

	CHVector GetStartPosition();

	int IsOnCheckpoint(CHVector position);

	CHVector IsOnTrack(CHVector position);

	bool IsOnFinish(CHVector position);

	CGeo * getStartGeo();
	CGeo * getCheckpointGeo(int pos);
	CGeo * getSektorGeo(int pos);
	CGeo * getAbkuerzungGeo(int pos);
};

