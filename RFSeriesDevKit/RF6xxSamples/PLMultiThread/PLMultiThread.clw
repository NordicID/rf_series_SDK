; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=BSConnections
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PLMultiThread.h"

ClassCount=5
Class1=CPLMultiThreadApp
Class2=CPLMultiThreadDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PLMULTITHREAD_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Class4=DataProcessing
Resource5=IDD_PLMULTITHREAD_DIALOG (English (U.S.))
Class5=BSConnections
Resource6=IDD_BSSETDLG

[CLS:CPLMultiThreadApp]
Type=0
HeaderFile=PLMultiThread.h
ImplementationFile=PLMultiThread.cpp
Filter=N

[CLS:CPLMultiThreadDlg]
Type=0
HeaderFile=PLMultiThreadDlg.h
ImplementationFile=PLMultiThreadDlg.cpp
Filter=D
LastObject=IDC_WHATTIME
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=PLMultiThreadDlg.h
ImplementationFile=PLMultiThreadDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_PLMULTITHREAD_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CPLMultiThreadDlg

[DLG:IDD_PLMULTITHREAD_DIALOG (English (U.S.))]
Type=1
Class=CPLMultiThreadDlg
ControlCount=15
Control1=IDCANCEL,button,1342242816
Control2=IDC_PLSERVERCTRL1,{244758C6-A002-11D2-B82B-938DAECFCE37},1342242816
Control3=IDC_LIST,listbox,1352728835
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BS_CONNECTIONS_BUT,button,1342242816
Control6=IDC_USEWAIT_CHK,button,1342242819
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PROSESSING_TIME,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_WHATTIME,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:DataProcessing]
Type=0
HeaderFile=DataProcessing.h
ImplementationFile=DataProcessing.cpp
BaseClass=CWinThread
Filter=N
VirtualFilter=TC
LastObject=DataProcessing

[DLG:IDD_BSSETDLG]
Type=1
Class=BSConnections
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_COMNUMBEREDIT,edit,1350639616
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PORTNOEDIT,edit,1350639616
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_IPADDREDIT,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_PORTEDIT,edit,1350639616

[CLS:BSConnections]
Type=0
HeaderFile=BSConnections.h
ImplementationFile=BSConnections.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_COMNUMBEREDIT

