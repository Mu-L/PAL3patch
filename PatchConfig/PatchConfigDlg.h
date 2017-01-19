// PatchConfigDlg.h : header file
//

#if !defined(AFX_PATCHCONFIGDLG_H__2481DBA8_E564_41F7_AC75_E39197235697__INCLUDED_)
#define AFX_PATCHCONFIGDLG_H__2481DBA8_E564_41F7_AC75_E39197235697__INCLUDED_


#include "MouseMsgButton.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPatchConfigDlg dialog

class CPatchConfigDlg : public CDialog
{
// Construction
public:
	CPatchConfigDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPatchConfigDlg)
	enum { IDD = IDD_PATCHCONFIG_DIALOG };
	CMouseMsgButton	m_RadioBtn1;
	CMouseMsgButton	m_RadioBtn2;
	CMouseMsgButton	m_RadioBtn3;
	CMouseMsgButton	m_RadioBtn4;
	CButton	m_ToggleAdvBtn;
	CButton	m_ChooseBtn;
	CTreeCtrl	m_CfgTree;
	CString	m_CfgTitle;
	CString	m_CfgDesc;
	CString	m_CfgVal;
	CString	m_OptDesc;
	int		m_RadioVal;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPatchConfigDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	CFont m_RadioBtnFont[MAX_CONFIGDESC_OPTIONS];
	ConfigDescItem *m_ItemSelected;
	int m_IsAdvMode;
	int m_OptDescShowing;
	std::vector<std::pair<CString, std::pair<CString, CString> > > m_EnumList;

	static void OnMouseMoveCallbackWarpper(void *ptr, int btnid);
	void SetRadioBtnStyle(int btnid, int bold, int underline);
	void BtnMouseMove(int btnid);
	void ToggleAdvMode(bool reset);
	void LoadConfigDescription();
	void SelectConfigItem(ConfigDescItem *pItem);
	void UpdateConfigItem();
	
	// Generated message map functions
	//{{AFX_MSG(CPatchConfigDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnToggleAdvOpts();
	afx_msg void OnSelchangedCfgtree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChoosefromlist();
	afx_msg void OnChangeCfgval();
	afx_msg void OnRadioClicked();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATCHCONFIGDLG_H__2481DBA8_E564_41F7_AC75_E39197235697__INCLUDED_)
