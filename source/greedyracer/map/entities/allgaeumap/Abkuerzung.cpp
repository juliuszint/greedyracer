#include "Abkuerzung.h"

void CAbkuerzung::Init(){

}


void CAbkuerzung::ConfigureInit(bool hasStartTrigger, bool hasMiddleTrigger, bool hasEndTrigger)
{
	this->hasStartTrigger = hasStartTrigger;
	this->hasEndTrigger = hasEndTrigger;
	this->hasMiddleTrigger = hasMiddleTrigger;
}

void CAbkuerzung::Init(char * GeoPath){

	m_pzgAbkuerzung = m_zgAbkuerzung.LoadGeo(GeoPath);
	m_zmAbkuerzung.MakeTextureDiffuse("textures\\allgaeumap\\strecke\\Rennstrecke_4098.jpg");
	m_zmAbkuerzung.MakeTextureSpecular("textures\\allgaeumap\\strecke\\Rennstrecke_4098_spec.jpg");
	m_pzgAbkuerzung->SetMaterial(&m_zmAbkuerzung);
	m_zpAbkuerzung.AddGeo(m_pzgAbkuerzung);

	if (this->hasStartTrigger)
	{
		m_zgTriggerStart.Init(1.5f, 0.2f, &m_zmAbkuerzung);
		m_zpTriggerStart.AddGeo(&m_zgTriggerStart);
		m_zpTriggerStart.RotateX(-HALFPI);
		m_zpAbkuerzung.AddPlacement(&m_zpTriggerStart);
	}

	if (hasMiddleTrigger)
	{
		m_zgTriggerMiddle.Init(1.5f, 0.2, &m_zmAbkuerzung);
		m_zpTriggerMiddle.AddGeo(&m_zgTriggerMiddle);
		m_zpTriggerMiddle.RotateX(-HALFPI);
		m_zpAbkuerzung.AddPlacement(&m_zpTriggerMiddle);
	}

	if (hasEndTrigger)
	{
		m_zgTriggerEnd.Init(1.5f, 0.2, &m_zmAbkuerzung);
		m_zpTriggerEnd.AddGeo(&m_zgTriggerEnd);
		m_zpTriggerEnd.RotateX(-HALFPI);
		m_zpAbkuerzung.AddPlacement(&m_zpTriggerEnd);
	}


}

CPlacement* CAbkuerzung::GetRootPlacement(){
	return &m_zpAbkuerzung;
}

CGeo * CAbkuerzung::GetGeo(){
	return m_pzgAbkuerzung;
}

void CAbkuerzung::Translate(CHVector Vektor){
	m_zpAbkuerzung.Translate(Vektor);
}

void CAbkuerzung::TranslateTrigger(CHVector Vektor, Trigger t)
{
	CPlacement* currentTrigger = this->GetTriggerPlacement(t);
	currentTrigger->TranslateDelta(Vektor);
}

void CAbkuerzung::RotateTriggerY(float RotateY, Trigger t)
{
	CPlacement* currentTrigger = this->GetTriggerPlacement(t);
	currentTrigger->RotateYDelta(RotateY);
}

CGeoQuad* CAbkuerzung::GetMidTrigger()
{
	CGeoQuad* result = NULL;
	if (this->hasMiddleTrigger)
	{
		result = &this->m_zgTriggerMiddle;
	}
	return result;
}

CPlacement* CAbkuerzung::GetTriggerPlacement(Trigger t)
{
	CPlacement* currentTrigger = NULL;
	switch (t)
	{
	case TRIGGERSTART:
		currentTrigger = &this->m_zpTriggerStart;
		break;
	case TRIGGERMID:
		currentTrigger = &this->m_zpTriggerMiddle;
		break;
	case TRIGGEREND:
		currentTrigger = &this->m_zpTriggerEnd;
		break;
	}
	return currentTrigger;
}