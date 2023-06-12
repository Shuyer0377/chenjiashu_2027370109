// CUITestDlg.cpp: 实现文件
//

#include "pch.h"
#include "IDimageapp.h"
#include "afxdialogex.h"
#include "CUITestDlg.h"


// CUITestDlg 对话框

IMPLEMENT_DYNAMIC(CUITestDlg, CDialogEx)

CUITestDlg::CUITestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDC_BUTTON_DLOG_SETTING, pParent)
{

}

CUITestDlg::~CUITestDlg()
{
}

void CUITestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUITestDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_SETTING, &CUITestDlg::OnBnClickedButtonOpenSetting)
END_MESSAGE_MAP()


// CUITestDlg 消息处理程序


void CUITestDlg::OnBnClickedButtonOpenSetting()
{
	// TODO: 在此添加控件通知处理程序代码
	
	
}
CString strSourceDir;

CEdit* pEditSourceFileDir = (CEdit*)GetDlgItem(IDC_EDIT_FILE_DIR);
if (pEditSourceFileDir)
{
	pEditSourceFileDir->GetWindowText(strSourceDir);
}

CEdit* pEditSourceFileDir = (CEdit*)GetDlgItem(IDC_EDIT_FILE_DIR);
if (pEditSourceFileDir)
{
	pEditSourceFileDir->SetWindowText(szBuffer);
}