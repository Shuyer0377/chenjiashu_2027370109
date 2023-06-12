#pragma once
#include "afxdialogex.h"


// CUITestDlg 对话框

class CUITestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUITestDlg)

public:
	CUITestDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CUITestDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDC_BUTTON_DLOG_SETTING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOpenSetting();
};
