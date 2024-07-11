#include "CBigVideoWidget.h"


CBigVideoWidget::CBigVideoWidget(QWidget* p)
	:QWidget(p)
{
	this->setMinimumSize(800, 600);

	setAttribute(Qt::WA_StyledBackground);
	setAttribute(Qt::WA_OpaquePaintEvent);

	setStyleSheet("background-color:rgb(100,210,130)");
}

CBigVideoWidget::~CBigVideoWidget()
{

}

HWND CBigVideoWidget::getHwnd() const
{
	return (HWND)(this->winId());
}
