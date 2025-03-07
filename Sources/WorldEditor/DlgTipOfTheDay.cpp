/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

// DlgTipOfTheDay.cpp : implementation file
//

#include "stdafx.h"
#include "WorldEditor.h"
#include "DlgTipOfTheDay.h"
#include "CtlTipOfTheDayText.h"

#ifdef _DEBUG
#undef new
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgTipOfTheDay dialog


CDlgTipOfTheDay::CDlgTipOfTheDay(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTipOfTheDay::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgTipOfTheDay)
	m_bShowTipsAtStartup = FALSE;
	//}}AFX_DATA_INIT
  m_bShowTipsAtStartup = theApp.m_bShowTipOfTheDay;

  try {
    CTFileStream strm;
    strm.Open_t(CTString("Data\\SED_TipOfTheDay.txt"));
    while (!strm.AtEOF()) {
      strm.GetLine_t(m_astrTips.Push(), '$');
    }
  } catch (char *strError) {
    WarningMessage("Cannot show Tip of the Day:\n%s", strError);
  }
}


void CDlgTipOfTheDay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

  INDEX ctTips = m_astrTips.Count();
  if (ctTips>0) {
    theApp.m_iCurrentTipOfTheDay = (theApp.m_iCurrentTipOfTheDay+ctTips)%ctTips;
    m_wndTipText.m_strTipText = (const char*)m_astrTips[theApp.m_iCurrentTipOfTheDay];
  } else {
    m_wndTipText.m_strTipText = "error";
  }

	//{{AFX_DATA_MAP(CDlgTipOfTheDay)
	DDX_Control(pDX, IDC_TIPTEXT, m_wndTipText);
	DDX_Check(pDX, IDC_SHOWTIPSATSTARTUP, m_bShowTipsAtStartup);
	//}}AFX_DATA_MAP

  theApp.m_bShowTipOfTheDay = m_bShowTipsAtStartup;
}


BEGIN_MESSAGE_MAP(CDlgTipOfTheDay, CDialog)
	//{{AFX_MSG_MAP(CDlgTipOfTheDay)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_NEXTTIP, OnNextTip)
	ON_BN_CLICKED(IDC_PREVTIP, OnPrevTip)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgTipOfTheDay message handlers

void CDlgTipOfTheDay::OnCancel() 
{
	CDlgTipOfTheDay::OnOK();
}

void CDlgTipOfTheDay::OnClose() 
{
	CDlgTipOfTheDay::OnOK();
}
void CDlgTipOfTheDay::OnOK()
{
  theApp.m_iCurrentTipOfTheDay++;
	CDialog::OnOK();
}

void CDlgTipOfTheDay::OnNextTip() 
{
  theApp.m_iCurrentTipOfTheDay++;
  Invalidate(FALSE);
  UpdateData();
}

void CDlgTipOfTheDay::OnPrevTip() 
{
  theApp.m_iCurrentTipOfTheDay--;
  Invalidate(FALSE);
  UpdateData();
}
