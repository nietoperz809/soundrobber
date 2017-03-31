#include "stdafx.h"
#include "WavePlay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Konstruktor: Ermittelt Anzahl der WaveOut-Devices
CWavePlay::CWavePlay()
{
	m_hwo = NULL;
	
	m_numdevs = ::waveOutGetNumDevs();
}

// Destruktor: Schliesst das WaveOut-Device
CWavePlay::~CWavePlay()
{
	Stop();
}

// Anzahl d. WaveOut-Devices abfragen
UINT CWavePlay::GetNumDevs()
{
	return m_numdevs;
}

// Spielt einen DatenBlock als WAVE ab...
MMRESULT CWavePlay::Play (WORD channels, DWORD s_rate, WORD bps,
						  void *data, DWORD length, BOOL mapflag)
{
	MMRESULT mmerror;
	UINT devid = WAVE_MAPPER;

	// Wave-Mapper benutzen oder nicht?
	if (!mapflag)
		devid = 0;

	// Falls vorher schon offen, erstmal schliessen
	Stop();
	
	// WaveFormat-Struct einstellen
	m_wvx.wFormatTag = WAVE_FORMAT_PCM;
	m_wvx.nChannels = channels;
	m_wvx.nSamplesPerSec = s_rate;
	m_wvx.nAvgBytesPerSec = s_rate * channels * bps/8;
	m_wvx.nBlockAlign = channels * bps/8 ;
	m_wvx.wBitsPerSample = bps;
	m_wvx.cbSize = 0;
	
	// WaveHeader einstellen
	m_whdr.lpData = (LPSTR)data;
	m_whdr.dwBufferLength = length;
	m_whdr.dwFlags = 0;

	// Wave-Device oeffnen
	mmerror = ::waveOutOpen (&m_hwo, devid, &m_wvx, 0, 0,
				CALLBACK_NULL | WAVE_ALLOWSYNC);
	
	// Falls Error -> Ausgeben und tschuess...
	if (mmerror != MMSYSERR_NOERROR)
	{	
		ViewError (mmerror, "WaveOutOpen:");
		return mmerror;
	}

	// WaveHeader anmelden
	mmerror = waveOutPrepareHeader (m_hwo, &m_whdr, sizeof (WAVEHDR));

	// Falls Error -> Ausgeben und tschuess...
	if (mmerror != MMSYSERR_NOERROR)
	{	
		ViewError (mmerror, "WaveOutPrepareHeader:");
		return mmerror;
	}

	// Wave abspielen
	mmerror = waveOutWrite (m_hwo, &m_whdr, sizeof (WAVEHDR));

	// Falls Error -> Ausgeben und tschuess...
	if (mmerror != MMSYSERR_NOERROR)
	{	
		ViewError (mmerror, "WaveOutWrite:");
		return mmerror;
	}

	return mmerror;
}

// Gibt eine Error-Msg aus
void CWavePlay::ViewError (MMRESULT mmerror, LPSTR caption)
{
	char errstring[256];
	::waveOutGetErrorText (mmerror, errstring, 256); 
	::MessageBox (NULL, errstring, caption, MB_OK | MB_ICONSTOP);
}

// Testet, ob WavePlayer spielt
BOOL CWavePlay::IsActive (void)
{	if (m_hwo)
		return TRUE;
	else
		return FALSE;
}

// Stellt die Lautstaerke ein
void CWavePlay::SetVolume (WORD left, WORD right)
{
	if (m_hwo)
		::waveOutSetVolume (m_hwo, MAKELONG	(left, right));
}

// Gibt die Lautstaerke zurueck
DWORD CWavePlay::GetVolume (void)
{	
	DWORD volume = 0;
	if (m_hwo)
		::waveOutGetVolume (m_hwo, &volume);
	return volume;
}

// Stoppt das Abspielen eines Waves
void CWavePlay::Stop (void)
{
	if (m_hwo)
	{
		::waveOutReset (m_hwo);
		::waveOutUnprepareHeader (m_hwo, &m_whdr, sizeof (WAVEHDR));
		::waveOutClose (m_hwo);
	}
	m_hwo = 0;
}

// Position des laufenden Waves	holen
DWORD CWavePlay::GetPosition()
{
	if (!m_hwo)
		return 0L;
	static MMTIME mmtime;	//Static, sonst eventuell Absturz!!
	mmtime.wType = TIME_BYTES;
	waveOutGetPosition (m_hwo, &mmtime, sizeof (MMTIME));
	return (mmtime.u.cb);
}


// Schreibt ein Wave-File auf die Platte
// channels: 1 == mono, 2 == stereo
// frequency: sampling rate: e.g. 22050
// bps: bits-per-sample: e.g. 16
// length: number of data bytes
void CWavePlay::MakeWaveFile (WORD channels, DWORD frequency, WORD bps, 
				   void* data, DWORD length, LPSTR fname) 
{
	BYTE wavehead[] = {'R','I','F','F',		  // 0	
						0, 0, 0, 0,			  // 4 - DWORD: Filelaenge - 8
						'W','A','V','E',      // 8
						'f','m','t',' ',      // 12
						16, 0, 0, 0,		  // 16 - Konstant
						1, 0,				  // 20 - Konstant
						0, 0,				  // 22 - WORD: Kanaele
						0, 0, 0, 0,			  // 24 - DWORD: Sample Frequenz
						0, 0, 0, 0,			  // 28 - DWORD: Average
						0, 0,				  // 32 - WORD: Bytes pro Sample
						0, 0, 				  // 34 - WORD: format-specific
						'd','a','t','a',      // 36 
						0, 0, 0, 0};		  // 40 - DWORD: Laenge Samplingdaten
											  // ---------------------------------
	                                          // Total: 44 bytes

	// WaveHead auffuellen
	*(DWORD *)(&wavehead[4]) = length + sizeof(wavehead) - 8;
	*(WORD *)(&wavehead[22]) = channels;
	*(DWORD *)(&wavehead[24]) = frequency;
	*(DWORD *)(&wavehead[28]) = channels * bps/8 * frequency;
	*(WORD *)(&wavehead[32]) = bps/8;
	*(WORD *)(&wavehead[34]) = bps;
	*(DWORD *)(&wavehead[40]) = length;

	// File anlegen	und Header schreiben
	CFile cf (fname, CFile::modeCreate | CFile::modeReadWrite);
	cf.Write (wavehead, sizeof (wavehead)); 

	// ... und Daten hinterher
	cf.Write (data, length);
}
