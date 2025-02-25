/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

// DlgPreferences.h : header file
//
#ifndef DLGPREFERENCES_H
#define DLGPREFERENCES_H 1

/////////////////////////////////////////////////////////////////////////////
// CDlgPreferences dialog

class CDlgPreferences : public CDialog
{
// Construction
public:
	CDisplayMode m_dmFullScreen;
  GfxAPIType   m_gatFullScreen;

	// constructor
  CDlgPreferences( CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CDlgPreferences)
	enum { IDD = IDD_PREFERENCES };
	CComboBox	m_ctrlTerrainSelectionHidden;
	CComboBox	m_ctrlTerrainSelectionVisible;
	CComboBox	m_ctrGfxApi;
	CSliderCtrl	m_ctrlCSGPrecission;
	CSliderCtrl	m_UndoLevels;
	CButton	m_OkButton;
	BOOL	m_PrefsCopy;
	BOOL	m_AutoMaximize;
	BOOL	m_SetDefaultColors;
	BOOL	m_AutomaticInfo;
	BOOL	m_UpdateAllways;
	BOOL	m_BinaryGrid;
	BOOL	m_bSaveUndoForDelete;
	int		m_iWndStartupCfg;
	BOOL	m_bAutoColorize;
	CString	m_strSSProject;
	BOOL	m_bShowAllOnOpen;
	CString	m_strCSGPrecission;
	BOOL	m_bAutoUpdateDisplaceMap;
	float	m_fFlyModeSpeed;
	BOOL	m_bHideShadowsOnStart;
	BOOL	m_bAutoUpdateTerrainDistribution;
	int		m_iMemoryForTerrainUndo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPreferences)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPreferences)
	virtual BOOL OnInitDialog();
	afx_msg void OnSavePreferences();
	afx_msg void OnLoadPreferences();
	afx_msg void OnChangeFullScreenDisplayMode();
	afx_msg void OnReleasedcaptureCsgPrecission(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
  afx_msg void OnChangePreferences(UINT nID);
	DECLARE_MESSAGE_MAP()
};
#endif // DLGPREFERENCES_H
