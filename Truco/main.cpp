#include "pch.h"
#include "afxwin.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "CmyWnd.h"

class CMyApp : public CWinApp
{
public:
	BOOL InitInstance() final;
};

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMyWnd();
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

const CMyApp theApp;