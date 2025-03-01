/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

// DlgEditFloat.cpp : implementation file
//

#include "stdafx.h"
#include "WorldEditor.h"
#include "DlgEditFloat.h"

#ifdef _DEBUG
#undef new
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgEditFloat dialog


CDlgEditFloat::CDlgEditFloat(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEditFloat::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgEditFloat)
	m_fEditFloat = 0.0f;
	m_strVarName = _T("");
	//}}AFX_DATA_INIT
  m_strTitle="Type new value";
}


void CDlgEditFloat::DoDataExchange(CDataExchange* pDX)
{
  // if dialog is receiving data
  if( pDX->m_bSaveAndValidate == FALSE)
  {
    if( IsWindow(m_hWnd)) 
    {
      SetWindowText(CString(m_strTitle));
    }
  }

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgEditFloat)
	DDX_Text(pDX, IDC_EDIT_FLOAT, m_fEditFloat);
	DDX_Text(pDX, IDC_EDIT_FLOAT_T, m_strVarName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgEditFloat, CDialog)
	//{{AFX_MSG_MAP(CDlgEditFloat)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgEditFloat message handlers
