// WaveDevCaps.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWaveDevCaps dialog

class CWaveDevCaps : public CDialog
{
// Construction
public:
	CWaveDevCaps(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWaveDevCaps)
	enum { IDD = IDD_DEVCAPS_DIALOG };
	CString	m_dcapsview;
	int		m_Combo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWaveDevCaps)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_str;
	CString Str (int value); // Wert zu String machen
	void FillBox (int device); // Edit-Box fuellen

	// Generated message map functions
	//{{AFX_MSG(CWaveDevCaps)
	afx_msg void OnSelchangeComboDevs();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
