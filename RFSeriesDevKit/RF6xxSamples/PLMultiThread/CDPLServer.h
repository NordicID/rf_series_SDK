// CDPLServer.h  : Declaration of ActiveX Control wrapper class(es) created by Microsoft Visual C++

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CDPLServer

class CDPLServer : public CWnd
{
protected:
	DECLARE_DYNCREATE(CDPLServer)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x244758C6, 0xA002, 0x11D2, { 0xB8, 0x2B, 0x93, 0x8D, 0xAE, 0xCF, 0xCE, 0x37 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// Attributes
public:

// Operations
public:

	BOOL Ack(long id)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id);
		return result;
	}
	BOOL Bell(long id)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id);
		return result;
	}
	BOOL Button(long id, short pos, LPCTSTR txt)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_BSTR ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, pos, txt);
		return result;
	}
	BOOL ClearCmd(long id, short cmd, short start, short stop)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_I2 ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, cmd, start, stop);
		return result;
	}
	void ClearSendBuffer(long id)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, id);
	}
	BOOL CmdSet(long id, short * commands, short length)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I2 ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, commands, length);
		return result;
	}
	BOOL Connect(short com_port)
	{
		BOOL result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, com_port);
		return result;
	}
	BOOL FieldCmd(long id, short pos, short fcmd)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, pos, fcmd);
		return result;
	}
	BOOL FldTxt(long id, short pos, LPCTSTR txt)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_BSTR ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, pos, txt);
		return result;
	}
	CString GetData(long id, short pos)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, id, pos);
		return result;
	}
	short GetExtraID(long id)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id);
		return result;
	}
	short GetLastFrameID(long id)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id);
		return result;
	}
	short GetRSSI(long id)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id);
		return result;
	}
	BOOL IsData(long id, short pos)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, pos);
		return result;
	}
	BOOL NewField(long id, short pos, short length, short style)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_I2 ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, pos, length, style);
		return result;
	}
	BOOL PopMessage(long id, short pos, LPCTSTR txt)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_BSTR ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, pos, txt);
		return result;
	}
	BOOL Send(long id, short frameid)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, frameid);
		return result;
	}
	BOOL SetView(long id, short row)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, row);
		return result;
	}
	BOOL Text(long id, short pos, LPCTSTR txt)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_BSTR ;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, pos, txt);
		return result;
	}
	BOOL What(long id, short delay)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, delay);
		return result;
	}
	void DataIn(short * data, short data_len, short source_addr)
	{
		static BYTE parms[] = VTS_PI2 VTS_I2 VTS_I2 ;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_EMPTY, NULL, parms, data, data_len, source_addr);
	}
	BOOL ClearForm(long id)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id);
		return result;
	}
	BOOL StartServer(short port)
	{
		BOOL result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, port);
		return result;
	}
	void StopServer()
	{
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL DataToSerial(long id, LPCTSTR txt)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, txt);
		return result;
	}
	BOOL WaitSerial(long id, short delay)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, delay);
		return result;
	}
	void DisconnectSerialServer(short ssID)
	{
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ssID);
	}
	short ConnectToSerialServer(LPCTSTR addr, short port)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_I2 ;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_I2, (void*)&result, parms, addr, port);
		return result;
	}
	BOOL NewFieldEx(long id, short pos, short length, short style)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_I2 ;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, pos, length, style);
		return result;
	}
	BOOL Receiver(long id, short mode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, mode);
		return result;
	}
	BOOL IsReceiver(long id)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id);
		return result;
	}
	BOOL SendMsg(long receiverID, long senderID, short frameid, short resendTimes)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I2 VTS_I2 ;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, receiverID, senderID, frameid, resendTimes);
		return result;
	}
	short GetFormID(long id)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id);
		return result;
	}
	BOOL SetFormID(long id, short formID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, formID);
		return result;
	}
	BOOL IsLastAnswerToHsOk(long id)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id);
		return result;
	}
	short GetMessageNumber(long id)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id);
		return result;
	}
	CString GetHsIdString(long id)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, id);
		return result;
	}
	short GetSerialData(long id, short * serdata)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI2 ;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id, serdata);
		return result;
	}
	short GetReceiveBuffer(long id, short * data)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI2 ;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id, data);
		return result;
	}
	void SetBSCollectDelay(short msDelay)
	{
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, msDelay);
	}
	BOOL Beep(long id, short length, short delay)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 ;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, length, delay);
		return result;
	}
	void SendSSMAck(short ssmID)
	{
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x2c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ssmID);
	}
	BOOL SendSSMData(long ssmID, short msgNum, short * data, short length, short retries)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_PI2 VTS_I2 VTS_I2 ;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ssmID, msgNum, data, length, retries);
		return result;
	}
	short WaitSSMData(short ssmID, short * ssmData, short ms_waitTime)
	{
		short result;
		static BYTE parms[] = VTS_I2 VTS_PI2 VTS_I2 ;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_I2, (void*)&result, parms, ssmID, ssmData, ms_waitTime);
		return result;
	}
	short GetBatteryLevel(long id)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2f, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id);
		return result;
	}
	BOOL RFIDField(long id, short pos, short length, short style, short first_page, short last_page)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 ;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, pos, length, style, first_page, last_page);
		return result;
	}
	short RFIDReadPages(long id, short firstPage, short lastPage, short * dataBuffer, short msWait)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_PI2 VTS_I2 ;
		InvokeHelper(0x31, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id, firstPage, lastPage, dataBuffer, msWait);
		return result;
	}
	short SendWaitRFIDEngineData(long id, short len, short * dataBuffer, short msWait)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_PI2 VTS_I2 ;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id, len, dataBuffer, msWait);
		return result;
	}
	BOOL SpecialCmd(long id, short type, long data)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_I4 ;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, type, data);
		return result;
	}
	short GetSpecialData(long id, short type)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x34, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id, type);
		return result;
	}
	BOOL RedirSSMtoNetworkAdapter(long ssmID, short sessionID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x35, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ssmID, sessionID);
		return result;
	}
	short GetStatus(long id)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id);
		return result;
	}
	BOOL WaitReceiverAck(long id)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id);
		return result;
	}
	short GetLogItemCount()
	{
		short result;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	BOOL GetLogItem(short ind, long * logStruct)
	{
		BOOL result;
		static BYTE parms[] = VTS_I2 VTS_PI4 ;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ind, logStruct);
		return result;
	}
	void SetLog(short mode, short eventBetweenXitems)
	{
		static BYTE parms[] = VTS_I2 VTS_I2 ;
		InvokeHelper(0x3a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, mode, eventBetweenXitems);
	}
	BOOL StartDataInLog(LPCTSTR logFile)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x3b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, logFile);
		return result;
	}
	void StopDataInLog()
	{
		InvokeHelper(0x3c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL StartMsgLog(LPCTSTR msgLogFile)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x3d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, msgLogFile);
		return result;
	}
	void StopMsgLog()
	{
		InvokeHelper(0x3e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	short SendWaitRFIDEngineDataEx(long id, short len, long * dataBuffer, short msWait)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_PI4 VTS_I2 ;
		InvokeHelper(0x3f, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id, len, dataBuffer, msWait);
		return result;
	}
	BOOL SetText(long id, short pos, LPCTSTR txt)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_BSTR ;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, pos, txt);
		return result;
	}
	short GetSerialSvrStatus(short connID)
	{
		short result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_I2, (void*)&result, parms, connID);
		return result;
	}
	long GetCRCValue(long id)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_I4, (void*)&result, parms, id);
		return result;
	}
	BOOL TextEx(long id, short pos, LPCTSTR txt)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_BSTR ;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, pos, txt);
		return result;
	}
	CString GetSourceIPAddr(long id)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, id);
		return result;
	}
	BOOL BinaryToSerial(long id, short * buffer, short length)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I2 ;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, buffer, length);
		return result;
	}
	BOOL RouteDataToHost(long id, LPCTSTR name)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, id, name);
		return result;
	}
	short ConnectToHostServer(LPCTSTR addr, short port, LPCTSTR friendlyName)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_I2 VTS_BSTR ;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_I2, (void*)&result, parms, addr, port, friendlyName);
		return result;
	}
	short RunConnectionFile(LPCTSTR path)
	{
		short result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_I2, (void*)&result, parms, path);
		return result;
	}
	short CallBTDevice(short serverID, LPCTSTR btAddr, short dataType)
	{
		short result;
		static BYTE parms[] = VTS_I2 VTS_BSTR VTS_I2 ;
		InvokeHelper(0x49, DISPATCH_METHOD, VT_I2, (void*)&result, parms, serverID, btAddr, dataType);
		return result;
	}
	short SendRawDataToBTDevice(LPCTSTR btAddr, short * data, short length)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_PI2 VTS_I2 ;
		InvokeHelper(0x4a, DISPATCH_METHOD, VT_I2, (void*)&result, parms, btAddr, data, length);
		return result;
	}
	short SendRawData(short connID, short * data, short length)
	{
		short result;
		static BYTE parms[] = VTS_I2 VTS_PI2 VTS_I2 ;
		InvokeHelper(0x4b, DISPATCH_METHOD, VT_I2, (void*)&result, parms, connID, data, length);
		return result;
	}
	short SendCmdToServer(short connID, LPCTSTR cmdText)
	{
		short result;
		static BYTE parms[] = VTS_I2 VTS_BSTR ;
		InvokeHelper(0x4c, DISPATCH_METHOD, VT_I2, (void*)&result, parms, connID, cmdText);
		return result;
	}
	BOOL SendSSMASCIIData(long ssmID, short msgNum, LPCTSTR dataString, short retries)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_BSTR VTS_I2 ;
		InvokeHelper(0x4d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ssmID, msgNum, dataString, retries);
		return result;
	}
	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	short SetRFIDEngineByte(long id, short index, unsigned char dataByte)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_UI1 ;
		InvokeHelper(0x4e, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id, index, dataByte);
		return result;
	}
	unsigned char GetRFIDEngineByte(long id, short index)
	{
		unsigned char result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x4f, DISPATCH_METHOD, VT_UI1, (void*)&result, parms, id, index);
		return result;
	}
	short IsBTDeviceConnected(LPCTSTR btAddr)
	{
		short result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x50, DISPATCH_METHOD, VT_I2, (void*)&result, parms, btAddr);
		return result;
	}
	CString GetBTAddress(short connID)
	{
		CString result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x51, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, connID);
		return result;
	}
	short SendASCIIDataToBTDevice(LPCTSTR btAddr, LPCTSTR asciiData)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x52, DISPATCH_METHOD, VT_I2, (void*)&result, parms, btAddr, asciiData);
		return result;
	}
	short SendFileToBTDevice(LPCTSTR btAddr, LPCTSTR fileName)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x53, DISPATCH_METHOD, VT_I2, (void*)&result, parms, btAddr, fileName);
		return result;
	}
	short SetParameter(long id, LPCTSTR pwd, LPCTSTR addr, LPCTSTR data)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x54, DISPATCH_METHOD, VT_I2, (void*)&result, parms, id, pwd, addr, data);
		return result;
	}
	void OpenBSConnections()
	{
		InvokeHelper(0x55, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


};
