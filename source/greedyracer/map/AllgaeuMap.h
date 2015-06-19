#pragma once


#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "Map.h"
#include "entities\common\Ground.h"
#include "entities\common\Water.h"
#include "entities\allgaeumap\Strecke.h"
#include "entities\allgaeumap\Landscape.h"

using namespace Vektoria;

class CAllgaeuMap : public CMap
{
private:
	CPlacement placement;
	CGround * ground;
	CWater * water;
	CStrecke * strecke;
	CLandscape * landscape;

public:
	~CAllgaeuMap();

	void Init();

	CPlacement* GetRootPlacement();

	//Felix: Die Funktionen reichen die von der Strecke einfach durch, passt das so?

	CHVector GetStartPosition();

	int IsOnCheckpoint(CHVector);

	CHVector IsOnTrack(CHVector);

	int IsOnShortcutTrigger(CHVector);

	bool IsOnFinish(CHVector);
};

