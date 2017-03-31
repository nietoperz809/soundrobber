// WaveDevCaps.cpp : implementation file
//

#include "stdafx.h"
#include "soundrobber.h"
#include "mmsystem.h"
#include "WaveDevCaps.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWaveDevCaps dialog


CWaveDevCaps::CWaveDevCaps(CWnd* pParent /*=NULL*/)
	: CDialog(CWaveDevCaps::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWaveDevCaps)
	m_dcapsview = _T("");
	m_Combo = -1;
	//}}AFX_DATA_INIT
}


void CWaveDevCaps::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWaveDevCaps)
	DDX_Text(pDX, IDC_DCAPS, m_dcapsview);
	DDX_CBIndex(pDX, IDC_COMBO_DEVS, m_Combo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWaveDevCaps, CDialog)
	//{{AFX_MSG_MAP(CWaveDevCaps)
	ON_CBN_SELCHANGE(IDC_COMBO_DEVS, OnSelchangeComboDevs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// Macht einen Wert zum String
CString CWaveDevCaps::Str (int value)
{
	wsprintf (m_str.GetBuffer(256), "%d", value);
	m_str.ReleaseBuffer();
	return m_str;
}

// Fuellt die Edit-Box mit den Driver-Daten
void CWaveDevCaps::FillBox (int device)
{
	WAVEOUTCAPS woc;
	MMRESULT mmerr;
	memset (&woc, 0, sizeof (WAVEOUTCAPS));

	mmerr = waveOutGetDevCaps (device, &woc, sizeof (WAVEOUTCAPS));
	
	if (mmerr != MMSYSERR_NOERROR)
	{	
		m_dcapsview = "Err: " + Str(mmerr) + 
					" --- Cannot access WaveOut Device";
		goto raus;
	}

	m_dcapsview = "********* General Information *********";
	
	m_dcapsview += "\r\r\nManufacturer ID: " + Str (woc.wMid) +
				   "\r\r\nProduct ID: " + Str (woc.wPid) +
				   "\r\r\nDriver version: " + Str (HIBYTE(woc.vDriverVersion)) +
				   "." + Str (LOBYTE(woc.vDriverVersion)) +
				   "\r\r\nProduct name: " + woc.szPname +
				   "\r\r\nChannels: " + Str (woc.wChannels);

	m_dcapsview += "\r\r\n\r\r\n******* Supported Wave Formats *******";

	if (woc.dwFormats & WAVE_FORMAT_1M08)
		m_dcapsview += 	"\r\r\n11.025 kHz, Mono,   8-bit";
	if (woc.dwFormats & WAVE_FORMAT_1S08)
		m_dcapsview += 	"\r\r\n11.025 kHz, Stereo, 8-bit";
	if (woc.dwFormats & WAVE_FORMAT_1M16)
		m_dcapsview += 	"\r\r\n11.025 kHz, Mono,   16-bit";
	if (woc.dwFormats & WAVE_FORMAT_1S16)
		m_dcapsview += 	"\r\r\n11.025 kHz, Stereo, 16-bit";
	if (woc.dwFormats & WAVE_FORMAT_2M08)
		m_dcapsview += 	"\r\r\n22.05  kHz, Mono,   8-bit";
	if (woc.dwFormats & WAVE_FORMAT_2S08)
		m_dcapsview += 	"\r\r\n22.05  kHz, Stereo, 8-bit";
	if (woc.dwFormats & WAVE_FORMAT_2M16)
		m_dcapsview += 	"\r\r\n22.05  kHz, Mono,   16-bit";
	if (woc.dwFormats & WAVE_FORMAT_2S16)
		m_dcapsview += 	"\r\r\n22.05  kHz, Stereo, 16-bit";
	if (woc.dwFormats & WAVE_FORMAT_4M08)
		m_dcapsview += 	"\r\r\n44.1   kHz, Mono,   8-bit";
	if (woc.dwFormats & WAVE_FORMAT_4S08)
		m_dcapsview += 	"\r\r\n44.1   kHz, Stereo, 8-bit";
	if (woc.dwFormats & WAVE_FORMAT_4M16)
		m_dcapsview += 	"\r\r\n44.1   kHz, Mono,   16-bit";
	if (woc.dwFormats & WAVE_FORMAT_4S16)
		m_dcapsview += 	"\r\r\n44.1   kHz, Stereo, 16-bit";
	
	m_dcapsview += "\r\r\n\r\r\n******* Special Functionality *******";

	if (woc.dwSupport & WAVECAPS_LRVOLUME)
		m_dcapsview += "\r\r\nSeparate Left/Right volume control";
	if (woc.dwSupport & WAVECAPS_PITCH)
		m_dcapsview += "\r\r\nPitch control supported";
	if (woc.dwSupport & WAVECAPS_PLAYBACKRATE)
		m_dcapsview += "\r\r\nPlayback rate control supported";
	if (woc.dwSupport & WAVECAPS_SYNC)
		m_dcapsview += "\r\r\nThe driver will block while playing";
	if (woc.dwSupport & WAVECAPS_VOLUME)
		m_dcapsview += "\r\r\nVolume control supported";
	if (woc.dwSupport & WAVECAPS_SAMPLEACCURATE)
		m_dcapsview += "\r\r\nSample accurate position information available";

raus:
	UpdateData (FALSE);	
}


// Combobox angeklickt
void CWaveDevCaps::OnSelchangeComboDevs() 
{
	UpdateData();
	if (!m_Combo)
		FillBox (WAVE_MAPPER);
	else
		FillBox (m_Combo-1);
}

// Beim Start auf Device 1 schalten
BOOL CWaveDevCaps::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_Combo = 1;
	UpdateData (FALSE);
	FillBox (0);
	return TRUE;
}

