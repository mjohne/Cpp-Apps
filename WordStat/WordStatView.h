// WordStatView.h : interface of the CWordStatView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORDSTATVIEW_H__CFA482E6_7533_4BAA_A884_9E43E84B719B__INCLUDED_)
#define AFX_WORDSTATVIEW_H__CFA482E6_7533_4BAA_A884_9E43E84B719B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <Afxtempl.h>

class CWordStatView : public CView
{
protected: // create from serialization only
	CWordStatView();
	DECLARE_DYNCREATE(CWordStatView)

// Attributes
public:
	CWordStatDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordStatView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
  CArray<SWordTable,SWordTable> m_WordTable;
	virtual ~CWordStatView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWordStatView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in WordStatView.cpp
inline CWordStatDoc* CWordStatView::GetDocument()
   { return (CWordStatDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDSTATVIEW_H__CFA482E6_7533_4BAA_A884_9E43E84B719B__INCLUDED_)
