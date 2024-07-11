#include "CMainWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include "CSmallVideoWidget.h"
#include "ShareScreenDialog.h"

CMainWidget::CMainWidget(QWidget* p)
	:CFrameLessWidgetBase(p)
{
	initUI();

	m_pAgora = new CAgoraObject();

	if (0 != m_pAgora->init())
	{
		QMessageBox::information(this, u8"提示", u8"agora init failed");
		exit(EXIT_FAILURE);
	}

	connect(m_pAgora, &CAgoraObject::sender_joinedChannelSuccess, 
		this, &CMainWidget::onLocalJoinedSuccess);

	connect(m_pAgora, &CAgoraObject::sender_userJoined, 
		this, &CMainWidget::onRemoteJoined);
}

CMainWidget::~CMainWidget()
{
	if (m_pAgora)
	{
		delete m_pAgora;
		m_pAgora = nullptr;
	}
}

void CMainWidget::joinRoom(const QString& roomId)
{
	m_pAgora->joinChannel(roomId, 123002);
}

void CMainWidget::initUI()
{
	m_pTitleBar = new CTitleBar(this);
	m_pLeftVideoList = new CLeftVideoList(this);
	m_pBigVideoWidget = new CBigVideoWidget(this);
	m_pBottomBar = new CBottomBar(this);

	QVBoxLayout* mainVLay = new QVBoxLayout(this);
	mainVLay->setSpacing(0);
	mainVLay->addWidget(m_pTitleBar);

	QHBoxLayout* pHLay = new QHBoxLayout(this);
	pHLay->addWidget(m_pLeftVideoList);

	QVBoxLayout* pVlay = new QVBoxLayout;
	pVlay->addWidget(m_pBigVideoWidget);
	pVlay->addWidget(m_pBottomBar);

	pHLay->addLayout(pVlay);
	mainVLay->addLayout(pHLay);
	
	mainVLay->setContentsMargins(0, 0, 0, 0);

	connect(m_pTitleBar, &CTitleBar::sig_close, this, &CMainWidget::onClose);
	connect(m_pBottomBar, &CBottomBar::sig_shareScreen, this, &CMainWidget::onShareScreen);
	connect(m_pBottomBar, &CBottomBar::sig_endMeeting, this, &CMainWidget::onEndMeeting);
}

void CMainWidget::resizeEvent(QResizeEvent* event)
{
	int w = this->width();
	int h = this->height();
	int screen_w = 1920;
	int screen_h = 1080;

	if(!this->isMaximized())
		this->move((1920 - w) / 2, (1080 - h) / 2);
}

// 本地加入房间
void CMainWidget::onLocalJoinedSuccess(const QString& qsChannel, unsigned int uid, int elapsed)
{
	m_pAgora->LocalVideoPreview(m_pBigVideoWidget->getHwnd(), true);
}

// 远程用户加入房间
void CMainWidget::onRemoteJoined(uid_t uid, int elapsed)
{
	CSmallVideoWidget* pSmall = new CSmallVideoWidget();
	m_pLeftVideoList->addVideoWidget(pSmall);

	m_pAgora->RemoteVideoRender(uid, (HWND)(pSmall->winId()));
}

void CMainWidget::onClose()
{
	close();
}

void CMainWidget::onShareScreen()
{
	VecWindowShareInfo vecWindowShare;
	m_pAgora->shareScreen(vecWindowShare);

	ShareScreenDialog* share = new ShareScreenDialog(this);
	share->initListWidget(vecWindowShare);

	connect(share, &ShareScreenDialog::sig_StartShare, this, &CMainWidget::startShareScreen);

	share->exec();
}

void CMainWidget::startShareScreen(int type, void* hwnd)
{
	if (0 != m_pAgora->start_share_screen(type, hwnd))
	{
		QMessageBox::information(this, u8"提示", u8"共享屏幕失败");
	}
}

void CMainWidget::onEndMeeting()
{
	// 其它操作
	close();
}
