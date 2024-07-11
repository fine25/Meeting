#include "CCustomToolButton.h"
#include <QEvent>

CCustomToolButton::CCustomToolButton(QString text, QString normalImageUrl, QString normalImageHoverUrl,
	QString clickedImageUrl, QString clickedImageHoverUrl, bool clicked, QWidget* parent)
	: m_text(text),
	m_normalImageUrl(normalImageUrl),
	m_normalImageHoverUrl(normalImageHoverUrl),
	m_clickedImageUrl(clickedImageUrl),
	m_clickedImageHoverUrl(clickedImageHoverUrl),
	m_StateOpen(clicked),
	QToolButton(parent)
{
	this->setFixedSize(CTRL_TOOLBUTTON_HEIGHT, CTRL_TOOLBUTTON_HEIGHT);
	this->setIconSize(QSize(CTRL_TOOLBUTTON_ICON_HEIGHT, CTRL_TOOLBUTTON_ICON_HEIGHT));
	this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	this->setStyleSheet("border:none;font-size:14px;padding-top:3px;padding-bottom:3px;");  //���������С����ֹ�ĸ����ֳ���ʡ�Ժ�
	this->setIcon(QIcon(m_StateOpen ? m_normalImageUrl : m_clickedImageUrl));
	this->setText(text);
}

CCustomToolButton::~CCustomToolButton()
{
}

bool CCustomToolButton::event(QEvent* e)
{
	if (this->isChecked())
		return QWidget::event(e);

	switch (e->type())
	{
	case QEvent::Enter:  //�������¼�
	{
		this->setIcon(QIcon(m_StateOpen ? m_normalImageHoverUrl : m_clickedImageHoverUrl));
		return true;
	}

	case QEvent::MouseButtonPress:  //��������¼�
	{
		m_StateOpen = !m_StateOpen;
		this->setIcon(QIcon(m_StateOpen ? m_normalImageUrl : m_clickedImageUrl));
		this->setChecked(true);
		emit sig_clicked();        //���͵���źţ���Ȼ�޷�����
		return true;
	}

	case QEvent::Leave:            //����뿪�¼�
	{
		this->setIcon(QIcon(m_StateOpen ? m_normalImageUrl : m_clickedImageUrl));
		return true;
	}

	default:
		break;
	}

	return QWidget::event(e);
}