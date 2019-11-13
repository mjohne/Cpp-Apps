// GrafMathDlg.h : header file
//

#if !defined(AFX_GRAFMATHDLG_H__CE305929_7A0D_432F_A4EE_6E234666BB91__INCLUDED_)
#define AFX_GRAFMATHDLG_H__CE305929_7A0D_432F_A4EE_6E234666BB91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CGrafMathDlg dialog

class CGrafMathDlg : public CDialog
{
// Construction
public:
	CGrafMathDlg(CWnd* pParent = NULL);	// standard constructor
	bool m_bFirstTime;
	float m_fDistanceSize;
	float m_fZahlFaktor;
	float m_fSizeFaktor;
	void DrawSection(CPoint cpFenstLeft,CPoint cpFenstRight, CClientDC& myDC, float nSizeFaktor);
	void DrawCanvas();
	void DrawFunction();
	float YFunc2Y(float y);
	float Y2YFunc(float y);
	float X2XFunc(float x);
	float XFunc2X(float x);
	float GetYofFunction(float x);
	CPoint m_cpRightFenst;
	CPoint m_cpLeftFenst;

// Dialog Data
	//{{AFX_DATA(CGrafMathDlg)
	enum { IDD = IDD_GRAFMATH_DIALOG };
	CXPStyleButtonST m_btnAnsichtSpeichern;
	CXPStyleButtonST m_btnAnsichtLaden;
	CXPStyleButtonST m_btnHochtiefpunkt;
	CXPStyleButtonST m_btnFunktionseingabe;
	CXPStyleButtonST m_btnAxisOptions;
	CXPStyleButtonST m_btnGetXYRange;
	CXPStyleButtonST m_btnZoomOutXYAchse;
	CXPStyleButtonST m_btnZoomOutYAchse;
	CXPStyleButtonST m_btnZoomOutXAchse;
	CXPStyleButtonST m_btnZoomInXYAchse;
	CXPStyleButtonST m_btnZoomInYAchse;
	CXPStyleButtonST m_btnZoomInXAchse;
	CXPStyleButtonST m_btnSchnittpunktYAchse;
	CXPStyleButtonST m_btnSchnittpunktXAchse;
	CXPStyleButtonST m_btnTangente;
	CXPStyleButtonST m_btnSteigung;
	CXPStyleButtonST m_btnAbleitung;
	CXPStyleButtonST m_btnWendepunkt;
	CXPStyleButtonST m_btnGraphZeichnen;
  CThemeHelperST m_ThemeHelper;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrafMathDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

private:
	void DerivateAll();
	int m_nHelpAxisWidth;
	int m_nDecimalPlaces;
	BOOL m_bAxisDescription;
	int m_nAxisDivision;
	CArray<float,float> m_arrFunction,m_arrFunction2,m_arrDerivatedFunction[10];
	CStatic	m_staticCanvas;
  CRect m_rctCanvasFormat;
	int m_nYCorr;
	int m_nXCorr;
	float m_fYValueMax;
	float m_fYValueMin;
	float m_fXValueMax;
	float m_fXValueMin;
	float m_fXFunc;
	float m_fYFunc;
	CStatusBar m_StatusBar;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGrafMathDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonParseAndDraw();
	afx_msg void OnButtonWendepunkt();
	afx_msg void OnButtonAbleitung();
	afx_msg void OnButtonTangente();
	afx_msg void OnButtonSteigung();
	afx_msg void OnButtonSchnittpunktXachse();
	afx_msg void OnButtonSchnittpunktYachse();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonZoomoutXyachse();
	afx_msg void OnButtonZoominXyachse();
	afx_msg void OnButtonZoomoutYachse();
	afx_msg void OnButtonZoominYachse();
	afx_msg void OnButtonZoomoutXachse();
	afx_msg void OnButtonZoominXachse();
	afx_msg void OnButtonGetXYRange();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnAboutbox();
	afx_msg void OnMnuAppHilfe();
	afx_msg void OnMnuMiscAbleitungen();
	afx_msg void OnMnuMiscGaussElimination();
	afx_msg void OnMnuMiscTangenteGleichung();
	afx_msg void OnMnuPunktHochtief();
	afx_msg void OnMnuPunktWendestelle();
	afx_msg void OnMnuPunktSchnittstellenXachse();
	afx_msg void OnMnuPunktSchnittstellenYachse();
	afx_msg void OnButtonAxisOptions();
	afx_msg void OnButtonInputFunction();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnMnuMiscSteigung();
	afx_msg void OnMnuFunktionEingeben();
	afx_msg void OnMnuFunktionEingebenUndZeichnen();
	afx_msg void OnMnuFunktionZeichnen();
	afx_msg void OnButtonHochtiefpunkt();
	afx_msg void OnMnuMiscAchsensymmetrie();
	afx_msg void OnMnuAchsenAchsenskalierungZoominXY();
	afx_msg void OnMnuAchsenAchsenskalierungZoomoutXY();
	afx_msg void OnMnuAchsenAnzeigeSkalierung();
	afx_msg void OnMnuAchsenEinstellungen();
	afx_msg void OnButtonViewLoad();
	afx_msg void OnButtonViewSave();
	afx_msg void OnMnuAppAnsichtLaden();
	afx_msg void OnMnuAppAnsichtSpeichern();
	afx_msg void OnMnuMiscWertetabelle();
	afx_msg void OnMnuAppCredits();
	afx_msg void OnMnuMiscAufleitung();
	afx_msg void OnMnuMiscFlaechenberechnung();
	afx_msg void OnMnuMiscMonotonie();
	afx_msg void OnMnuPunktScheitelpunkt();
	afx_msg void OnMnuMiscLaengeZwischen2Punkten();
	afx_msg void OnMnuMiscYausX();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Helper functions
void	EnableThemeDialogTexture(HWND hwndDlg);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAFMATHDLG_H__CE305929_7A0D_432F_A4EE_6E234666BB91__INCLUDED_)
