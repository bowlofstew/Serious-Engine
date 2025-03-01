/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

// DlgPgPrimitive.h : header file
//
#ifndef DLGPGPRIMITIVE_H
#define DLGPGPRIMITIVE_H 1

/////////////////////////////////////////////////////////////////////////////
// CDlgPgPrimitive dialog

class CDlgPgPrimitive : public CPropertyPage
{
	DECLARE_DYNCREATE(CDlgPgPrimitive)

// Construction
public:
  CDlgPgPrimitive();
	~CDlgPgPrimitive();
  BOOL OnIdle(LONG lCount);
  void ApplySCGChange();
  
  COLOR m_colLastSectorColor;
  COLOR m_colLastPolygonColor;
// Dialog Data
	//{{AFX_DATA(CDlgPgPrimitive)
	enum { IDD = IDD_PG_PRIMITIVE };
	CPrimitiveHistoryCombo m_comboPrimitiveHistory;
	CComboBox	m_comboTopShape;
	CComboBox	m_comboBottomShape;
	CColoredButton	m_SectorColor;
	CColoredButton	m_PolygonColor;
	float	m_fHeight;
	float	m_fLenght;
	float	m_fWidth;
	float	m_fEdit1;
	float	m_fEdit2;
	float	m_fEdit3;
	float	m_fEdit4;
	float	m_fEdit5;
	BOOL	m_bIfRoom;
	BOOL	m_bIfSpiral;
	BOOL	m_bIfOuter;
	CString	m_strDisplacePicture;
	BOOL	m_bAutoCreateMipBrushes;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDlgPgPrimitive)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgPgPrimitive)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeBottomShape();
	afx_msg void OnSelchangeTopShape();
	afx_msg void OnIfRoom();
	afx_msg void OnIfSpiral();
	afx_msg void OnIfOuter();
	afx_msg void OnSelchangePrimitiveHistory();
	afx_msg void OnDropdownPrimitiveHistory();
	afx_msg void OnDisplaceBrowse();
	afx_msg void OnDisplaceNone();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnLoadPrimitiveSettings();
	afx_msg void OnSavePrimitiveSettings();
	afx_msg void OnSaveAsPrimitiveSettings();
	afx_msg void OnResetPrimitive();
	afx_msg void OnDropdownTopShape();
	afx_msg void OnDropdownBottomShape();
	afx_msg void OnAutoCreateMipBrushes();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
#endif // DLGPGPRIMITIVE_H
