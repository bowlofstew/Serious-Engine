/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__395D5845_FE79_4FF6_A71C_34C178CB4AE3__INCLUDED_)
#define AFX_STDAFX_H__395D5845_FE79_4FF6_A71C_34C178CB4AE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#include <EngineGUI/EngineGUI.h>
//#include "SeriousSkaStudio.h"
//#include "SeriousSkaStudioDoc.h"

#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")

#endif // !defined(AFX_STDAFX_H__395D5845_FE79_4FF6_A71C_34C178CB4AE3__INCLUDED_)
