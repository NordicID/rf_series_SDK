//NORDIC ID DEMO SOFTWARE DISCLAIMER

//You are about to use Nordic ID Demo Software (“Software”).
//It is explicitly stated that Nordic ID does not give any kind of warranties, expressed or implied, for this Software.
//Software is provided “as is” and with all faults.
//Under no circumstances is Nordic ID liable for any direct, special, incidental or indirect damages or for any economic consequential damages to you or to any third party.
//The use of this software indicates your complete and unconditional understanding of the terms of this disclaimer.
//IF YOU DO NOT AGREE OF THE TERMS OF THIS DISCLAIMER, DO NOT USE THE SOFTWARE.


// PLMultiThreadDlg.cpp : implementation file
// 13.6.2006 Ari Pöyhönen Nordic ID
//Sample code to demonstrate using new WHAT command implementation

#include "stdafx.h"
#include "PLMultiThread.h"
#include "PLMultiThreadDlg.h"
#include "DataProcessing.h"
#include "yleis.h"
#include "plconst.h"
#include "BSConnections.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPLMultiThreadDlg dialog

CPLMultiThreadDlg::CPLMultiThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPLMultiThreadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPLMultiThreadDlg)
	m_prosTime = 0;
	m_waitchk = FALSE;
	m_whattime = 0;
	//}}AFX_DATA_INIT

	for(int x=0;x<50;x++)
	{
		hsStatus[x].hsid=0;
		hsStatus[x].status=0;
	}

	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPLMultiThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPLMultiThreadDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_PLSERVERCTRL1, m_pl);
	DDX_Text(pDX, IDC_PROSESSING_TIME, m_prosTime);
	DDX_Check(pDX, IDC_USEWAIT_CHK, m_waitchk);
	DDX_Text(pDX, IDC_WHATTIME, m_whattime);
	DDV_MinMaxInt(pDX, m_whattime, 0, 99);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPLMultiThreadDlg, CDialog)
	//{{AFX_MSG_MAP(CPLMultiThreadDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BS_CONNECTIONS_BUT, OnBsConnectionsBut)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPLMultiThreadDlg message handlers

BOOL CPLMultiThreadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	SetTimer(1,1000,NULL);//We will meet again after 1 second
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPLMultiThreadDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPLMultiThreadDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPLMultiThreadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CPLMultiThreadDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CPLMultiThreadDlg)
	ON_EVENT(CPLMultiThreadDlg, IDC_PLSERVERCTRL1, 1 /* DataArrived */, OnDataArrivedPlserverctrl1, VTS_I4 VTS_I2)
	ON_EVENT(CPLMultiThreadDlg, IDC_PLSERVERCTRL1, 4 /* What */, OnWhatPlserverctrl1, VTS_I4)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CPLMultiThreadDlg::OnDataArrivedPlserverctrl1(long id, short frameid) 
{
	UpdateData(TRUE);

	int index=GetStatusIndex(id);//Get index to HSSTATUS struct

	//Before launching new data handling thread, let's make sure that data is not under processing
	if(hsStatus[index].status==1)
	{//Yes it under process. Send Wait screen
		SendWaitScreen(id);
		return;
	}

	m_DataProcessingThread=(DataProcessing*)AfxBeginThread(RUNTIME_CLASS(DataProcessing),
				THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);

	m_DataProcessingThread->SetOwner(this);
	m_DataProcessingThread->DataToProcess(id,frameid,index);
	m_DataProcessingThread->ResumeThread();
	return;
	
}

void CPLMultiThreadDlg::OnWhatPlserverctrl1(long id) 
{
	int index=GetStatusIndex(id);

	//Hand terminal has sent WHAT code to us.
	//Let's take a look what is situation of data processing.
	//Can we give results of data processing to HS or do we have to ask HS to wait for a while?
	//At least we have to give somekind of answer to the HS
		
	if(hsStatus[index].status==5)//WHAT sended once?
	{
		m_pl.Text(id,141,c(m_counter++));
		m_pl.What(id,255);//Command HS to send WHAT as fast it can
		m_pl.Send(id,-1);

	}
	if(hsStatus[index].status==1)//Still under processing?
	{
		//Still processing.
		//We need to send something to HS.
		//Let's send current time to hand terminal screen
		CTime t = CTime::GetCurrentTime();
		CString timeTxt= t.Format( "%H:%M:%S" );

		m_pl.Text(id,80,"Time:"+timeTxt);
		m_pl.Send(id,-1);		
		
		return;
	}
	if(hsStatus[index].status==2)//Data processed?
	{
		//YES. Data is now processed and we can send results to HS screen
		
		m_pl.PopMessage(id,23,"Data Prosessed");
		m_pl.Beep(id,100,50);//Some beeps
		m_pl.Beep(id,30,50);
		m_pl.Beep(id,30,50);		
		m_pl.What(id,0);//Do not send "WHAT"s anymore
		SendScanScreen(id);		
		/*
		m_pl.ClearForm (id);
		m_pl.Text (id, 0, "Hello, world!");
		m_pl.NewField (id, 40, 10, 0x91);
		m_pl.Bell (id);
		m_pl.Send (id, -1);
		*/

		hsStatus[index].status=0;//no actions anymore
	}

	
}

void CPLMultiThreadDlg::UpDateDlgField() 
{
	UpdateData(FALSE);
}

void CPLMultiThreadDlg::SendWaitScreen(long id)
{
	//Send Text to screen "Please wait"
	//Use Locked input field whitout ability to send by the user
	m_pl.ClearForm(id);
	m_pl.NewField(id,25,11,FLD_LOCK);
	m_pl.FldTxt(id,25,"Please Wait");
	//Set Hand terminal to send WHAT code  every 'm_whattime' second
	m_pl.What(id,m_whattime);
	m_pl.Send(id,-1);
}
void CPLMultiThreadDlg::SendScanScreen(long id)
{
	m_pl.ClearForm(id);
	m_pl.Text(id,20,"Scan Bar Code:");
	m_pl.NewFieldEx(id,40,40,SND_ENTER+OVR+FLD_READER+READER_DEFAULT);
	m_pl.Button(id,100,"Close");
	m_pl.Button(id,120,"Start");
	m_pl.Button(id,130,"Stop");
	m_pl.SetFormID(id,10);
	m_pl.Send(id,10);

}
//GetStatusIndex
//Returns index to HSSTATUS struct
//If Hand terminal ID is not in the list, it will be added and its index returned
int CPLMultiThreadDlg::GetStatusIndex(long hsid)
{
	int x;

	for(x=0;x<50;x++)
	{
		if(hsStatus[x].hsid==hsid) return x;
		if(hsStatus[x].hsid==0)
		{
			hsStatus[x].hsid=hsid;
			return x;
		}
	}

}

void CPLMultiThreadDlg::OnBsConnectionsBut() 
{
	//Let's use PLServer ver 5.x.x new feature for BS connections.
	m_pl.OpenBSConnections();
	
	/*
	BSConnections dlg;

	if(dlg.DoModal()==IDOK)
	{
		if(!dlg.m_comport.IsEmpty())
		{
			//Connecting to the serial port.
			m_pl.Connect(atoi(dlg.m_comport));
		}

		if(!dlg.m_portcli.IsEmpty())
		{
			//Starting server.
			//Server stopped if Port number is 0
			if(dlg.m_portcli=="0") m_pl.StopServer();
			else m_pl.StartServer(atoi(dlg.m_portcli));
		}

		if(!dlg.m_portserv.IsEmpty())
		{
			//Connect to network adapter
			if(dlg.m_ipaddr.GetLength()<8) return;
			m_pl.ConnectToSerialServer(dlg.m_ipaddr,(short)atoi(dlg.m_portserv));
			m_pl.StartServer(atoi(dlg.m_portcli));
		}
	}
	*/
	
}

void CPLMultiThreadDlg::OnTimer(UINT nIDEvent) 
{

	m_list.ResetContent();//Clear list from old shit

	int x;
	CString line;

	//Get all HS from the list and print status of each to the listbox
	for(x=0;x<50;x++)
	{
		if(hsStatus[x].hsid>0)
		{
			line="ID="+c(hsStatus[x].hsid);
			line +="  Status=";
			line+=c(hsStatus[x].status);

			m_list.AddString(line);
		}
			
		if(hsStatus[x].hsid==0) break;		
	}

	SetTimer(1,1000,NULL);//We will meet again after 1 second
	CDialog::OnTimer(nIDEvent);
}
