#pragma once


#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "Map.h"
#include "entities\common\Ground.h"
#include "entities\common\Water.h"
#include "entities\test\SphereEntity.h"
#include "entities\allgaeumap\Strecke.h"
#include "entities\allgaeumap\Landscape.h"
#include "entities\allgaeumap\shortcuts\Barrel.h"
#include "entities\allgaeumap\shortcuts\FallenTree.h"
#include "entities\allgaeumap\shortcuts\Rocks.h"

using namespace Vektoria;

class CAllgaeuMap : public CMap
{
private:
	CPlacement placement;
	CGround * ground;
	CWater * water;
	CStrecke * strecke;
	CLandscape * landscape;
	CShortcutData shortCuts[3];

public:

	~CAllgaeuMap();

	void Init();

	CPlacement* GetRootPlacement();

	CHVector GetStartPosition();

	int IsOnCheckpoint(CHVector);

	CHVector IsOnTrack(CHVector);

	int IsOnShortcutTrigger(CHVector);

	CShortcutData* GetShortcut(int);

	bool IsOnFinish(CHVector);
};

