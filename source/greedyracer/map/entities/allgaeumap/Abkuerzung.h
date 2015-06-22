#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

enum Trigger
{
	TRIGGERSTART,
	TRIGGERMID,
	TRIGGEREND,
};

class CAbkuerzung : public CEntity
{
private:
	CGeo* m_pzgAbkuerzung;

	CFileWavefront m_zgAbkuerzung;
	CPlacement m_zpAbkuerzung;
	CMaterial m_zmAbkuerzung;

	//Quad für Abkürzungseingang
	CGeoQuad m_zgTriggerStart;
	CGeoQuad m_zgTriggerMiddle;
	CGeoQuad m_zgTriggerEnd;

	CPlacement m_zpTriggerStart;
	CPlacement m_zpTriggerMiddle;
	CPlacement m_zpTriggerEnd;

	bool hasEndTrigger;
	bool hasMiddleTrigger;
	bool hasStartTrigger;

	CPlacement* GetTriggerPlacement(Trigger);

	float RespawnAngle;
public:
	void ConfigureInit(bool, bool, bool);
	void Init();

	void Init(char* GeoPath);
	CPlacement* GetRootPlacement();
	CGeo * GetGeo();
	void Translate(CHVector Vektor);

	void TranslateTrigger(CHVector Vektor, Trigger t);
	void RotateTriggerY(float RotateY, Trigger t);

	CGeoQuad* GetMidTrigger();
	void setRespawnAngle(float fAngle);
	float getRespawnAngle();
};