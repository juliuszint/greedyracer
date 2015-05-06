#pragma once


#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"

using namespace Vektoria;

class CRouteGenerator
{
public:
	CRouteGenerator();
	~CRouteGenerator();

	void AddStraight();
	void AddLeft();
	void AddRight();

	CPlacement Generate();
};

