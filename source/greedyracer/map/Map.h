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

struct MapPosition
{
	CHVector position;
	float directionAngle;
};

struct MapPositions
{
	int StartPositionCount;
	MapPosition Positions[5];
};

class CMap : public CEntity
{
public:
	int ShortcutCount;

	// Note (julius): gibt die Startposition f�r den Spieler auf dieser Strecke zur�ck
	virtual MapPositions GetStartPosition() = 0;

	virtual int IsOnCheckpoint(CHVector) = 0;

	virtual CHVector IsOnTrack(CHVector) = 0;

	virtual bool IsOnFinish(CHVector) = 0;

	virtual int IsOnShortcutTrigger(CHVector) = 0;

	virtual CShortcutData* GetShortcut(int) = 0;
};

