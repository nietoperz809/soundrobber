; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSoundrobberDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "soundrobber.h"
LastPage=0

ClassCount=5
Class1=CSoundrobberApp
Class2=CAboutDlg
Class3=CSoundrobberDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDD_DEVCAPS_DIALOG
Class4=CWaveDevCaps
Class5=CScope
Resource3=IDD_SOUNDROBBER_DIALOG

[CLS:CSoundrobberApp]
Type=0
BaseClass=CWinApp
HeaderFile=soundrobber.h
ImplementationFile=soundrobber.cpp
LastObject=CSoundrobberApp
Filter=N
VirtualFilter=AC

[CLS:CAboutDlg]
Type=0
HeaderFile=about.h
ImplementationFile=about.cpp
BaseClass=CDialog
LastObject=CAboutDlg
Filter=D
VirtualFilter=dWC

[CLS:CSoundrobberDlg]
Type=0
BaseClass=CDialog
HeaderFile=soundrobberDlg.h
ImplementationFile=soundrobberDlg.cpp
Filter=W
VirtualFilter=dWC
LastObject=CSoundrobberDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=2
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352

[DLG:IDD_SOUNDROBBER_DIALOG]
Type=1
Class=CSoundrobberDlg
ControlCount=37
Control1=IDC_BUTTON_OPEN,button,1342177280
Control2=IDC_BUTTON_PLAY,button,1342177280
Control3=IDC_BUTTON_STOP,button,1342177280
Control4=IDC_BUTTON_WAVE,button,1342177280
Control5=IDC_EDIT_END,edit,1350566016
Control6=IDC_EDIT_START,edit,1350566016
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_SPEED,edit,1350566016
Control10=IDC_SPIN_SPEED,msctls_updown32,1342177312
Control11=IDC_STATIC,button,1342210823
Control12=IDC_STATIC,static,1342308352
Control13=IDC_CHECK_MONO,button,1342177282
Control14=IDC_CHECK_STEREO,button,1342177282
Control15=IDC_CHECK_REVERSE,button,1342177282
Control16=IDC_CHECK_16BITS,button,1342177282
Control17=IDC_CHECK_8BITS,button,1342177282
Control18=IDC_STATIC,button,1342210823
Control19=IDC_POSITION,edit,1484785664
Control20=IDC_STATIC,static,1342177292
Control21=IDC_GET_START,button,1342177280
Control22=IDC_GET_END,button,1342177280
Control23=IDC_STATIC,static,1342177287
Control24=IDC_STATIC,static,1342177284
Control25=IDC_SCROLL_VOLUME,scrollbar,1342177281
Control26=IDC_STATIC,static,1342177280
Control27=IDC_STATIC,static,1342177288
Control28=IDC_STATIC,static,1342177287
Control29=IDC_CHECK_XOR,button,1342177282
Control30=IDC_EDIT_XOR,edit,1350566016
Control31=IDC_CHECK_ADD,button,1342177282
Control32=IDC_EDIT_ADD,edit,1350566016
Control33=IDC_CHECK_MAPPER,button,1342177282
Control34=IDC_PICTURE,static,1350567945
Control35=IDC_STATIC,button,1342178055
Control36=IDC_SLIDER_START,msctls_trackbar32,1342177304
Control37=IDC_SLIDER_END,msctls_trackbar32,1342177304

[DLG:IDD_DEVCAPS_DIALOG]
Type=1
Class=CWaveDevCaps
ControlCount=3
Control1=IDOK,button,1342177280
Control2=IDC_DCAPS,edit,1342183620
Control3=IDC_COMBO_DEVS,combobox,1344274435

[CLS:CWaveDevCaps]
Type=0
HeaderFile=WaveDevCaps.h
ImplementationFile=WaveDevCaps.cpp
BaseClass=CDialog
Filter=D
LastObject=CWaveDevCaps
VirtualFilter=dWC

[CLS:CScope]
Type=0
HeaderFile=Scope.h
ImplementationFile=Scope.cpp
BaseClass=CStatic
Filter=W
LastObject=CScope
VirtualFilter=WC

