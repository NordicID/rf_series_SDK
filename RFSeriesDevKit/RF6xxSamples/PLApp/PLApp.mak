# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=PLApp - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to PLApp - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "PLApp - Win32 Release" && "$(CFG)" != "PLApp - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "PLApp.mak" CFG="PLApp - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PLApp - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PLApp - Win32 Debug" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "PLApp - Win32 Debug"
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "PLApp - Win32 Release"

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

ALL : "$(OUTDIR)\PLApp.exe"

CLEAN : 
	-@erase ".\Release\PLApp.exe"
	-@erase ".\Release\StdAfx.obj"
	-@erase ".\Release\PLApp.obj"
	-@erase ".\Release\PLApp.pch"
	-@erase ".\Release\PrdDlg.obj"
	-@erase ".\Release\PLAppDoc.obj"
	-@erase ".\Release\plocx2.obj"
	-@erase ".\Release\MainFrm.obj"
	-@erase ".\Release\Yleis.obj"
	-@erase ".\Release\PLAppView.obj"
	-@erase ".\Release\PLApp.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/PLApp.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x40b /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x40b /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x40b /fo"$(INTDIR)/PLApp.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/PLApp.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/PLApp.pdb" /machine:I386 /out:"$(OUTDIR)/PLApp.exe" 
LINK32_OBJS= \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/PLApp.obj" \
	"$(INTDIR)/PrdDlg.obj" \
	"$(INTDIR)/PLAppDoc.obj" \
	"$(INTDIR)/plocx2.obj" \
	"$(INTDIR)/MainFrm.obj" \
	"$(INTDIR)/Yleis.obj" \
	"$(INTDIR)/PLAppView.obj" \
	"$(INTDIR)/PLApp.res"

"$(OUTDIR)\PLApp.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PLApp - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\PLApp.exe"

CLEAN : 
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\PLApp.pch"
	-@erase ".\Debug\vc40.idb"
	-@erase ".\Debug\PLApp.exe"
	-@erase ".\Debug\plocx2.obj"
	-@erase ".\Debug\MainFrm.obj"
	-@erase ".\Debug\PLAppView.obj"
	-@erase ".\Debug\PLApp.obj"
	-@erase ".\Debug\Yleis.obj"
	-@erase ".\Debug\StdAfx.obj"
	-@erase ".\Debug\PrdDlg.obj"
	-@erase ".\Debug\PLAppDoc.obj"
	-@erase ".\Debug\PLApp.res"
	-@erase ".\Debug\PLApp.ilk"
	-@erase ".\Debug\PLApp.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/PLApp.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x40b /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x40b /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x40b /fo"$(INTDIR)/PLApp.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/PLApp.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/PLApp.pdb" /debug /machine:I386 /out:"$(OUTDIR)/PLApp.exe" 
LINK32_OBJS= \
	"$(INTDIR)/plocx2.obj" \
	"$(INTDIR)/MainFrm.obj" \
	"$(INTDIR)/PLAppView.obj" \
	"$(INTDIR)/PLApp.obj" \
	"$(INTDIR)/Yleis.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/PrdDlg.obj" \
	"$(INTDIR)/PLAppDoc.obj" \
	"$(INTDIR)/PLApp.res"

"$(OUTDIR)\PLApp.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

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

################################################################################
# Begin Target

# Name "PLApp - Win32 Release"
# Name "PLApp - Win32 Debug"

!IF  "$(CFG)" == "PLApp - Win32 Release"

!ELSEIF  "$(CFG)" == "PLApp - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "PLApp - Win32 Release"

!ELSEIF  "$(CFG)" == "PLApp - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PLApp.cpp
DEP_CPP_PLAPP=\
	".\StdAfx.h"\
	".\PLApp.h"\
	".\MainFrm.h"\
	".\PLAppDoc.h"\
	".\PLAppView.h"\
	".\plocx2.h"\
	

"$(INTDIR)\PLApp.obj" : $(SOURCE) $(DEP_CPP_PLAPP) "$(INTDIR)"\
 "$(INTDIR)\PLApp.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "PLApp - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/PLApp.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c\
 $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\PLApp.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "PLApp - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/PLApp.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\PLApp.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\StdAfx.h"\
	".\PLApp.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\PLApp.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PLAppDoc.cpp
DEP_CPP_PLAPPD=\
	".\StdAfx.h"\
	".\PLApp.h"\
	".\PLAppDoc.h"\
	".\PrdDlg.h"\
	

"$(INTDIR)\PLAppDoc.obj" : $(SOURCE) $(DEP_CPP_PLAPPD) "$(INTDIR)"\
 "$(INTDIR)\PLApp.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PLAppView.cpp

!IF  "$(CFG)" == "PLApp - Win32 Release"

DEP_CPP_PLAPPV=\
	".\StdAfx.h"\
	".\PLApp.h"\
	".\const.h"\
	".\PLAppDoc.h"\
	".\PLAppView.h"\
	".\Yleis.h"\
	".\plocx2.h"\
	

"$(INTDIR)\PLAppView.obj" : $(SOURCE) $(DEP_CPP_PLAPPV) "$(INTDIR)"\
 "$(INTDIR)\PLApp.pch"


!ELSEIF  "$(CFG)" == "PLApp - Win32 Debug"

DEP_CPP_PLAPPV=\
	".\StdAfx.h"\
	".\PLApp.h"\
	".\const.h"\
	".\PLAppDoc.h"\
	".\PLAppView.h"\
	".\Yleis.h"\
	".\plocx2.h"\
	
NODEP_CPP_PLAPPV=\
	".\m_plocx"\
	

"$(INTDIR)\PLAppView.obj" : $(SOURCE) $(DEP_CPP_PLAPPV) "$(INTDIR)"\
 "$(INTDIR)\PLApp.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PLApp.rc
DEP_RSC_PLAPP_=\
	".\res\PLApp.ico"\
	".\res\PLAppDoc.ico"\
	".\res\Toolbar.bmp"\
	".\res\PLApp.rc2"\
	

"$(INTDIR)\PLApp.res" : $(SOURCE) $(DEP_RSC_PLAPP_) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\plocx2.cpp
DEP_CPP_PLOCX=\
	".\StdAfx.h"\
	".\plocx2.h"\
	

"$(INTDIR)\plocx2.obj" : $(SOURCE) $(DEP_CPP_PLOCX) "$(INTDIR)"\
 "$(INTDIR)\PLApp.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PrdDlg.cpp
DEP_CPP_PRDDL=\
	".\StdAfx.h"\
	".\PLApp.h"\
	".\PrdDlg.h"\
	

"$(INTDIR)\PrdDlg.obj" : $(SOURCE) $(DEP_CPP_PRDDL) "$(INTDIR)"\
 "$(INTDIR)\PLApp.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Yleis.cpp
DEP_CPP_YLEIS=\
	".\StdAfx.h"\
	".\Yleis.h"\
	

"$(INTDIR)\Yleis.obj" : $(SOURCE) $(DEP_CPP_YLEIS) "$(INTDIR)"\
 "$(INTDIR)\PLApp.pch"


# End Source File
# End Target
# End Project
################################################################################
################################################################################
# Section PLApp : {EF9BA243-FBBD-11D1-84F3-444553540000}
# 	0:8:PLOCX2.h:D:\MSDEV\Projects\PLApp\PLOCX2.h
# 	0:10:PLOCX2.cpp:D:\MSDEV\Projects\PLApp\PLOCX2.cpp
# 	2:21:DefaultSinkHeaderFile:plocx2.h
# 	2:16:DefaultSinkClass:CPLOCX2
# End Section
################################################################################
################################################################################
# Section OLE Controls
# 	{EF9BA243-FBBD-11D1-84F3-444553540000}
# End Section
################################################################################
################################################################################
# Section PLApp : {EF9BA241-FBBD-11D1-84F3-444553540000}
# 	2:5:Class:CPLOCX2
# 	2:10:HeaderFile:plocx2.h
# 	2:8:ImplFile:plocx2.cpp
# End Section
################################################################################
