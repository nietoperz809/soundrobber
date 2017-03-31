// Scope.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScope window

class CScope : public CStatic
{
// Construction
public:
	CScope();

// Attributes
public:
	HWND hwnd;
	HDC hdc;
	HPEN hp_green;
	POINT *pts;
	int cx;
	int cy;
	int cy2;
	int cyscope;

// Operations
public:
	void Reset (void);
	
// Inline Funcs	
	// Neuen Wert aufnehmen und Anzeigen
	void UpdateView (BYTE *ptr)
	{
		int s;
		for (s=0; s<cx; s++)
			pts[s].y = cyscope + ptr[s]/8;	
		::PatBlt (hdc, 0, 0, cx, cy, BLACKNESS);
		::Polyline (hdc, pts, cx);
	}
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScope)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CScope();

	// Generated message map functions
protected:
	//{{AFX_MSG(CScope)
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
