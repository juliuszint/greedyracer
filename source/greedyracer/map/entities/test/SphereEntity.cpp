#include "SphereEntity.h"

CSphereEntity::CSphereEntity()
{
	this->radius = -1;
}

void CSphereEntity::ConfigureInit(float radius)
{
	this->radius = radius;
}

void CSphereEntity::Init()
{
	if (this->radius < 0) this->radius = 0.2f;

	this->material.Init(CColor(0, 1, 0), CColor(0, 1, 0), CColor(0, 0, 0));
	this->sphere.Init(.5, &this->material);
	this->placement.AddGeo(&this->sphere);
}

CPlacement* CSphereEntity::GetRootPlacement()
{
	return &this->placement;
}