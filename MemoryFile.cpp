#include "stdafx.h"
#include "MemoryFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Konstruktor: Markiert den SpeicherBlock als unbelegt
CMemoryFile::CMemoryFile()
{
	hglobal = NULL;
}

// Destruktor: Gibt eventuell belegten Speicher wieder frei
CMemoryFile::~CMemoryFile()
{
	if (hglobal)
	{
		GlobalUnlock (hglobal);
		GlobalFree (hglobal);
	}
}

// Liest Teile einer Datei in den Speicher
void *CMemoryFile::Read (UINT start, UINT end)
{
	// Cursor auf EierUhr
	SetCursor (LoadCursor (NULL, IDC_WAIT));

	// Laenge ermitteln
	size = end-start;

	// Wenn SpeicherBlock schon benutzt wurde, ->freimachen
	if (hglobal)
	{
		GlobalUnlock (hglobal);
		GlobalFree (hglobal);
	}

	// SpeicherBlock anlegen, 256 mehr weils sicherer ist
	hglobal = GlobalAlloc (GHND, size+256);
	memptr = GlobalLock (hglobal);
	if (!memptr)
		::MessageBox (NULL, "GlobalAlloc failed....", 
		"CMemoryFile::Read", MB_ICONSTOP | MB_OK);
	
	// Daten in' Speicher einlesen
	CFile::Seek (start, CFile::begin);
	CFile::Read	(memptr, size);

	// Cursor wieder auf Pfeil
	SetCursor (LoadCursor (NULL, IDC_ARROW));
	
	// Pointer auf SpeicherBlock zurueckgeben
	return memptr;
}

// Dreht den Speicher um
void CMemoryFile::Reverse (void)
{
	// Nix zum Umdrehen, dann 'raus
	if (!hglobal)
		return;
	
	// Cursor auf EierUhr
	SetCursor (LoadCursor (NULL, IDC_WAIT));
	
	// Pointer und Schleifenzaehler anlegen
	BYTE *tmp = new	BYTE[size];
	BYTE *mem = (BYTE*)memptr;
	UINT s;

	// Speicherinhalt umdrehen...
	for (s=size; s>0; s--)
		tmp[size-s] = mem[s];

	// und zurueckschreiben
	for (s=0; s<size; s++)
		mem[s] = tmp[s];

	// Temporaeres Array freigeben
	delete[] tmp;

	// Cursor wieder auf Pfeil
	SetCursor (LoadCursor (NULL, IDC_ARROW));
}

// Addiert ein BYTE zu jedem Byte im Speicher
void CMemoryFile::AddByte (BYTE byte)
{
	// Nix zum Umdrehen, dann 'raus
	if (!hglobal)
		return;

	// Cursor auf EierUhr
	SetCursor (LoadCursor (NULL, IDC_WAIT));

	// BYTE aufaddieren
	BYTE *mem = (BYTE*)memptr;
	UINT s;
	for (s=0; s<size; s++)
		mem[s] += byte;

   	// Cursor wieder auf Pfeil
	SetCursor (LoadCursor (NULL, IDC_ARROW));
}

// XOR'd alle Bytes im Speicher
void CMemoryFile::XorByte (BYTE byte)
{
	// Nix zum Umdrehen, dann 'raus
	if (!hglobal)
		return;

	// Cursor auf EierUhr
	SetCursor (LoadCursor (NULL, IDC_WAIT));

	// BYTE xorren
	BYTE *mem = (BYTE*)memptr;
	UINT s;
	for (s=0; s<size; s++)
		mem[s] ^= byte;

   	// Cursor wieder auf Pfeil
	SetCursor (LoadCursor (NULL, IDC_ARROW));
}
