# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=soundrobber - Win32 Release
!MESSAGE No configuration specified.  Defaulting to soundrobber - Win32\
 Release.
!ENDIF 

!IF "$(CFG)" != "soundrobber - Win32 Release" && "$(CFG)" !=\
 "soundrobber - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "soundrobber.mak" CFG="soundrobber - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "soundrobber - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "soundrobber - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "soundrobber - Win32 Release"
MTL=mktyplib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "soundrobber - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\soundrobber.exe"

CLEAN : 
	-@erase "$(INTDIR)\about.obj"
	-@erase "$(INTDIR)\MemoryFile.obj"
	-@erase "$(INTDIR)\Scope.obj"
	-@erase "$(INTDIR)\soundrobber.obj"
	-@erase "$(INTDIR)\soundrobber.pch"
	-@erase "$(INTDIR)\soundrobber.res"
	-@erase "$(INTDIR)\soundrobberDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\WaveDevCaps.obj"
	-@erase "$(INTDIR)\WavePlay.obj"
	-@erase "$(OUTDIR)\soundrobber.exe"
	-@erase "$(OUTDIR)\soundrobber.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /Gi /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /Gi /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/soundrobber.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/soundrobber.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 winmm.lib /nologo /subsystem:windows /incremental:yes /machine:I386
LINK32_FLAGS=winmm.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/soundrobber.pdb" /machine:I386 /out:"$(OUTDIR)/soundrobber.exe"\
 
LINK32_OBJS= \
	"$(INTDIR)\about.obj" \
	"$(INTDIR)\MemoryFile.obj" \
	"$(INTDIR)\Scope.obj" \
	"$(INTDIR)\soundrobber.obj" \
	"$(INTDIR)\soundrobber.res" \
	"$(INTDIR)\soundrobberDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WaveDevCaps.obj" \
	"$(INTDIR)\WavePlay.obj"

"$(OUTDIR)\soundrobber.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "soundrobber - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "soundrob"
# PROP BASE Intermediate_Dir "soundrob"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "soundrob"
# PROP Intermediate_Dir "soundrob"
# PROP Target_Dir ""
OUTDIR=.\soundrob
INTDIR=.\soundrob

ALL : "$(OUTDIR)\soundrobber.exe" "$(OUTDIR)\soundrobber.bsc"

CLEAN : 
	-@erase "$(INTDIR)\about.obj"
	-@erase "$(INTDIR)\about.sbr"
	-@erase "$(INTDIR)\MemoryFile.obj"
	-@erase "$(INTDIR)\MemoryFile.sbr"
	-@erase "$(INTDIR)\Scope.obj"
	-@erase "$(INTDIR)\Scope.sbr"
	-@erase "$(INTDIR)\soundrobber.obj"
	-@erase "$(INTDIR)\soundrobber.pch"
	-@erase "$(INTDIR)\soundrobber.res"
	-@erase "$(INTDIR)\soundrobber.sbr"
	-@erase "$(INTDIR)\soundrobberDlg.obj"
	-@erase "$(INTDIR)\soundrobberDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\WaveDevCaps.obj"
	-@erase "$(INTDIR)\WaveDevCaps.sbr"
	-@erase "$(INTDIR)\WavePlay.obj"
	-@erase "$(INTDIR)\WavePlay.sbr"
	-@erase "$(OUTDIR)\soundrobber.bsc"
	-@erase "$(OUTDIR)\soundrobber.exe"
	-@erase "$(OUTDIR)\soundrobber.ilk"
	-@erase "$(OUTDIR)\soundrobber.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /Gi /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /G3 /MD /W3 /Gi /GX /Zi /Od /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /G3 /MD /W3 /Gi /GX /Zi /Od /D "WIN32" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/soundrobber.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\soundrob/
CPP_SBRS=.\soundrob/
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/soundrobber.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\about.sbr" \
	"$(INTDIR)\MemoryFile.sbr" \
	"$(INTDIR)\Scope.sbr" \
	"$(INTDIR)\soundrobber.sbr" \
	"$(INTDIR)\soundrobberDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\WaveDevCaps.sbr" \
	"$(INTDIR)\WavePlay.sbr"

"$(OUTDIR)\soundrobber.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 winmm.lib /nologo /subsystem:windows /incremental:yes /machine:I386
# ADD LINK32 winmm.lib /nologo /subsystem:windows /incremental:yes /debug /machine:I386
LINK32_FLAGS=winmm.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/soundrobber.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/soundrobber.exe" 
LINK32_OBJS= \
	"$(INTDIR)\about.obj" \
	"$(INTDIR)\MemoryFile.obj" \
	"$(INTDIR)\Scope.obj" \
	"$(INTDIR)\soundrobber.obj" \
	"$(INTDIR)\soundrobber.res" \
	"$(INTDIR)\soundrobberDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WaveDevCaps.obj" \
	"$(INTDIR)\WavePlay.obj"

"$(OUTDIR)\soundrobber.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

MTL_PROJ=/nologo /D "NDEBUG" /win32 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

RSC_PROJ=/l 0x409 /fo"$(INTDIR)/soundrobber.res" /d "NDEBUG" /d "_AFXDLL" 
################################################################################
# Begin Target

# Name "soundrobber - Win32 Release"
# Name "soundrobber - Win32 Debug"

!IF  "$(CFG)" == "soundrobber - Win32 Release"

!ELSEIF  "$(CFG)" == "soundrobber - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\soundrobber.cpp
DEP_CPP_SOUND=\
	".\about.h"\
	".\MemoryFile.h"\
	".\Scope.h"\
	".\soundrobber.h"\
	".\soundrobberDlg.h"\
	".\StdAfx.h"\
	".\WavePlay.h"\
	

!IF  "$(CFG)" == "soundrobber - Win32 Release"


"$(INTDIR)\soundrobber.obj" : $(SOURCE) $(DEP_CPP_SOUND) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ELSEIF  "$(CFG)" == "soundrobber - Win32 Debug"


"$(INTDIR)\soundrobber.obj" : $(SOURCE) $(DEP_CPP_SOUND) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"

"$(INTDIR)\soundrobber.sbr" : $(SOURCE) $(DEP_CPP_SOUND) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\soundrobberDlg.cpp
DEP_CPP_SOUNDR=\
	".\about.h"\
	".\MemoryFile.h"\
	".\Scope.h"\
	".\soundrobber.h"\
	".\soundrobberDlg.h"\
	".\StdAfx.h"\
	".\WaveDevCaps.h"\
	".\WavePlay.h"\
	

!IF  "$(CFG)" == "soundrobber - Win32 Release"


"$(INTDIR)\soundrobberDlg.obj" : $(SOURCE) $(DEP_CPP_SOUNDR) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ELSEIF  "$(CFG)" == "soundrobber - Win32 Debug"


"$(INTDIR)\soundrobberDlg.obj" : $(SOURCE) $(DEP_CPP_SOUNDR) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"

"$(INTDIR)\soundrobberDlg.sbr" : $(SOURCE) $(DEP_CPP_SOUNDR) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "soundrobber - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /Gi /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/soundrobber.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\soundrobber.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "soundrobber - Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /G3 /MD /W3 /Gi /GX /Zi /Od /D "WIN32" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/soundrobber.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\StdAfx.sbr" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\soundrobber.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\soundrobber.rc
DEP_RSC_SOUNDRO=\
	".\res\soundrobber.rc2"\
	".\res\treiber.ico"\
	

"$(INTDIR)\soundrobber.res" : $(SOURCE) $(DEP_RSC_SOUNDRO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\WavePlay.cpp
DEP_CPP_WAVEP=\
	".\StdAfx.h"\
	".\WavePlay.h"\
	

!IF  "$(CFG)" == "soundrobber - Win32 Release"


"$(INTDIR)\WavePlay.obj" : $(SOURCE) $(DEP_CPP_WAVEP) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ELSEIF  "$(CFG)" == "soundrobber - Win32 Debug"


"$(INTDIR)\WavePlay.obj" : $(SOURCE) $(DEP_CPP_WAVEP) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"

"$(INTDIR)\WavePlay.sbr" : $(SOURCE) $(DEP_CPP_WAVEP) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\WaveDevCaps.cpp
DEP_CPP_WAVED=\
	".\soundrobber.h"\
	".\StdAfx.h"\
	".\WaveDevCaps.h"\
	

!IF  "$(CFG)" == "soundrobber - Win32 Release"


"$(INTDIR)\WaveDevCaps.obj" : $(SOURCE) $(DEP_CPP_WAVED) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ELSEIF  "$(CFG)" == "soundrobber - Win32 Debug"


"$(INTDIR)\WaveDevCaps.obj" : $(SOURCE) $(DEP_CPP_WAVED) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"

"$(INTDIR)\WaveDevCaps.sbr" : $(SOURCE) $(DEP_CPP_WAVED) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MemoryFile.cpp
DEP_CPP_MEMOR=\
	".\MemoryFile.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "soundrobber - Win32 Release"


"$(INTDIR)\MemoryFile.obj" : $(SOURCE) $(DEP_CPP_MEMOR) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ELSEIF  "$(CFG)" == "soundrobber - Win32 Debug"


"$(INTDIR)\MemoryFile.obj" : $(SOURCE) $(DEP_CPP_MEMOR) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"

"$(INTDIR)\MemoryFile.sbr" : $(SOURCE) $(DEP_CPP_MEMOR) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\about.cpp
DEP_CPP_ABOUT=\
	".\about.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "soundrobber - Win32 Release"


"$(INTDIR)\about.obj" : $(SOURCE) $(DEP_CPP_ABOUT) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ELSEIF  "$(CFG)" == "soundrobber - Win32 Debug"


"$(INTDIR)\about.obj" : $(SOURCE) $(DEP_CPP_ABOUT) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"

"$(INTDIR)\about.sbr" : $(SOURCE) $(DEP_CPP_ABOUT) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\doku.txt

!IF  "$(CFG)" == "soundrobber - Win32 Release"

!ELSEIF  "$(CFG)" == "soundrobber - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Scope.cpp
DEP_CPP_SCOPE=\
	".\Scope.h"\
	".\soundrobber.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "soundrobber - Win32 Release"


"$(INTDIR)\Scope.obj" : $(SOURCE) $(DEP_CPP_SCOPE) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ELSEIF  "$(CFG)" == "soundrobber - Win32 Debug"


"$(INTDIR)\Scope.obj" : $(SOURCE) $(DEP_CPP_SCOPE) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"

"$(INTDIR)\Scope.sbr" : $(SOURCE) $(DEP_CPP_SCOPE) "$(INTDIR)"\
 "$(INTDIR)\soundrobber.pch"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
