#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;

class CTrack
{
public:
	CTrack();
	~CTrack();

	CGeo* m_pzgAsphalt;
	CGeo* m_pzgAsphaltMarks;
	CGeo* m_pzgRennstrecke;

	CFileWavefront m_zgAsphalt;
	CFileWavefront m_zgAsphaltMarks;
	CFileWavefront m_zgRennstrecke;

	CPlacement m_zpAsphalt;
	CPlacement m_zpAsphaltMarks;
	CPlacement m_zpTrack;
	CPlacement m_zpRennstrecke;

	CMaterial m_zmAsphalt;
	CMaterial m_zmAsphaltMarks;
	CMaterial m_zmRennstrecke;

	void InitTrack();

	CPlacement* GetPlacement();
};

