#pragma once
#include <QObject>
#include <QWidget>
#include "CFrameLessWidgetBase.h"
#include "CTitleBar.h"
#include "CLeftVideoList.h"
#include "CBigVideoWidget.h"
#include "CBottomBar.h"
#include "CAgoraObject.h"

class CMainWidget : public CFrameLessWidgetBase
{
	Q_OBJECT

public:
	CMainWidget(QWidget *p = nullptr);
	~CMainWidget();

	void joinRoom(const QString& roomId);
	
private:
	void initUI();
	void resizeEvent(QResizeEvent* event) override;

private slots:
	void onLocalJoinedSuccess(const QString& qsChannel, unsigned int uid, int elapsed);
	void onRemoteJoined(uid_t uid, int elapsed);
	void onClose();
	void onShareScreen();
	void onEndMeeting();
	void startShareScreen(int type, void* hwnd);

private:
	CTitleBar* m_pTitleBar = nullptr;
	CLeftVideoList* m_pLeftVideoList = nullptr;
	CBigVideoWidget* m_pBigVideoWidget = nullptr;
	CBottomBar* m_pBottomBar = nullptr;

	CAgoraObject* m_pAgora = nullptr;
};

