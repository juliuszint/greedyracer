#pragma once


#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "Map.h"
#include "entities\common\Ground.h"
#include "entities\common\Water.h"
#include "entities\allgaeumap\Strecke.h"
#include "entities\allgaeumap\Landscape.h"
#include "entities\allgaeumap\Trigger.h"

using namespace Vektoria;

class CAllgaeuMap : public CMap
{
private:
	CPlacement placement;
	CGround * ground;
	CWater * water;
	CStrecke * strecke;
	CLandscape * landscape;
	ShortcutData shortCuts[3];
	CTrigger * TriggerTree;
	CTrigger * TriggerRocks;
	CTrigger * TriggerBeerbarrel;


public:

	~CAllgaeuMap();

	void Init();

	CPlacement* GetRootPlacement();

	CHVector GetStartPosition();

	int IsOnCheckpoint(CHVector);

	CHVector IsOnTrack(CHVector);

	int IsOnShortcutTrigger(CHVector);

	ShortcutData* GetShortcut(int);

	bool IsOnFinish(CHVector);
};

