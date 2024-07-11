#pragma once
#include <QWidget>
#include "CCustomToolButton.h"
#include <QPushButton>

class CBottomBar : public QWidget
{
	Q_OBJECT

public:
	CBottomBar(QWidget* p = nullptr);
	~CBottomBar();

signals:
	void sig_shareScreen();
	void sig_endMeeting();
	
private:
	CCustomToolButton* m_pAudioToolButton;
	CCustomToolButton* m_pCameraToolButton;
	CCustomToolButton* m_pShareScreenToolButton;
	CCustomToolButton* m_pSecurityToolButton;
	CCustomToolButton* m_pInvitationToolButton;
	CCustomToolButton* m_pManageMemberToolButton;
	CCustomToolButton* m_pChatToolButton;
	CCustomToolButton* m_pRecordToolButton;
	CCustomToolButton* m_pGroupDiscussionToolButton;
	CCustomToolButton* m_pApplicationToolButton;
	CCustomToolButton* m_pSetToolButton;
	QPushButton* m_pFullScreenButton;
	QPushButton* m_pEndMeetingButton;
};
