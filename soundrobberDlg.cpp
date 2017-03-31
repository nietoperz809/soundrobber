// soundrobberDlg.cpp : implementation file
//

#include "stdafx.h"
#include "scope.h"
#include "memoryfile.h"
#include "waveplay.h"
#include "wavedevcaps.h"
#include "soundrobber.h"
#include "soundrobberDlg.h"
#include "about.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


///////////////// Utility-Procs /////////////////////////////////////////

// Stop-Button simulieren
void CSoundrobberDlg::RemoteStop()
{
	CWnd* child = GetDlgItem (IDC_BUTTON_STOP);
	child->SendMessage (BM_SETSTATE, TRUE, 0L);
	::Sleep (100);
	child->SendMessage (BM_SETSTATE, FALSE, 0L);		
	OnButtonStop();
}

// Start-Button simulieren
void CSoundrobberDlg::RemoteStart()
{
	CWnd* child = GetDlgItem (IDC_BUTTON_PLAY);
	child->SendMessage (BM_SETSTATE, TRUE, 0L);
	::Sleep (100);
	child->SendMessage (BM_SETSTATE, FALSE, 0L);		
	OnButtonPlay();
}

// Stop/Start simulieren
void CSoundrobberDlg::Restart()
{
	if (!m_waveplay.GetPosition())
		return;
	RemoteStop();
	RemoteStart();
}

// Alles zurücksetzen
void CSoundrobberDlg::ResetView()
{
	m_mono = TRUE;
	m_stereo = FALSE;
	m_reverse = FALSE;
	m_xor = FALSE;
	m_add = FALSE;
	m_mapper = TRUE;
	m_16bits = FALSE;
	m_8bits = TRUE;
	m_fileend = 0;
	m_filestart = 0;
	m_position = 0;
	m_speed = 11025;
	m_position = 0;

	// Windows disablen
	CWnd *child	= GetWindow (GW_CHILD);
	while (child)
	{	
		if (child != GetDlgItem (IDC_BUTTON_OPEN) 
			&& child != GetDlgItem (IDC_SCROLL_VOLUME)
			&& child != GetDlgItem (IDC_PICTURE))
				child->EnableWindow (FALSE);
		child = child->GetWindow (GW_HWNDNEXT);
	} 

	// Default-Caption malen
	CString cs;
	cs.LoadString (IDS_TITLE);
	SetWindowText ((LPCSTR)cs);
	
	UpdateData (FALSE);
}


/////////////////////////////////////////////////////////////////////////////
// CSoundrobberDlg dialog

CSoundrobberDlg::CSoundrobberDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSoundrobberDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSoundrobberDlg)
	m_mono = FALSE;
	m_stereo = FALSE;
	m_reverse = FALSE;
	m_fileend = 0;
	m_filestart = 0;
	m_speed = 0;
	m_16bits = FALSE;
	m_8bits = FALSE;
	m_position = 0;
	m_add = FALSE;
	m_xor = FALSE;
	m_addvalue = 0;
	m_xorvalue = 0;
	m_mapper = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSoundrobberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSoundrobberDlg)
	DDX_Control(pDX, IDC_SLIDER_START, m_slider_start);
	DDX_Control(pDX, IDC_SLIDER_END, m_slider_end);
	DDX_Control(pDX, IDC_PICTURE, m_scope);
	DDX_Control(pDX, IDC_SPIN_SPEED, m_spinspeed);
	DDX_Check(pDX, IDC_CHECK_MONO, m_mono);
	DDX_Check(pDX, IDC_CHECK_STEREO, m_stereo);
	DDX_Check(pDX, IDC_CHECK_REVERSE, m_reverse);
	DDX_Text(pDX, IDC_EDIT_END, m_fileend);
	DDX_Text(pDX, IDC_EDIT_START, m_filestart);
	DDX_Text(pDX, IDC_EDIT_SPEED, m_speed);
	DDX_Check(pDX, IDC_CHECK_16BITS, m_16bits);
	DDX_Check(pDX, IDC_CHECK_8BITS, m_8bits);
	DDX_Text(pDX, IDC_POSITION, m_position);
	DDX_Check(pDX, IDC_CHECK_ADD, m_add);
	DDX_Check(pDX, IDC_CHECK_XOR, m_xor);
	DDX_Text(pDX, IDC_EDIT_ADD, m_addvalue);
	DDX_Text(pDX, IDC_EDIT_XOR, m_xorvalue);
	DDX_Check(pDX, IDC_CHECK_MAPPER, m_mapper);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSoundrobberDlg, CDialog)
	//{{AFX_MSG_MAP(CSoundrobberDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	ON_BN_CLICKED(IDC_CHECK_MONO, OnCheckMono)
	ON_BN_CLICKED(IDC_CHECK_STEREO, OnCheckStereo)
	ON_BN_CLICKED(IDC_CHECK_REVERSE, OnCheckReverse)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SPEED, OnDeltaposSpinSpeed)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_EN_KILLFOCUS(IDC_EDIT_SPEED, OnKillfocusEditSpeed)
	ON_BN_CLICKED(IDC_CHECK_16BITS, OnCheck16bits)
	ON_BN_CLICKED(IDC_CHECK_8BITS, OnCheck8bits)
	ON_BN_CLICKED(IDC_BUTTON_WAVE, OnButtonWave)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_GET_END, OnGetEnd)
	ON_BN_CLICKED(IDC_GET_START, OnGetStart)
	ON_EN_KILLFOCUS(IDC_EDIT_START, OnKillfocusEditStart)
	ON_EN_KILLFOCUS(IDC_EDIT_END, OnKillfocusEditEnd)
	ON_EN_SETFOCUS(IDC_POSITION, OnSetfocusPosition)
	ON_WM_VSCROLL()
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDC_CHECK_XOR, OnCheckXor)
	ON_BN_CLICKED(IDC_CHECK_ADD, OnCheckAdd)
	ON_BN_CLICKED(IDC_CHECK_MAPPER, OnCheckMapper)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSoundrobberDlg message handlers

// Dialog-schliessen beim druecken von RETURN abfangen
BOOL CSoundrobberDlg::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	if (wParam == 1)
		return TRUE;
	
	return CDialog::OnCommand(wParam, lParam);
}

// Init-Dialog
BOOL CSoundrobberDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Drag/Drop einschalten
	DragAcceptFiles();
	
	// Add "About..." menu item to system menu.

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	CString strAboutMenu;
	CString strDevCaps;
	int s;
	strAboutMenu.LoadString(IDS_ABOUTBOX);
	strDevCaps.LoadString (IDS_DEVCAPS);
	for (s=0; s<3; s++)
		pSysMenu->RemoveMenu (s, MF_BYPOSITION);
	pSysMenu->AppendMenu (MF_SEPARATOR);
	pSysMenu->AppendMenu (MF_STRING, IDM_DEVCAPS, strDevCaps);
	pSysMenu->AppendMenu (MF_STRING, IDM_ABOUTBOX, strAboutMenu);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// ScrollBar einstellen
	mp_scroll_volume = (CScrollBar *)GetDlgItem (IDC_SCROLL_VOLUME);
	mp_scroll_volume->SetScrollRange (0, 255); 
	mp_scroll_volume->SetScrollPos (0);

	// Controls vorbelegen
	ResetView();
	
	return TRUE; 
}

// WavePlay-Devices abfragen
// WM_SIZE wird nur einmal gesendet weil dies eine DialogBox ist !!!
void CSoundrobberDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// Keine Soundkarte da, dann tschuess...
	if (!m_waveplay.GetNumDevs())
	{
		MessageBox ("Sorry, No WaveOut Device\n WaveRobber cannot run...",
					"MMSYSTEM Error...");
		SendMessage (WM_CLOSE);
	}
}

// Menu-Commands
void CSoundrobberDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if ((nID & 0xFFF0) == IDM_DEVCAPS)
	{
		CWaveDevCaps cwd;
		cwd.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSoundrobberDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSoundrobberDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/////////////////////////////// Control-Messages //////////////////////////

// Pos-Control hat den Input-Focus? -> das geht garnicht...
void CSoundrobberDlg::OnSetfocusPosition() 
{
	::SetFocus (NULL);	
}

// Drag/Drop - Support
void CSoundrobberDlg::OnDropFiles(HDROP hDropInfo) 
{
	char fname[256];

	DragQueryFile (hDropInfo, 0, fname, 256); 
	m_pathname = fname;
	m_filename = m_pathname.Right (m_pathname.GetLength() - 
								   m_pathname.ReverseFind (0x5c) 
								   -1);

	FileOpenProc();
	
	CDialog::OnDropFiles(hDropInfo);
}


// File-Open Button
void CSoundrobberDlg::OnButtonOpen() 
{
	// File-Open-Dialog aktivieren und Filenamen holen
	CFileDialog cf(TRUE);
	cf.m_ofn.lpstrTitle = "Open file for wave stealin'";
	cf.m_ofn.lpstrFilter = "All files (*.*)\0 *.*\0";
	cf.m_ofn.Flags &= ~OFN_EXPLORER;
	if (cf.DoModal() == IDCANCEL)
		return;

	// FileNamen holen
	m_pathname = cf.GetPathName();
	m_filename = cf.GetFileName();

	// Restliche Open-Prozedur ausfuehren
	FileOpenProc();
}

// Aktionen beim oeffnen eines Files....
// Wird von OnButtonOpen und OnDropFiles aufgerufen !!!
void CSoundrobberDlg::FileOpenProc()
{	
	// Alles von vorher zuruecksetzen
	ResetView();
	RemoteStop();
	m_memfile.Close();

	// File öffnen und Edit-Controls einstellen
	if (!m_memfile.Open (m_pathname, CFile::modeRead | CFile::typeBinary))
	{
		MessageBox (m_pathname, "Failed to open...", MB_ICONSTOP);
		return;
	}
	m_fileend = m_memfile.GetLength();

	// Slider-Controls einstellen
	m_slider_start.SetRange (0, m_fileend, TRUE);
	m_slider_start.SetPos (0);
	m_slider_start.SetPageSize (100+m_fileend/1000);
	m_slider_end.SetRange (0, m_fileend, TRUE);
	m_slider_end.SetPos (m_fileend);
	m_slider_end.SetPageSize (100+m_fileend/1000);

	// Filenamen in Titelzeile malen
	CString caption = "PB's SR (" + m_filename + ")";
	SetWindowText ((LPCSTR)caption);

	// Alle Controls Enablen, bis auf einige gewisse....
	CWnd *child	= GetWindow (GW_CHILD);
	while (child)
	{
		if (child != GetDlgItem (IDC_EDIT_XOR) && child != GetDlgItem (IDC_EDIT_ADD))
			child->EnableWindow ();
		child = child->GetWindow (GW_HWNDNEXT);
	} 

	UpdateData (FALSE);
}

// Wave-File basteln
void CSoundrobberDlg::OnButtonWave() 
{
	CFileDialog cf (FALSE);
	cf.m_ofn.lpstrFilter = "Audio samplings (*.WAV)\0\0";
	cf.m_ofn.lpstrTitle = "Save file as a 'WAVE'";
	cf.m_ofn.Flags &= ~OFN_EXPLORER;
	cf.m_ofn.lpstrDefExt = "WAV";
	// Bei Abbruch -> Abbruch
	if (cf.DoModal() == IDCANCEL)
		return;
	// Wave erzeugen
	WORD channels = 1;
	WORD bits = 8;
	CString savename;
	// Wenn noch nix eingelesen wurde, dann jetzt aber
	void *data = m_memfile.GetPointer();
	if (!data)
		data = m_memfile.Read (m_filestart, m_fileend);
	if (m_stereo)
		channels = 2;
	if (m_16bits)
		bits = 16;
	savename = cf.GetPathName();
	// ... und mach jetzt
	m_waveplay.MakeWaveFile (channels, m_speed, bits, 
							data, m_fileend - m_filestart,
							savename.GetBuffer(256));
}


///////////////////////// Handler fuer CheckBoxes //////////////////////

void CSoundrobberDlg::OnCheckMono() 
{
	m_stereo = FALSE;
	m_mono = TRUE;
	UpdateData (FALSE);
	Restart();	
}

void CSoundrobberDlg::OnCheckStereo() 
{
	m_mono = FALSE;
	m_stereo = TRUE;
	UpdateData (FALSE);
	Restart();
}

void CSoundrobberDlg::OnCheckReverse() 
{
	if (m_reverse)
		m_reverse = FALSE;
	else
		m_reverse = TRUE;
	UpdateData (FALSE);
	Restart();
}

void CSoundrobberDlg::OnCheck16bits() 
{
	m_16bits = TRUE;
	m_8bits = FALSE;
	UpdateData (FALSE);
	Restart();
}

void CSoundrobberDlg::OnCheck8bits() 
{
	m_8bits = TRUE;
	m_16bits = FALSE;
	UpdateData (FALSE);
	Restart();
}

void CSoundrobberDlg::OnCheckXor() 
{
	CWnd *child = GetDlgItem (IDC_EDIT_XOR);
	if (m_xor)
	{
		m_xor = FALSE;
		child->EnableWindow	(FALSE);
	}
	else
	{
		m_xor = TRUE;
		child->EnableWindow();
	}
	UpdateData (FALSE);
	Restart();
	
}

void CSoundrobberDlg::OnCheckAdd() 
{
	CWnd *child = GetDlgItem (IDC_EDIT_ADD);
	if (m_add)
	{
		m_add = FALSE;
		child->EnableWindow (FALSE);
	}
	else
	{
		m_add = TRUE;
		child->EnableWindow();
	}
	UpdateData (FALSE);
	Restart();
	
}

void CSoundrobberDlg::OnCheckMapper() 
{
	if (m_mapper)
		m_mapper = FALSE;
	else
		m_mapper = TRUE;
	UpdateData (FALSE);
	Restart();
}

//////////////////// Ende CheckBox-Handlers /////////////////////////////


// Spin-Control -> Speed
void CSoundrobberDlg::OnDeltaposSpinSpeed(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	static int speeds[] = {4000, 8000, 11025, 22050, 44100};
	static int idx = 2;
	if (pNMUpDown->iDelta < 0)
		idx++;
	else
		idx--;
	if (idx < 0)
		idx = 0;
	if (idx > 4)
		idx = 4;
	m_speed = speeds[idx];
	UpdateData (FALSE);
	Restart();
	*pResult = 0;
}


// Play!!!
void CSoundrobberDlg::OnButtonPlay() 
{
	void *data;
	WORD channels = 1;
	WORD bits = 8;
	// Erstmal alle Class-Wizard-Variablen auffrischen...
	UpdateData();
	// Daten in'n Speicher lesen
	data = m_memfile.Read (m_filestart, m_fileend);
	// Xorren?
	if (m_xor)
		m_memfile.XorByte (m_xorvalue);
	// Byte aufaddieren?
	if (m_add)
		m_memfile.AddByte (m_addvalue);
	// Eventuell Rueckwaerts spielen
	if (m_reverse)
		m_memfile.Reverse();
	// Stereo?
	if (m_stereo)
		channels = 2;
	// 16Bits?
	if (m_16bits)
		bits = 16;
	// ... und los!
	MMRESULT mmr;
	mmr = m_waveplay.Play (channels, m_speed, bits, data, 
							m_fileend-m_filestart, m_mapper);
	// Abspielen schiefgegeangen, dann sofort raus
	if (mmr |= MMSYSERR_NOERROR)
		return;
	// Lautstaerke einstellen
	int volume = mp_scroll_volume->GetScrollPos();
	m_waveplay.SetVolume (65535-(WORD)(256*volume), 65535-(WORD)(256*volume));
	// Timer starten zur Anzeige der WavePosition
	SetTimer (1, 100, NULL);
	// PositionsAnzeige uebernehmen
	m_position = m_filestart;
	UpdateData (FALSE);
}

// Stop!!!
void CSoundrobberDlg::OnButtonStop() 
{
	// Wave abspielen stoppen...
	m_waveplay.Stop();
	// Timer anhalten
	KillTimer (1);
}

// Manuelle Eingabe der EndPosition
void CSoundrobberDlg::OnKillfocusEditEnd() 
{
	long tmp = m_fileend;
	m_fileend = (long)GetDlgItemInt (IDC_EDIT_END);
	if (m_fileend <= m_filestart)
		m_fileend = tmp;
	if (m_fileend > (long)m_memfile.GetLength())
		m_fileend = tmp;
	
	// Slider nachziehen
	m_slider_end.SetPos (m_fileend);

	UpdateData (FALSE);
}

// Manuelle Eingabe der StartPosition
void CSoundrobberDlg::OnKillfocusEditStart() 
{
	long tmp = m_filestart;
	m_filestart = (long)GetDlgItemInt (IDC_EDIT_START);
	if (m_filestart > m_fileend)
		m_filestart = tmp;
	m_position = m_filestart;

	// Slider nachziehen
	m_slider_start.SetPos (m_filestart);

	UpdateData (FALSE);
}

// Manuelle Eingabe der Gewschwindigkeit
void CSoundrobberDlg::OnKillfocusEditSpeed() 
{
	UpdateData();
}

// Timer-Prozedur zur Anzeige der WavePosition
void CSoundrobberDlg::OnTimer (UINT nIDEvent) 
{
	DWORD wavepos = m_waveplay.GetPosition();
	m_position = m_filestart + wavepos;
	
	// Current Pos und Scope aktualisieren
	SetDlgItemInt (IDC_POSITION, m_position, FALSE);
	m_scope.UpdateView ((BYTE *)m_memfile.GetPointer() + wavepos);

	// Wenn FileEnde erreicht, dann Wave-abspielen stoppen/schliessen
	// ... und Ossi resetten
	if (m_position >= m_fileend-1)
	{	
		m_scope.Reset();
		RemoteStop();
	}
}

//////////////////////////////// Get Buttons /////////////////////

// Ende des Waves aus'm Pos-Control holen
void CSoundrobberDlg::OnGetEnd() 
{
	m_fileend = m_position;
	UpdateData (FALSE);
	// Slider anpassen
	m_slider_end.SetPos (m_position);
	// Stop-Button druecken
	RemoteStop();
}

// Start des Waves aus'm Pos-Control holen
void CSoundrobberDlg::OnGetStart() 
{
	m_filestart = m_position;
	UpdateData (FALSE);
	// Slider anpassen
	m_slider_start.SetPos (m_position);
	// Stop-Button druecken
	RemoteStop();
}


///////////////////////////// Volume ScrollBar Messages ////////////////////

void CSoundrobberDlg::OnVScroll (UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (pScrollBar == mp_scroll_volume)
	{
		int pos = pScrollBar->GetScrollPos();
		switch (nSBCode)
		{
			case SB_LINEDOWN:
			pos += 1;
			break;

			case SB_PAGEDOWN:
			pos += 10;
			break;
			
			case SB_LINEUP:
			pos -= 1;
			break;

			case SB_PAGEUP:
			pos -= 10;
			break;
			
			case SB_THUMBPOSITION:
			pos = (int)(nPos);
			break;
		}
		pScrollBar->SetScrollPos (pos);
		if (m_waveplay.IsActive())
			m_waveplay.SetVolume ((WORD)(65535-256*pos), (WORD)(65535-256*pos));
	}
	else
		CDialog::OnVScroll (nSBCode, nPos, pScrollBar);
}

///////////////////// Slider - Messages ///////////////////

void CSoundrobberDlg::OnHScroll (UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	switch (nSBCode)
	{
		case TB_THUMBTRACK:
		case TB_PAGEDOWN:
		case TB_PAGEUP:
		if ((CSliderCtrl *)pScrollBar == &m_slider_start)
		{
			m_filestart = m_slider_start.GetPos();
			if (m_filestart > m_fileend)
			{
				m_fileend = m_filestart;
				m_slider_end.SetPos (m_filestart);
			}
		}
		else if	((CSliderCtrl *)pScrollBar == &m_slider_end)
		{
			m_fileend = m_slider_end.GetPos();
			if (m_fileend < m_filestart)
			{
				m_filestart = m_fileend;
				m_slider_start.SetPos (m_fileend);
			}
		}
		break;
	}
	UpdateData (FALSE);
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
