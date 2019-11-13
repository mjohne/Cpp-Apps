////////////////////////////////////////////////////////////////////////////////////
//
//	Purpose: simple help dialog that can display a RTF file
//	 Author: Antoine Megens (antoine.megens@salland.com)
//
//	11 Jun 2001 - Posted on the Code Project site http://www.codeproject.com
//	03 Oct 2001	- Fixed bug in RTF Callback (thanks to Andre Stoelwinder)
//
////////////////////////////////////////////////////////////////////////////////////
//
// HelpDialog.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "HelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
// RTF edit control StreamIn's callback function
//    - see CRichEditCtrl::StreamIn
//
static DWORD CALLBACK _LoadRtfCallback(
		DWORD dwCookie,      // (in) pointer to the string
		LPBYTE pbBuff,       // (in) pointer to the destination buffer
		LONG cb,             // (in) size in bytes of the destination buffer
		LONG FAR *pcb        // (out) number of bytes transfered
		)
{
	
	CString *pstr = (CString *)dwCookie;

	if( pstr->GetLength() < cb )
	{
		*pcb = pstr->GetLength();
		memcpy(pbBuff, (LPCSTR)*pstr, *pcb );
		pstr->Empty();
	}
	else
	{
		*pcb = cb;
		memcpy(pbBuff, (LPCSTR)*pstr, *pcb );
		*pstr = pstr->Right( pstr->GetLength() - cb );
	}
	return 0;
}

static BOOL _LoadStringEx( UINT nResId, LPCTSTR pszRsType, CString& strOut )
{
	LPTSTR pszResId = MAKEINTRESOURCE(nResId);
	HINSTANCE hInst = ::AfxFindResourceHandle( pszResId, pszRsType );

	if( hInst == NULL )
	  return FALSE;

	HRSRC hRsrc = ::FindResource( hInst, pszResId, pszRsType );

	if( hRsrc == NULL )
	  return FALSE;

	HGLOBAL hGlobal = ::LoadResource( hInst, hRsrc );

	if (hGlobal == NULL)
		return FALSE;

	const BYTE* pData = (const BYTE*)::LockResource( hGlobal );
	DWORD dwSize = ::SizeofResource( hInst, hRsrc );

	if( pData == NULL )
	  return FALSE;

	CString str( (LPCTSTR)pData, dwSize );
	strOut = str;

	::UnlockResource( hGlobal );
	::FreeResource( hGlobal );

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CHelpDialog dialog


CHelpDialog::CHelpDialog(CWnd* pParent /*=NULL*/, UINT RtfId)
	: CDialog(CHelpDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHelpDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDI_HELP_ICON);
	m_ID = RtfId;
	m_strTitle = _T("Help");	// default title
	m_bOnTop = TRUE;			// default topmost window
	m_bFileLoaded = FALSE;		// default no RTF file loaded
}


void CHelpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHelpDialog)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHelpDialog, CDialog)
	//{{AFX_MSG_MAP(CHelpDialog)
	ON_WM_SIZING()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_POPUP_HELP_PRINT, OnPopupHelpPrint)
	ON_COMMAND(ID_FILE_KEEPHELPONTOP_ONTOP, OnFileKeephelpontopOntop)
	ON_COMMAND(ID_FILE_KEEPHELPONTOP_NOTONTOP, OnFileKeephelpontopNotontop)
	ON_WM_INITMENUPOPUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelpDialog message handlers

BOOL CHelpDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Set the icon for the Help dialog.

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CRect rcDummy; // dimension doesn't matter here

	// create the RTF control
	m_RichEdit.Create( WS_CHILD|WS_VISIBLE|ES_LEFT|ES_MULTILINE|ES_READONLY|WS_HSCROLL|WS_VSCROLL|WS_TABSTOP,
				       rcDummy, 
					   this, 
					   (UINT)IDC_STATIC);

	m_RichEdit.SetBackgroundColor(FALSE,GetSysColor(COLOR_INFOBK));
	m_RichEdit.SetOptions(ECOOP_SET,ECO_READONLY | ECO_SAVESEL | ECO_AUTOWORDSELECTION);

	// set the title
	SetWindowText(m_strTitle);

//	TRACE("HelpDialog: ID = %d, File Loaded = %d\r\n",m_ID,m_bFileLoaded);

	// do we have a vaild ID?
	if (!m_ID)
	{
		if (!m_bFileLoaded)
		{
			m_Msg = "{\\rtf1\\ansi\\ansicpg1252\\deff0\\deflang1033{\\fonttbl{\\f0\\fswiss\\fcharset0 Arial;}}"
					"{\\colortbl ;\\red255\\green0\\blue0;}"
					"\\viewkind4\\uc1\\pard\\cf1\\b\\f0\\fs36 HelpDialog Internal Error\\par"
					"\\fs20\\par"
					"\\cf0 no RTF ID set in constructor AND no RTF File Loaded, check your code!\\par"
					"\\cf0\\b0\\par"
					"}";
		}
	}
	else
	{
		if (!_LoadStringEx(m_ID,"RTF",m_Msg))
		{
			m_Msg = "{\\rtf1\\ansi\\ansicpg1252\\deff0\\deflang1033{\\fonttbl{\\f0\\fswiss\\fcharset0 Arial;}}"
					"{\\colortbl ;\\red255\\green0\\blue0;}"
					"\\viewkind4\\uc1\\pard\\cf1\\b\\f0\\fs36 HelpDialog Internal Error\\par"
					"\\fs20\\par"
					"\\cf0 Failed to load RTF from resources, check your code!\\par"
					"\\cf0\\b0\\par"
					"}";
		}
	}
//	TRACE("HelpDialog: %s\r\n",m_Msg);

	// move the RTF to the Rich Edit
	// Note: use of StreamIn is required for WinNT, for Win2K it is allowed to do a SetWindowText.

	EDITSTREAM es;
	es.dwCookie = (DWORD)&m_Msg;
	es.dwError = 0;
	es.pfnCallback = _LoadRtfCallback;

	m_RichEdit.StreamIn( SF_RTF, es );

	/////////////////////////////////////////////////////////
	// Calcule the best Rich Edit control dimension
	m_dimMsg.cx = 0;
	m_dimMsg.cy = 0;

	m_RichEdit.SetEventMask( ENM_REQUESTRESIZE );

	// Performing the binary search for the best dimension

	int cxFirst = 100; // do not go smaller than this
	int cxLast = ::GetSystemMetrics( SM_CXFULLSCREEN ) / 2;
	int cyMin = 0;

	cxLast *= 2;

	do
	{
	  // Taking a guess
	  int cx = ( cxFirst + cxLast ) / 2;

	  // Testing this guess
	  CRect rc( 0, 0, cx, 1 );
	  m_RichEdit.MoveWindow(rc , FALSE);
	  m_RichEdit.SetRect(rc);
	  m_RichEdit.RequestResize();

	  // If it's the first time, take the result anyway.
	  // This is the minimum height the control needs
	  if( cyMin == 0 )
	  {
		  cyMin = m_dimMsg.cy;
	  }

	  // Iterating
	  if( m_dimMsg.cy > cyMin )
	  {
		 // If the control required a larger height, then it's too narrow.
		 cxFirst = cx + 1;
	  }
	  else
	  {
		 // If the control didn't required a larger height, then it's too wide.
		 cxLast = cx - 1;
	  }
	}
	while( cxFirst < cxLast );

	// Giving it a few pixels extra width for safety
	m_dimMsg.cx += 5;
	m_dimMsg.cy += (2 + GetSystemMetrics(SM_CYMENUSIZE));

	// take care not to exceed the screen height
	if (m_dimMsg.cy > ::GetSystemMetrics(SM_CYFULLSCREEN) - 80)
	{
		m_dimMsg.cy = GetSystemMetrics(SM_CYFULLSCREEN) - 80;
	}

	// Set the size of both the RichEdit and the main window
	CRect rc(2,2,m_dimMsg.cx,m_dimMsg.cy);
	m_RichEdit.SetWindowPos(NULL,2,2,m_dimMsg.cx,m_dimMsg.cy,SWP_NOZORDER);
	m_RichEdit.SetRect(rc);

	SetWindowPos(NULL,0,0,m_dimMsg.cx + 14,m_dimMsg.cy + 60,SWP_NOMOVE | SWP_NOZORDER);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CHelpDialog::OnWndMsg( UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult )
{
	if (message == WM_NOTIFY)
	{
		REQRESIZE* prr = (REQRESIZE*)lParam;
		if( prr->nmhdr.code == EN_REQUESTRESIZE )
		{
//			TRACE("prr->rc.top=%d, prr->rc.bottom=%d\n",prr->rc.top,prr->rc.bottom);
//			TRACE("prr->rc.left=%d, prr->rc.right=%d\n",prr->rc.left,prr->rc.right);

			// The rich edit control requested a resize.
			// Store the requested resize.
			m_dimMsg.cx = prr->rc.right - prr->rc.left;
			m_dimMsg.cy = prr->rc.bottom - prr->rc.top;

			*pResult = NULL;
			return TRUE;
		}
	}
	// next code is required on WinNT to get the contextmenu whem clicked in the
	// RichEdit control. On Win2K this code can be commented out...
	if (message == WM_SETCURSOR)
	{
		if (HIWORD(lParam) == WM_RBUTTONDOWN)
		{
  			POINT pt;
  			GetCursorPos(&pt);
			OnContextMenu(this,pt);
		}
	}
	return CDialog::OnWndMsg( message, wParam, lParam, pResult );
}


void CHelpDialog::OnSizing(UINT fwSide, LPRECT pRect) 
{	
	CDialog::OnSizing(fwSide, pRect);

	CRect rcClient;
	GetClientRect(&rcClient);

	rcClient.left += 2;
	rcClient.top += 2;
	rcClient.right -= 1;
	rcClient.bottom -= 1;
	m_RichEdit.MoveWindow(rcClient);
}

void CHelpDialog::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	if (m_RichEdit.GetSafeHwnd())
	{
		CRect rcClient;
		GetClientRect(&rcClient);

		rcClient.left += 2;
		rcClient.top += 2;
		rcClient.right -= 1;
		rcClient.bottom -= 1;
		m_RichEdit.MoveWindow(rcClient);
		m_RichEdit.SetRect(rcClient);
		m_RichEdit.Invalidate();
	}	
}

void CHelpDialog::SetTitle(CString title)
{
	m_strTitle = title;
}

void CHelpDialog::OnContextMenu(CWnd* pWnd, CPoint point) 
{
  	CMenu menu;
  	int pMenuID = 0;
  	DWORD SelectionMade;
  	VERIFY(menu.LoadMenu(IDR_POPUP_HELP_MENU));		// load the menu
  
  	CMenu* pPopup = menu.GetSubMenu(pMenuID);
  	ASSERT(pPopup != NULL);
   
  	POINT pp;
  	GetCursorPos(&pp);

	// check the appropriate On Top command
	int cmd = MF_BYCOMMAND | (m_bOnTop ? MF_CHECKED : MF_UNCHECKED);
	menu.CheckMenuItem(ID_FILE_KEEPHELPONTOP_ONTOP,cmd);
	cmd = MF_BYCOMMAND | (!m_bOnTop ? MF_CHECKED : MF_UNCHECKED);
	menu.CheckMenuItem(ID_FILE_KEEPHELPONTOP_NOTONTOP,cmd);

  	// open the popup, using the TrackPopupMenu function
  	SelectionMade = pPopup->TrackPopupMenu( TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_NONOTIFY | TPM_RETURNCMD,
  											pp.x,pp.y,this);
  
  	pPopup->DestroyMenu();
  
  	//The value of SelectionMade is the id of the command selected
  	//or 0 if no selection was made
 	if (!SelectionMade) return;
 
 	switch(SelectionMade)
 	{
		case ID_EDIT_COPY:
				OnEditCopy();
				break;
		case ID_POPUP_HELP_PRINT:
				PrintTopic();
				break;
		case ID_FILE_KEEPHELPONTOP_ONTOP:
				SetTopMost(TRUE);
				break;
		case ID_FILE_KEEPHELPONTOP_NOTONTOP:
				SetTopMost(FALSE);
				break;
		case IDOK:
				CDialog::OnOK();
				break;
	}
}

void CHelpDialog::PrintTopic()
{
	CPrintDialog printDialog(false);

	bool bShowPrintDialog = TRUE; //set to FALSE when you want direct printing without the PrintDialog
	
	if (bShowPrintDialog)
	{
		int r = printDialog.DoModal();
		if (r == IDCANCEL)
			return; // User pressed cancel, don't print.
	}
	else
	{
		printDialog.GetDefaults();
	}

	HDC hPrinterDC = printDialog.GetPrinterDC();
	HWND hRTFWnd = m_RichEdit.GetSafeHwnd();
		
	// This code basically taken from MS KB article Q129860 
	
	FORMATRANGE fr;
	int		nHorizRes = GetDeviceCaps(hPrinterDC, HORZRES),
			nVertRes = GetDeviceCaps(hPrinterDC, VERTRES),
			nLogPixelsX = GetDeviceCaps(hPrinterDC, LOGPIXELSX),
			nLogPixelsY = GetDeviceCaps(hPrinterDC, LOGPIXELSY);
	LONG	lTextLength;			// Length of document.
	LONG	lTextPrinted;			// Amount of document printed.

	// Ensure the printer DC is in MM_TEXT mode.
	SetMapMode ( hPrinterDC, MM_TEXT );

	// Rendering to the same DC we are measuring.
	ZeroMemory(&fr, sizeof(fr));
	fr.hdc = fr.hdcTarget = hPrinterDC;

	// Set up the page.
	fr.rcPage.left     = fr.rcPage.top = 0;
	fr.rcPage.right    = (nHorizRes/nLogPixelsX) * 1440;
	fr.rcPage.bottom   = (nVertRes/nLogPixelsY) * 1440;

	// Set up 1" margins all around.
	fr.rc.left   = fr.rcPage.left + 1440;  // 1440 TWIPS = 1 inch.
	fr.rc.top    = fr.rcPage.top + 1440;
	fr.rc.right  = fr.rcPage.right - 1440;
	fr.rc.bottom = fr.rcPage.bottom - 1440;

	// Default the range of text to print as the entire document.
	fr.chrg.cpMin = 0;
	fr.chrg.cpMax = -1;

	 // Set up the print job (standard printing stuff here).
		DOCINFO di;
	  ZeroMemory(&di, sizeof(di));
	  di.cbSize = sizeof(DOCINFO);

	di.lpszDocName = "(Help Topic)";

	// Do not print to file.
	di.lpszOutput = NULL;
	     

	// Start the document.
	StartDoc(hPrinterDC, &di);

	// Find out real size of document in characters.
	lTextLength = ::SendMessage ( hRTFWnd, WM_GETTEXTLENGTH, 0, 0 );

	do
	{
		// Start the page.
		StartPage(hPrinterDC);

		// Print as much text as can fit on a page. The return value is
		// the index of the first character on the next page. Using TRUE
		// for the wParam parameter causes the text to be printed.

		#ifdef USE_BANDING

		lTextPrinted = ::SendMessage(hRTFWnd,EM_FORMATRANGE,FALSE,(LPARAM)&fr);
		::SendMessage(hRTFWnd, EM_DISPLAYBAND, 0, (LPARAM)&fr.rc);

		#else

		lTextPrinted = ::SendMessage( hRTFWnd,	EM_FORMATRANGE,TRUE,(LPARAM)&fr);

		#endif

		// Print last page.
		EndPage(hPrinterDC);

		// If there is more text to print, adjust the range of characters
		// to start printing at the first character of the next page.
		if (lTextPrinted < lTextLength)
		{
			fr.chrg.cpMin = lTextPrinted;
			fr.chrg.cpMax = -1;
		}
	}
	while (lTextPrinted < lTextLength);

	// Tell the control to release cached information.
	::SendMessage( hRTFWnd, EM_FORMATRANGE, 0, (LPARAM)NULL);

	EndDoc (hPrinterDC);	  
	DeleteDC(hPrinterDC);
}


void CHelpDialog::OnEditCopy() 
{
	m_RichEdit.SetSel(0,-1);				// select all text
	m_RichEdit.Copy();						// copy it
	m_RichEdit.SetSel(0,0);
}

void CHelpDialog::OnPopupHelpPrint() 
{
	PrintTopic();
}

void CHelpDialog::OnFileKeephelpontopOntop() 
{
	SetTopMost(TRUE);
}

void CHelpDialog::OnFileKeephelpontopNotontop() 
{
	SetTopMost(FALSE);
}

void CHelpDialog::SetTopMost(BOOL value)
{
	m_bOnTop = value;
	if (value)
	{
		SetWindowPos(&CWnd::wndTopMost,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE);
		BringWindowToTop();
	}
	else
	{
		SetWindowPos(&CWnd::wndBottom,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE | SWP_NOACTIVATE);
	}
}

BOOL CHelpDialog::IsTopMost()
{
	return m_bOnTop;
}


BOOL CHelpDialog::LoadRTFFile(CString RTFFileName)
{
	CFile file;

	m_bFileLoaded = FALSE;
	try
	{	
		file.Open(RTFFileName,CFile::modeRead);
		file.Read(m_Msg.GetBufferSetLength(file.GetLength()),file.GetLength());
		file.Close();
	}
	catch(...)
	{
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL 
		);
		// use the error as the Help message
		m_Msg = "{\\rtf1\\ansi\\ansicpg1252\\deff0\\deflang1033{\\fonttbl{\\f0\\fswiss\\fcharset0 Arial;}}"
					"{\\colortbl ;\\red255\\green0\\blue0;}"
					"\\viewkind4\\uc1\\pard\\cf1\\b\\f0\\fs36 HelpDialog Internal Error\\par"
					"\\fs20\\par"
					"\\cf0 Failed to load RTF file '";
		m_Msg += RTFFileName;
		m_Msg += "'\\par\\par\\cf0Reason: ";
		m_Msg += (char *) lpMsgBuf;		
		m_Msg += "\\par\\cf0\\b0\\par}";
		LocalFree( lpMsgBuf );

		// fake that we have loaded an RTF file, so the above message will be displayed
		// if the caller will not handle our FALSE return code
		m_bFileLoaded = TRUE;
		return FALSE;
	}
	m_bFileLoaded = TRUE;
	return TRUE;
}

void CHelpDialog::OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu) 
{
	int cmd = MF_BYCOMMAND | (m_bOnTop ? MF_CHECKED : MF_UNCHECKED);
	pPopupMenu->CheckMenuItem(ID_FILE_KEEPHELPONTOP_ONTOP,cmd);
	cmd = MF_BYCOMMAND | (!m_bOnTop ? MF_CHECKED : MF_UNCHECKED);
	pPopupMenu->CheckMenuItem(ID_FILE_KEEPHELPONTOP_NOTONTOP,cmd);

	CDialog::OnInitMenuPopup(pPopupMenu, nIndex, bSysMenu);	
}
