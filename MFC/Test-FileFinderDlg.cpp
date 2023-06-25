
// Test-FileFinderDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Test-FileFinder.h"
#include "Test-FileFinderDlg.h"
#include "afxdialogex.h"

#include "string"
#include "vector"
#include "io.h"

#undef UNICODE
#undef _UNICODE

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestFileFinderDlg 对话框



CTestFileFinderDlg::CTestFileFinderDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTFILEFINDER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestFileFinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CTestFileFinderDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CTestFileFinderDlg::OnLvnItemchangedList1)
//	ON_NOTIFY(LVN_GETINFOTIP, IDC_LIST1, &CTestFileFinderDlg::m_list)
ON_BN_CLICKED(IDC_BUTTON1, &CTestFileFinderDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON3, &CTestFileFinderDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CTestFileFinderDlg 消息处理程序

BOOL CTestFileFinderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_list.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_list.InsertColumn(0, _T("文件路径"), LVCFMT_CENTER, rect.Width(), 0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestFileFinderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestFileFinderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTestFileFinderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestFileFinderDlg::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


//void CTestFileFinderDlg::m_list(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	LPNMLVGETINFOTIP pGetInfoTip = reinterpret_cast<LPNMLVGETINFOTIP>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
//	*pResult = 0;
//}


void CTestFileFinderDlg::OnBnClickedButton3()
{
	
}







void CTestFileFinderDlg::DoSearchFiles(const std::string& path)
{
	if (path.length() == 0) {
		return;
	}
	std::string temp(path);
	temp.append("*,*");



	_finddata_t fileinfo;
	long handle = _findfirst(temp.c_str(),  &fileinfo);
	if (handle == -1) {
		return;
	}

	while (!_findnext(handle, &fileinfo))
	{
		if (fileinfo.attrib == _A_SUBDIR) {
			if (strcmp(fileinfo.name, ".") == 0 || strcmp(fileinfo.name, "..") == 0) {
				continue;
			}

		

			std::string temp(path);
			temp.append(fileinfo.name);
			temp.append("\\");


			DoSearchFiles(temp);
		}
		else {
			
			_filenames.push_back(fileinfo.name);
		}
	}
	_findclose(handle);
}



void CTestFileFinderDlg::OnBnClickedButton1()
{
	// dynamic call dll
	HINSTANCE m_hDll = LoadLibrary("MyDll.dll");

	if (NULL == m_hDll)
	{
		MessageBox("Load dll failed!");
		return;
	}
	else
	{
		std::string path;
		path.append("d:\\");
		DoSearchFiles(path);



		std::vector<std::string>::const_iterator itrbegin = _filenames.begin();
		std::vector<std::string>::const_iterator itrend = _filenames.end();

		for (; itrbegin != itrend; itrbegin++) {

			m_list.InsertItem(0, (*itrbegin).c_str());

		}
		FreeLibrary(m_hDll);
	}
}

