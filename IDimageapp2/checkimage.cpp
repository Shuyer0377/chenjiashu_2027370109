// checkimage.cpp: 实现文件
//

#include "pch.h"
#include "IDimageapp.h"
#include "afxdialogex.h"
#include "checkimage.h"


// checkimage 对话框

IMPLEMENT_DYNAMIC(checkimage, CDialogEx)

checkimage::checkimage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IDIMAGEAPP_DIALOG, pParent)
{

}

checkimage::~checkimage()
{
}

void checkimage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(checkimage, CDialogEx)
END_MESSAGE_MAP()


// checkimage 消息处理程序
