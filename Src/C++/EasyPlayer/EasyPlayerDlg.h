
// EasyPlayerDlg.h : ͷ�ļ�
//

#pragma once

#include "DlgVideo.h"
#include ".\EasySkinUI\skindialog.h"
#define KEY "79393674363469576B5A754144474A636F35337A4A65784659584E3555477868655756794C564A55553141755A58686C567778576F502B6C3430566863336C4559584A33615735555A57467453584E55614756435A584E30514449774D54686C59584E35"


#define	_SURV_MAX_WINDOW_NUM		16
#define MSG_LOG WM_USER +0x1001

typedef struct __VIDEO_NODE_T
{
	bool		fullscreen;
	int			maximizedId;
	int			selectedId;
	int			channels;
	CDlgVideo	*pDlgVideo;
}VIDEO_NODE_T;

static int shownToScale = 0x01;

// CEasyPlayerDlg �Ի���
class CEasyPlayerDlg : public CSkinDialog
{
// ����
public:
	CEasyPlayerDlg(CWnd* pParent = NULL);	// ��׼���캯��


public:
	CComboBox		*pComboxSplitScreen;
	CComboBox		*pComboxRenderFormat;	//IDC_COMBO_RENDER_FORMAT
	VIDEO_NODE_T	*pVideoWindow;		//��Ƶ����
	CSkinButton			pChkShownToScale;	//��������ʾ
	CStatic			*pStaticCopyright;	//IDC_STATIC_COPYRIGHT

	void	InitialComponents();
	void	CreateComponents();
	void	UpdateComponents();
	void	DeleteComponents();
	void	UpdateVideoPosition(LPRECT lpRect);

// �Ի�������
	enum { IDD = IDD_EASYPLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	LRESULT OnWindowMaximized(WPARAM wParam, LPARAM lParam);
	LRESULT OnLog(WPARAM wParam, LPARAM lParam);

private:
	int m_nValidTimes;

public:
	virtual BOOL DestroyWindow();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnCbnSelchangeComboSplitScreen();
	afx_msg void OnCbnSelchangeComboRenderFormat();
	afx_msg void OnBnClickedCheckShowntoscale();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
