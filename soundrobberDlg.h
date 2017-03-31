// soundrobberDlg.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// CSoundrobberDlg dialog

class CSoundrobberDlg : public CDialog
{
// Construction
public:
	CSoundrobberDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSoundrobberDlg)
	enum { IDD = IDD_SOUNDROBBER_DIALOG };
	CSliderCtrl	m_slider_start;
	CSliderCtrl	m_slider_end;
	CScope	m_scope;
	CSpinButtonCtrl	m_spinspeed;
	BOOL	m_mono;
	BOOL	m_stereo;
	BOOL	m_reverse;
	long	m_fileend;
	long	m_filestart;
	int		m_speed;
	BOOL	m_16bits;
	BOOL	m_8bits;
	long	m_position;
	BOOL	m_add;
	BOOL	m_xor;
	BYTE	m_addvalue;
	BYTE	m_xorvalue;
	BOOL	m_mapper;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoundrobberDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CMemoryFile m_memfile;
	CWavePlay m_waveplay;
	CString m_pathname;
	CString m_filename;
	CScrollBar *mp_scroll_volume;

	void ResetView (void);
	void RemoteStop (void);
	void RemoteStart (void);
	void Restart (void);
	void FileOpenProc (void);

	// Generated message map functions
	//{{AFX_MSG(CSoundrobberDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonOpen();
	afx_msg void OnCheckMono();
	afx_msg void OnCheckStereo();
	afx_msg void OnCheckReverse();
	afx_msg void OnDeltaposSpinSpeed(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnButtonPlay();
	afx_msg void OnButtonStop();
	afx_msg void OnKillfocusEditSpeed();
	afx_msg void OnCheck16bits();
	afx_msg void OnCheck8bits();
	afx_msg void OnButtonWave();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnGetEnd();
	afx_msg void OnGetStart();
	afx_msg void OnKillfocusEditStart();
	afx_msg void OnKillfocusEditEnd();
	afx_msg void OnSetfocusPosition();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnCheckXor();
	afx_msg void OnCheckAdd();
	afx_msg void OnCheckMapper();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
