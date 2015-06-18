#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CAbkuerzung : public CEntity
{
private:
	CGeo* m_pzgAbkuerzung;

	CFileWavefront m_zgAbkuerzung;
	CPlacement m_zpAbkuerzung;
	CMaterial m_zmAbkuerzung;
	//Quad für Abkürzungseingang
	CGeoQuad m_zgTrigger;
	CGeoQuad m_zgTriggerEnd;
	CPlacement m_zpTrigger;
	CPlacement m_zpTriggerEnd;

public:
	void Init();
	void Init(char* GeoPath);
	CPlacement* GetRootPlacement();
	CGeo * GetGeo();
	void Translate(CHVector Vektor);
	void TranslateTrigger(CHVector Vektor);
	void RotateTriggerX(float Rotate);
	void RotateTriggerY(float RotateY);
	void InitTriggerEnd();
	void TranslateTriggerEnd(CHVector Vektor);
	void RotateTriggerEndX(float Rotate);
	void RotateTriggerEndY(float RotateY);

};