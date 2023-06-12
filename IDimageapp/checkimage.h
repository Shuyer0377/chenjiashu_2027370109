#pragma once
#include "afxdialogex.h"


// checkimage 对话框

class checkimage : public CDialogEx
{
	DECLARE_DYNAMIC(checkimage)

public:
	checkimage(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~checkimage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IDIMAGEAPP_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
