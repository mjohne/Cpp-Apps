// CXI-CompressorDlg.h : Headerdatei
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

class CCXICompressorDlgAutoProxy;


// CCXICompressorDlg Dialogfeld
class CCXICompressorDlg : public CDialog
{
	DECLARE_DYNAMIC(CCXICompressorDlg);
	friend class CCXICompressorDlgAutoProxy;

// Konstruktion
public:
	CCXICompressorDlg(CWnd* pParent = NULL);	// Standardkonstruktor
	virtual ~CCXICompressorDlg();

// Dialogfelddaten
	enum { IDD = IDD_CXICOMPRESSOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	CCXICompressorDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
  CString m_strInputfileName;
  CString m_strOutputfileName;
  afx_msg void OnBnClickedButtonChooseInputfile();
  afx_msg void OnBnClickedButtonChooseOutputfile();
  afx_msg void OnBnClickedButtonCompress();
  afx_msg void OnCbnSelchangeComboIntsize();
  CComboBox m_cmbIntSize;
  CString m_strStatusMessage;
  CString m_strProgressInPercent;
  CProgressCtrl m_prgsProgress;
};
