#pragma once


#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "entities\Entity.h"

using namespace Vektoria;

struct CShortcutData
{
public:
	int ChancePrecentage;
	float MaxActiveTime;
	float ActiveTime;
	CEntity* CollisionEntity;
	CPlacement* CollisionPlacement;
};


class CMap : public CEntity
{
public:
	int ShortcutCount;

	// Note (julius): gibt die Startposition für den Spieler auf dieser Strecke zurück
	virtual CHVector GetStartPosition() = 0;

	virtual int IsOnCheckpoint(CHVector) = 0;

	virtual CHVector IsOnTrack(CHVector) = 0;

	virtual bool IsOnFinish(CHVector) = 0;

	virtual int IsOnShortcutTrigger(CHVector) = 0;

	virtual CShortcutData* GetShortcut(int) = 0;
};

