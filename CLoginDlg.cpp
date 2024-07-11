#include "CLoginDlg.h"
#include <QMouseEvent>

CLoginDlg::CLoginDlg(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    ui.lineEdit_roomId->setText("666");

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);

    ui.widget_left->setFixedWidth(500);
    ui.widget_right->setStyleSheet("background-image:url(:/CLoginDlg/resources/login/right_image.png);");
    ui.widget_right->setFixedSize(540, 840);
    ui.btnMin->setText("");
    ui.btnMin->setFixedSize(32, 32);
    ui.btnMin->setStyleSheet("QPushButton{background-image:url(:/CLoginDlg/resources/login/min.svg);border:none}" \
        "QPushButton:hover{" \
        "background-color:rgb(99, 99, 99);" \
        "background-image:url(:/CLoginDlg/resources/login/min_hover.svg);border:none;}");

    ui.btnClose->setText("");
    ui.btnClose->setFixedSize(32, 32);
    ui.btnClose->setStyleSheet("QPushButton{background-image:url(:/CLoginDlg/resources/login/close.svg);border:none}" \
        "QPushButton:hover{" \
        "background-color:rgb(99, 99, 99);" \
        "background-image:url(:/CLoginDlg/resources/login/close_hover.svg);border:none;}");

    ui.btnNetStatus->setText("");
    ui.btnNetStatus->setFixedSize(32, 32);
    ui.btnNetStatus->setStyleSheet("QPushButton{background-color:rgb(0, 255, 0);background-repeat: no-repeat;background-position:center;background-image:url(:/CLoginDlg/resources/login/login_netstatus);border:none}");

    ui.btnSet->setText("");
    ui.btnSet->setFixedSize(32, 32);
    ui.btnSet->setStyleSheet("QPushButton{background-repeat: no-repeat;background-position:center;background-image:url(:/CLoginDlg/resources/login/login_set);border:none}");

    ui.label_logo->setText("");
    ui.label_logo->setFixedSize(40, 40);
    ui.label_logo->setStyleSheet("QLabel{background-repeat: no-repeat;background-position:center;background-image:url(:/CLoginDlg/resources/login/logo);border:none}");

    ui.label_name->setText("HelloMeeting");
    ui.label_name->setStyleSheet("font-size:24px");

    ui.lineEdit_roomId->setFixedHeight(50);
    ui.lineEdit_pwd->setFixedHeight(50);
    ui.lineEdit_userName->setFixedHeight(50);

    ui.btnJoin->setFixedHeight(50);
}

CLoginDlg::~CLoginDlg()
{
}

QString CLoginDlg::getRoomId() const
{
    return ui.lineEdit_roomId->text();
}

void CLoginDlg::on_btnJoin_clicked()
{
    QString roomId = ui.lineEdit_roomId->text();
    if (roomId.isEmpty())
        return;

    accept();
}

void CLoginDlg::mousePressEvent(QMouseEvent* event)
{
    mouse_pos = event->globalPos();
    window_pos = this->pos();
    diff_pos = mouse_pos - window_pos;
}

void CLoginDlg::mouseMoveEvent(QMouseEvent* event)
{
    QPoint pos = event->globalPos();
    //this->move(pos);
    this->move(pos - diff_pos);
}

void CLoginDlg::on_btnClose_clicked()
{
    close();
}
