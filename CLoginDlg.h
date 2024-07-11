#pragma once

#include <QtWidgets/QDialog>
#include "ui_CLoginDlg.h"

class CLoginDlg : public QDialog
{
    Q_OBJECT

public:
    CLoginDlg(QWidget *parent = nullptr);
    ~CLoginDlg();

    QString getRoomId() const;

private:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
   
private slots:
    void on_btnJoin_clicked();
    void on_btnClose_clicked();


private:
    Ui::CLoginDlgClass ui;

    QPoint diff_pos;  // ���ʹ��ڵ����λ��
    QPoint window_pos;
    QPoint mouse_pos;
};
