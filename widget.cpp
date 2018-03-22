#include "widget.h"
#include "ui_widget.h"

#include <QPaintEvent>
#include <stdio.h>
#include <io.h>
#include <QToolTip>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
//    if (watched == button && event->type() == QEvent::Paint) {
//        QRect rc = button->rect();
//        if(button->isDown())
//        {
//            rc.setTop(rc.top() + 1);
//            rc.setLeft(rc.left() +  1);
//        }
//        else
//        {
//            rc.setRight(rc.right() - 1);
//            rc.setBottom(rc.bottom() - 1);
//        }
//        watched->event(event);
//        QPainter painter;
//        painter.begin(button);
//        painter.fillRect(rc, Qt::blue);
//        painter.end();
//        return false;
//    }
    return false;
}


void Widget::on_pushButton_clicked()
{
    rc = new ParserWinRC(ui->lineEdit->text());
    rc->startParser();
}

void Widget::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    ui->lineEdit->setText(fileName);
}
