#pragma once

#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CSphereEntity : public CEntity
{
private:
	float radius;
	CGeoSphere sphere;
	CPlacement placement;
	CMaterial material;
public:
	CSphereEntity();
	void ConfigureInit(float);
	void Init();
	CPlacement* GetRootPlacement();
};

