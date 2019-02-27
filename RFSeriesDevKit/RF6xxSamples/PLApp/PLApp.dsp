# Microsoft Developer Studio Project File - Name="PLApp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=PLApp - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PLApp.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PLApp.mak" CFG="PLApp - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PLApp - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PLApp - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PLApp - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40b /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x40b /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "PLApp - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40b /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x40b /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386

!ENDIF 

# Begin Target

# Name "PLApp - Win32 Release"
# Name "PLApp - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\PLApp.cpp
# End Source File
# Begin Source File

SOURCE=.\PLApp.rc
# End Source File
# Begin Source File

SOURCE=.\PLAppDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\PLAppView.cpp
# End Source File
# Begin Source File

SOURCE=.\plserver.cpp
# End Source File
# Begin Source File

SOURCE=.\PrdDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\StartServerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Yleis.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\const.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\PLApp.h
# End Source File
# Begin Source File

SOURCE=.\PLAppDoc.h
# End Source File
# Begin Source File

SOURCE=.\PLAppView.h
# End Source File
# Begin Source File

SOURCE=.\plserver.h
# End Source File
# Begin Source File

SOURCE=.\PrdDlg.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\StartServerDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Yleis.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\PLApp.ico
# End Source File
# Begin Source File

SOURCE=.\res\PLApp.rc2
# End Source File
# Begin Source File

SOURCE=.\res\PLAppDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# End Target
# End Project
# Section PLApp : {244758C6-A002-11D2-B82B-938DAECFCE37}
# 	2:21:DefaultSinkHeaderFile:plserver.h
# 	2:16:DefaultSinkClass:CPLServer
# End Section
# Section PLApp : {785739C3-A288-11D2-B82B-8D8A650ADC32}
# 	2:5:Class:CPLServer
# 	2:10:HeaderFile:plserver.h
# 	2:8:ImplFile:plserver.cpp
# End Section
# Section PLApp : {EF9BA243-FBBD-11D1-84F3-444553540000}
# 	0:8:PLOCX2.h:D:\MSDEV\Projects\PLApp\PLOCX2.h
# 	0:10:PLOCX2.cpp:D:\MSDEV\Projects\PLApp\PLOCX2.cpp
# 	2:21:DefaultSinkHeaderFile:plocx2.h
# 	2:16:DefaultSinkClass:CPLOCX2
# End Section
# Section OLE Controls
# 	{EF9BA243-FBBD-11D1-84F3-444553540000}
# End Section
# Section PLApp : {EF9BA241-FBBD-11D1-84F3-444553540000}
# 	2:5:Class:CPLOCX2
# 	2:10:HeaderFile:plocx2.h
# 	2:8:ImplFile:plocx2.cpp
# End Section
