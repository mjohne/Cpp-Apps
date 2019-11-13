// WordStatDoc.h : interface of the CWordStatDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORDSTATDOC_H__5DACD6D2_A728_4490_B64D_F9E8B30E5AEA__INCLUDED_)
#define AFX_WORDSTATDOC_H__5DACD6D2_A728_4490_B64D_F9E8B30E5AEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <Afxtempl.h>

struct SWordTable
{
  DWORD WordFrequency;
  BYTE WordLength;
  CString WordString;
};

class CWordStatDoc : public CDocument
{
protected: // create from serialization only
	CWordStatDoc();
	DECLARE_DYNCREATE(CWordStatDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordStatDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	UINT m_uintLimitX;
	CArray<SWordTable,SWordTable> m_WordTable;
  BYTE ProcessState;
  BYTE nWordLenMax;
  LONG Letters;
  LONG Spaces;
  LONG Words;
  LONG KValue[65535];
  LONG WordLen[65535];
  LONG WordFrequency[65535];
  	
  virtual ~CWordStatDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWordStatDoc)
	afx_msg void OnButtonKvalue();
	afx_msg void OnButtonWordlenSequence();
	afx_msg void OnButtonWorddiagLenfreq();
	afx_msg void OnButtonWordlendiagSortfreq();
	afx_msg void OnButtonWordlendiagSortpos();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CWordStatDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDSTATDOC_H__5DACD6D2_A728_4490_B64D_F9E8B30E5AEA__INCLUDED_)
