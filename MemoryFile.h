

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////
// Abgeleitet von CFile
// liest Teile einer Datei in'n Speicher

class CMemoryFile : public CFile
{
public:
	CMemoryFile();
	~CMemoryFile();
	void *Read (UINT start, UINT end);
	void Reverse (void);
	void AddByte (BYTE);
	void XorByte (BYTE);
	
	void *GetPointer (void)
	{
		if (hglobal)
			return memptr;
		else
			return NULL;
	}

	BYTE GetByte (DWORD pos)
	{
		if (hglobal)
			return 0;
		else
			return ((BYTE *)memptr)[pos];
	}

protected:
	HGLOBAL hglobal;
	void *memptr;
	UINT size;
};


