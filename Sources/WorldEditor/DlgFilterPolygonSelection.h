/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

#if !defined(AFX_DLGFILTERPOLYGONSELECTION_H__AC59EE33_FCCF_11D3_8409_004095812ACC__INCLUDED_)
#define AFX_DLGFILTERPOLYGONSELECTION_H__AC59EE33_FCCF_11D3_8409_004095812ACC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgFilterPolygonSelection.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgFilterPolygonSelection dialog

class CDlgFilterPolygonSelection : public CDialog
{
// Construction
public:
	CDlgFilterPolygonSelection(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgFilterPolygonSelection)
	enum { IDD = IDD_FILTER_POLYGON_SELECTION };
	CColoredButton	m_ctrlMultiplyColor;
	CComboBox	m_ctrlFilterPolygonMirror;
	CComboBox	m_ctrFilterPolygonSurface;
	CComboBox	m_ctrlClusterMemoryCombo;
	CComboBox	m_ctrlClusterSizeCombo;
	float	m_fMinH;
	float	m_fMinP;
	float	m_fMaxH;
	float	m_fMaxP;
	float	m_fMinX;
	float	m_fMinY;
	float	m_fMinZ;
	float	m_fMaxX;
	float	m_fMaxY;
	float	m_fMaxZ;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgFilterPolygonSelection)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgFilterPolygonSelection)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGFILTERPOLYGONSELECTION_H__AC59EE33_FCCF_11D3_8409_004095812ACC__INCLUDED_)
