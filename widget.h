#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRegExpValidator>
#include <QPainter>
#include <QToolButton>
#include <QtWidgets>

#include "lineedit.h"
#include "parserwinrc.h"
#include "cmka_silderctrl.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QToolButton *button;
    ParserWinRC *rc;
};

#endif // WIDGET_H
