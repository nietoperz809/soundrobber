

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include <mmsystem.h>

class CWavePlay : public CObject
{
public:
	CWavePlay();
	~CWavePlay();
	UINT GetNumDevs (void);
	MMRESULT Play (WORD, DWORD, WORD, void*, DWORD, BOOL);
	DWORD GetPosition (void);
	void Stop (void);
	void MakeWaveFile (WORD, DWORD, WORD, void*, DWORD, LPSTR); 
	void SetVolume (WORD, WORD);
	DWORD GetVolume (void);
	BOOL IsActive (void);
	void ViewError (MMRESULT, LPSTR);

protected:
	UINT m_numdevs;
	HWAVEOUT m_hwo;
	WAVEHDR m_whdr;
	WAVEFORMATEX m_wvx;
};



