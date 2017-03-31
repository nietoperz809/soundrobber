// Scope.cpp : implementation file
//

#include "stdafx.h"
#include "soundrobber.h"
#include "Scope.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScope

CScope::CScope()
{
	hdc = 0;
	hwnd = 0;
}

CScope::~CScope()
{

}


BEGIN_MESSAGE_MAP(CScope, CStatic)
	//{{AFX_MSG_MAP(CScope)
	ON_WM_DESTROY()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScope message handlers


void CScope::OnDestroy() 
{
	::ReleaseDC (hwnd, hdc);
	::DeleteObject (hp_green);
	delete [] pts;
	CStatic::OnDestroy();
}


void CScope::OnPaint() 
{
	// Window-Spezifische Initialisierungen	werden hier gemacht,
	// Weil ein CStatic kein WM_CREATE kriegt!!!!
	if (!hdc)
	{	RECT rect;
		GetClientRect (&rect);
		cx = rect.right;
		cy = rect.bottom;
		cy2 = cy/2;
		cyscope = cy2-16;
		hwnd = GetSafeHwnd();
		hdc = ::GetDC (hwnd);
		hp_green = ::CreatePen (PS_SOLID, 1, RGB(0,255,0));
		::SelectObject (hdc, hp_green);
		pts = new POINT[cx];
		Reset();
	}

	PAINTSTRUCT ps;
	::BeginPaint (hwnd, &ps);
	::PatBlt (hdc, 0, 0, cx, cy, BLACKNESS);
	::Polyline (hdc, pts, cx);
	::EndPaint (hwnd, &ps); 
}


///////////////////////// Eigene Methoden /////////////////////
//

// Alle Points zuruecksetzen (Linie)
void CScope::Reset (void)
{
	int s;
	for (s=0; s<cx; s++)
	{	pts[s].x = s;
		pts[s].y = cy2;
	}
	::PatBlt (hdc, 0, 0, cx, cy, BLACKNESS);
	::Polyline (hdc, pts, cx);
}


