#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;

class CTrack
{
public:
	CTrack();
	~CTrack();

	CGeo* m_pzgRennstrecke;

	CFileWavefront m_zgRennstrecke;

	CPlacement m_zpTrack;
	CPlacement m_zpRennstrecke;

	CMaterial m_zmRennstrecke;

	void InitTrack();

	CPlacement* GetPlacement();
};

