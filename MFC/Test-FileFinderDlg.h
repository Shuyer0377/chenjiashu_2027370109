
// Test-FileFinderDlg.h: 头文件
//

#pragma once
#include<string>
#include <vector>

// CTestFileFinderDlg 对话框
class CTestFileFinderDlg : public CDialogEx
{
// 构造
public:
	CTestFileFinderDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTFILEFINDER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持



private:
	void DoSearchFiles(const std::string& path);
	std::vector<std::string>_filenames;




// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void m_list(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton1();
	CListCtrl m_list;
	afx_msg void OnBnClickedButton3();
};
