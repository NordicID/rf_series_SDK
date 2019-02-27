//NORDIC ID DEMO SOFTWARE DISCLAIMER

//You are about to use Nordic ID Demo Software (“Software”).
//It is explicitly stated that Nordic ID does not give any kind of warranties, expressed or implied, for this Software.
//Software is provided “as is” and with all faults.
//Under no circumstances is Nordic ID liable for any direct, special, incidental or indirect damages or for any economic consequential damages to you or to any third party.
//The use of this software indicates your complete and unconditional understanding of the terms of this disclaimer.
//IF YOU DO NOT AGREE OF THE TERMS OF THIS DISCLAIMER, DO NOT USE THE SOFTWARE.

// DataProcessing.cpp : implementation file
//

#include "stdafx.h"
#include "PLMultiThread.h"
#include "DataProcessing.h"
#include "PLMultiThreadDlg.h"
#include "plconst.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DataProcessing

IMPLEMENT_DYNCREATE(DataProcessing, CWinThread)

DataProcessing::DataProcessing()
{
}

DataProcessing::~DataProcessing()
{
}

BOOL DataProcessing::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int DataProcessing::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(DataProcessing, CWinThread)
	//{{AFX_MSG_MAP(DataProcessing)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DataProcessing message handlers
void DataProcessing::DataToProcess(long hsid,short hsframeid,int hsIndex)
{
	id=hsid;
	frameid=hsframeid;	
	ind=hsIndex;
}

int DataProcessing::Run() 
{
	short formID;
	formID=m_dlg->m_pl.GetFormID(id);//Get current form
	if(!formID)
	{
		m_dlg->SendScanScreen(id);//If no current form or func key is pressed, send main menu
		return CWinThread::Run();
	}

	if(formID==10) DataFromScanScreen();
	else m_dlg->SendScanScreen(id);
	
	return CWinThread::Run();
}


void DataProcessing::DataFromScanScreen()
{

	if(m_dlg->m_pl.IsData(id,100)) //Close button pressed
	{	//Show init screen
		m_dlg->m_pl.ClearForm(id);
		m_dlg->m_pl.SetFormID(id,0);
		m_dlg->m_pl.Send(id,0);
		return;
	}
	if(m_dlg->m_pl.IsData(id,120)) //Test1
	{	//Show init screen
		m_dlg->hsStatus[ind].status=5;
		m_dlg->m_counter=0;
		m_dlg->m_pl.What(id,255);
		m_dlg->m_pl.Text(id,141,"1");
		m_dlg->m_pl.SetFormID(id,0);
		m_dlg->m_pl.Send(id,0);
		return;
	}
	if(m_dlg->m_pl.IsData(id,130)) //Test2
	{	//Show init screen
	m_dlg->hsStatus[ind].status=0;
		m_dlg->m_pl.WaitSerial(id,255);
		m_dlg->m_pl.SetFormID(id,0);
		m_dlg->m_pl.Send(id,0);
		return;
	}
	
	//Data from scanned data field	
	//m_dlg->m_barcode=m_dlg->m_pl.GetData(id,40);
	//m_dlg->UpDateDlgField();//Show it in the dialog screen

	if(m_dlg->m_waitchk)
	{		
		m_dlg->SendWaitScreen(id);

		//Processing data...
		m_dlg->hsStatus[ind].status=1;
		Sleep(m_dlg->m_prosTime*1000);
		//Done. Set answer data ready for next WHAT code from HAND terminal
		m_dlg->hsStatus[ind].status=2;
		
		return;
	}
	
			//""DATA PROCESSING""
		Sleep(m_dlg->m_prosTime*1000);
		//Done. Let's give answer
	
	m_dlg->m_pl.PopMessage(id,21,"Data Processed");
	m_dlg->m_pl.FieldCmd(id,40,FLD_ACTIVE);//Set Barcode field active	
	m_dlg->m_pl.Send(id,-1);

}

