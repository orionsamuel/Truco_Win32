
// MFCApplication4.h : main header file for the MFCApplication4 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCApplication4App:
// See MFCApplication4.cpp for the implementation of this class
//

class CMFCApplication4App : public CWinApp
{
public:
	CMFCApplication4App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication4App theApp;
