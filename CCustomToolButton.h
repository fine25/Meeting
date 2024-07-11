/*

�Զ���toolbutton

�ı�
������ͼ��
��������ʱ��ͼ��
�����Ĺر�ͼ��
�����Ĺر�ͼ�������

*/


#pragma once

#include <QToolButton>
#include "commons.h"

class CCustomToolButton : public QToolButton
{
	Q_OBJECT

public:
	CCustomToolButton(QString text, QString normalImageUrl, QString normalImageHoverUrl,
		QString clickedImageUrl, QString clickedImageHoverUrl, bool clicked, QWidget* parent = nullptr);

	~CCustomToolButton();

	bool event(QEvent* e) override;

	void setOpen(bool open)
	{
		m_StateOpen = open;
	}

signals:
	void sig_clicked();

private:
	QString m_text;
	QString m_normalImageUrl;
	QString m_normalImageHoverUrl;
	QString m_clickedImageUrl;
	QString m_clickedImageHoverUrl;

	//�ò��������ж�״̬�Ƿ��£���������������ͷ��¼����Щ��ť�Ŀ����͹ر�������ͼƬ��
	//���졢���õȰ�ť�Ĵ򿪺͹ر���ͬһ��ͼƬ
	//������Ϊtrue, �ر���Ϊfalse
	bool    m_StateOpen = false;
};
