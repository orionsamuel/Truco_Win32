#pragma once
class CMyWnd : public CFrameWnd
{
public:
	CMyWnd();
	afx_msg void OnButtonClick();
	DECLARE_MESSAGE_MAP()

private:
	CButton button;
	CEdit editTextfield;
};

