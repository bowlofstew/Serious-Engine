/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

// CtrlEditFloat.cpp : implementation file
//

#include "stdafx.h"
#include "CtrlEditFloat.h"

#ifdef _DEBUG
#undef new
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCtrlEditFloat

CCtrlEditFloat::CCtrlEditFloat()
{
}

CCtrlEditFloat::~CCtrlEditFloat()
{
}

void CCtrlEditFloat::SetDialogPtr( CPropertyComboBar *pDialog)
{
  m_pDialog = pDialog;
}

BEGIN_MESSAGE_MAP(CCtrlEditFloat, CEdit)
	//{{AFX_MSG_MAP(CCtrlEditFloat)
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCtrlEditFloat message handlers

void CCtrlEditFloat::OnChange() 
{
}

BOOL CCtrlEditFloat::PreTranslateMessage(MSG* pMsg) 
{
	// if we caught key down message
  if( pMsg->message==WM_KEYDOWN)
  {
    if((int)pMsg->wParam==VK_RETURN)
    {
      // don't do anything if document doesn't exist
      if( theApp.GetDocument() == NULL) return TRUE;
      // mark that document is changed
      theApp.GetDocument()->SetModifiedFlag( TRUE);
      theApp.GetDocument()->m_chSelections.MarkChanged();
      // update dialog data (to reflect data change)
	    m_pDialog->UpdateData( TRUE);
      // obtain document ptr
      CWorldEditorDoc *pDoc = theApp.GetDocument();
      // update all views
      pDoc->UpdateAllViews( NULL);
    } else {
      TranslateMessage(pMsg);
      SendMessage( WM_KEYDOWN, pMsg->wParam, pMsg->lParam);
    }

    return TRUE;
  }

  return CEdit::PreTranslateMessage(pMsg);
}
