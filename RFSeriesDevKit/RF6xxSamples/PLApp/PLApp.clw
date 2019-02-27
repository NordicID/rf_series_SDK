; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=StartServerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PLApp.h"
LastPage=0

ClassCount=7
Class1=CPLAppApp
Class2=CPLAppDoc
Class3=CPLAppView
Class4=CMainFrame

ResourceCount=8
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_PLAPP_FORM
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_PLAPP_FORM (English (U.S.))
Resource6=IDD_PRDADDEDIT_DLG
Class6=CPrdDlg
Resource7=IDR_MAINFRAME (English (U.S.))
Class7=StartServerDlg
Resource8=IDD_STARTSERVER_DLG

[CLS:CPLAppApp]
Type=0
HeaderFile=PLApp.h
ImplementationFile=PLApp.cpp
Filter=N

[CLS:CPLAppDoc]
Type=0
HeaderFile=PLAppDoc.h
ImplementationFile=PLAppDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_AUTOADD

[CLS:CPLAppView]
Type=0
HeaderFile=PLAppView.h
ImplementationFile=PLAppView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=ID_DISCONNECT

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_FILE_STARTSERVER
BaseClass=CFrameWnd
VirtualFilter=fWC



[CLS:CAboutDlg]
Type=0
HeaderFile=PLApp.cpp
ImplementationFile=PLApp.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
CommandCount=16
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command16=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
CommandCount=14
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE

[DLG:IDD_PLAPP_FORM]
Type=1
Class=CPLAppView

[DLG:IDD_PLAPP_FORM (English (U.S.))]
Type=1
Class=CPLAppView
ControlCount=2
Control1=IDC_PRDLIST,SysListView32,1350631429
Control2=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_ADDPRD
Command5=ID_EDITPRD
Command6=ID_REMOVEPRD
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_COM1
Command2=ID_COM2
Command3=ID_COM3
Command4=ID_COM4
Command5=ID_COM5
Command6=ID_COM6
Command7=ID_COM7
Command8=ID_COM8
Command9=ID_COM9
Command10=ID_COM10
Command11=ID_COM11
Command12=ID_COM12
Command13=ID_COM13
Command14=ID_COM14
Command15=ID_COM15
Command16=ID_COM16
Command17=ID_COM17
Command18=ID_COM18
Command19=ID_COM19
Command20=ID_COM20
Command21=ID_DISCONNECT
Command22=ID_FILE_STARTSERVER
Command23=ID_FILE_STOPSERVER
Command24=ID_FILE_NEW
Command25=ID_FILE_OPEN
Command26=ID_FILE_SAVE
Command27=ID_FILE_SAVE_AS
Command28=ID_FILE_PRINT
Command29=ID_FILE_PRINT_PREVIEW
Command30=ID_FILE_PRINT_SETUP
Command31=ID_FILE_MRU_FILE1
Command32=ID_APP_EXIT
Command33=ID_ADDPRD
Command34=ID_EDITPRD
Command35=ID_REMOVEPRD
Command36=ID_AUTOADD
Command37=ID_VIEW_TOOLBAR
Command38=ID_VIEW_STATUS_BAR
Command39=ID_APP_ABOUT
CommandCount=39

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_FILE_SAVE
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_REMOVEPRD
Command9=ID_EDIT_CUT
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
Command12=ID_ADDPRD
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_EDIT_CUT
Command16=ID_EDIT_UNDO
CommandCount=16

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PRDADDEDIT_DLG]
Type=1
Class=CPrdDlg
ControlCount=12
Control1=IDC_CODE_EDIT,edit,1350631424
Control2=IDC_DESCR_EDIT,edit,1350631552
Control3=IDC_PRICE_EDIT,edit,1350631424
Control4=IDC_UNIT_EDIT,edit,1350631424
Control5=IDC_AMOUNT_EDIT,edit,1350631424
Control6=IDOK,button,1342242817
Control7=IDCANCEL,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352

[CLS:CPrdDlg]
Type=0
HeaderFile=PrdDlg.h
ImplementationFile=PrdDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPrdDlg

[DLG:IDD_STARTSERVER_DLG]
Type=1
Class=StartServerDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PORTEDIT,edit,1350639616

[CLS:StartServerDlg]
Type=0
HeaderFile=StartServerDlg.h
ImplementationFile=StartServerDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_ADDPRD

