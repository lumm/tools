#include "cmka_combobox.h"
#include <QDebug>
#include <QPainter>
#include <QApplication>
#include <QScreen>
#include <QPen>
#include <QStylePainter>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QVariant>

CMKA_ComboBoxItemDelegate::CMKA_ComboBoxItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void CMKA_ComboBoxItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int itemIndex = index.row();
    QPen oldPen;

    const QWidget *itemThis = option.widget;
    QColor gray_color(192, 192, 192);
    QBrush gray_brush(QColor(240, 240, 240));
    QBrush brush(QColor(255, 255, 255));
    QRect rc = option.rect;

    QBrush logbrush(Qt::SolidPattern);
    if(itemThis->isEnabled())
    {
        logbrush.setColor(QColor(0, 0, 0));
    }
    else
    {
        logbrush.setColor(gray_color);
    }

    if(option.state & QStyle::State_Selected)
    {
        QBrush br(option.palette.highlight());
        painter->fillRect(rc, br);
    }
    else
    {
        if(itemThis->isEnabled())
        {
            painter->fillRect(rc, brush);
        }
        else
        {
            painter->fillRect(rc, gray_brush);
        }
    }
    switch(itemIndex)
    {
    case -1:
        break;
    case 0:
        if(itemThis->isEnabled())
        {
            QPen pen(QColor(0, 0, 0));
            oldPen = pen;
        }
        else
        {
            QPen pen(gray_color);
            oldPen = pen;
        }
        painter->save();
        painter->setPen(oldPen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    case 1:
    {
        QVector<qreal> dashes;
        dashes << 1 << 1 << 1 << 1 << 1 << 1 << 1 << 1 << 1 << 1;
        QPen pen(logbrush, 1);
        scaleDash(dashes, 3);
        pen.setDashPattern(dashes);
        painter->save();
        painter->setPen(pen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 2:
    {
        QVector<qreal> dashes;
        dashes << 2 << 1 << 2 << 1 << 2 << 1 << 2 << 1 << 2 << 1;
        QPen pen(logbrush, 1);
        scaleDash(dashes, 3);
        pen.setDashPattern(dashes);
        painter->save();
        painter->setPen(pen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 3:
    {
        QVector<qreal> dashes;
        dashes << 3 << 1 << 3 << 1 << 3 << 1 << 3 << 1 << 3 << 1 << 3 << 1;
        QPen pen(logbrush, 1);
        scaleDash(dashes, 3);
        pen.setDashPattern(dashes);
        painter->save();
        painter->setPen(pen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 4:
    {
        QVector<qreal> dashes;
        dashes << 3 << 1 << 1 << 1 << 3 << 1 << 1 << 1 << 3 << 1 << 1 << 1;
        QPen pen(logbrush, 1);
        scaleDash(dashes, 3);
        pen.setDashPattern(dashes);
        painter->save();
        painter->setPen(pen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 5:
    {
        QVector<qreal> dashes;
        dashes << 3 << 2 << 6 << 2 << 3 << 2 << 6 << 2 << 3 << 2 << 6 << 2;
        QPen pen(logbrush, 1);
        scaleDash(dashes, 3);
        pen.setDashPattern(dashes);
        painter->save();
        painter->setPen(pen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 6:
    {
        QVector<qreal> dashes;
        dashes << 5 << 2 << 2 << 2 << 5 << 2 << 2 << 2 << 5 << 2 << 2 << 2;
        QPen pen(logbrush, 1);
        scaleDash(dashes, 3);
        pen.setDashPattern(dashes);
        pen.setStyle(Qt::CustomDashLine);
        painter->save();
        painter->setPen(pen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 7:
    {
        if(!itemThis->isEnabled())
        {
            QPen pen(gray_color);
            oldPen = pen;
        }
        else
        {
            QPen pen(QColor(0, 0, 0));
            oldPen = pen;
        }
        painter->save();
        painter->setPen(oldPen);
        int nsep = rc.width() / 8;
        int h = rc.height();
        for(int i = 0; i < 8; i++)
        {
            QRect rect1(QPoint(rc.left() + nsep * i - nsep / 3, rc.top() + h/6),
                        QPoint(rc.left() + nsep + nsep *i, rc.top() + 7*h/6));
            int startAngle = 0 * 16;
            int spanAgnle = 130 * 16;
            painter->drawArc(rect1, startAngle, spanAgnle);

        }
        painter->restore();
        break;
    }
    case 8:
    {
        if(!itemThis->isEnabled())
        {
            QPen pen(gray_color);
            oldPen = pen;
        }
        else
        {
            QPen pen(QColor(0, 0, 0));
            oldPen = pen;
        }
        painter->save();
        painter->setPen(oldPen);
        int nsep = rc.width() / 6;
        int h = rc.height();
        for(int i = 0; i < 6; i++)
        {
            QRect rect1(QPoint(rc.left() + nsep * i - nsep / 3, rc.top() + h/6),
                        QPoint(rc.left() + nsep + nsep *i, rc.top() + 7*h/6));
            int startAngle = 0 * 16;
            int spanAgnle = 130 * 16;
            painter->drawArc(rect1, startAngle, spanAgnle);

        }
        painter->restore();
        break;
    }
    }
}

QWidget *CMKA_ComboBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QWidget *widget = QStyledItemDelegate::createEditor(parent, option, index);
    return widget;
}

void CMKA_ComboBoxItemDelegate::scaleDash(QVector<qreal> &dashes, qreal scale)
{
    QVector<qreal> tmpStore;
    for(int i = 0; i < dashes.size(); i++)
    {
        tmpStore.append(dashes[i] * scale);
    }
    dashes = tmpStore;
}




CMKA_ComboBox::CMKA_ComboBox(QWidget *parent):
    QComboBox(parent)
{
    customItemDelegate = new CMKA_ComboBoxItemDelegate(this);
    this->setItemDelegate(customItemDelegate);
}

void CMKA_ComboBox::showEvent(QShowEvent *e)
{
    QComboBox::showEvent(e);
}

void CMKA_ComboBox::paintEvent(QPaintEvent *e)
{
    QComboBox::paintEvent(e);

    QPainter *painter = new QPainter(this);
    QPen oldPen;
    QRect rc = this->rect();
    rc.setWidth(rc.width() - 20);
    QColor gray_color(192, 192, 192);
    QBrush gray_brush(QColor(240, 240, 240));
    QBrush brush(QColor(255, 255, 255));

    QBrush logbrush(Qt::SolidPattern);


    int itemIndex = this->currentIndex();
    switch(itemIndex)
    {
    case -1:
        break;
    case 0:
    {
        QPen pen(QColor(0, 0, 0));
        oldPen = pen;
        painter->save();
        painter->setPen(oldPen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 1:
    {
        QVector<qreal> dashes;
        dashes << 1 << 1 << 1 << 1 << 1 << 1 << 1 << 1 << 1 << 1;
        QPen pen(logbrush, 1);
        customItemDelegate->scaleDash(dashes, 3);
        pen.setDashPattern(dashes);
        painter->save();
        painter->setPen(pen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 2:
    {
        QVector<qreal> dashes;
        dashes << 2 << 1 << 2 << 1 << 2 << 1 << 2 << 1 << 2 << 1;
        QPen pen(logbrush, 1);
        customItemDelegate->scaleDash(dashes, 3);
        pen.setDashPattern(dashes);
        painter->save();
        painter->setPen(pen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 3:
    {
        QVector<qreal> dashes;
        dashes << 3 << 1 << 3 << 1 << 3 << 1 << 3 << 1 << 3 << 1 << 3 << 1;
        QPen pen(logbrush, 1);
        customItemDelegate->scaleDash(dashes, 3);
        pen.setDashPattern(dashes);
        painter->save();
        painter->setPen(pen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 4:
    {
        QVector<qreal> dashes;
        dashes << 3 << 1 << 1 << 1 << 3 << 1 << 1 << 1 << 3 << 1 << 1 << 1;
        QPen pen(logbrush, 1);
        customItemDelegate->scaleDash(dashes, 3);
        pen.setDashPattern(dashes);
        painter->save();
        painter->setPen(pen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 5:
    {
        QVector<qreal> dashes;
        dashes << 3 << 2 << 6 << 2 << 3 << 2 << 6 << 2 << 3 << 2 << 6 << 2;
        QPen pen(logbrush, 1);
        customItemDelegate->scaleDash(dashes, 3);
        pen.setDashPattern(dashes);
        painter->save();
        painter->setPen(pen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 6:
    {
        QVector<qreal> dashes;
        dashes << 5 << 2 << 2 << 2 << 5 << 2 << 2 << 2 << 5 << 2 << 2 << 2;
        QPen pen(logbrush, 1);
        customItemDelegate->scaleDash(dashes, 3);
        pen.setDashPattern(dashes);
        pen.setStyle(Qt::CustomDashLine);
        painter->save();
        painter->setPen(pen);
        painter->drawLine(QPoint(rc.left(), rc.top() + rc.height()/2 ), QPoint(rc.right(), rc.top() + rc.height()/2 ));
        painter->restore();
        break;
    }
    case 7:
    {
        QPen pen(QColor(0, 0, 0));
        oldPen = pen;
        painter->save();
        painter->setPen(oldPen);
        int nsep = rc.width() / 8;
        int h = rc.height();
        for(int i = 0; i < 8; i++)
        {
            QRect rect1(QPoint(rc.left() + nsep * i - nsep / 3, rc.top() + h/6),
                        QPoint(rc.left() + nsep + nsep *i, rc.top() + 7*h/6));
            int startAngle = 0 * 16;
            int spanAgnle = 130 * 16;
            painter->drawArc(rect1, startAngle, spanAgnle);

        }
        painter->restore();
        break;
    }
    case 8:
    {
        QPen pen(QColor(0, 0, 0));
        oldPen = pen;
        painter->save();
        painter->setPen(oldPen);
        int nsep = rc.width() / 6;
        int h = rc.height();
        for(int i = 0; i < 6; i++)
        {
            QRect rect1(QPoint(rc.left() + nsep * i - nsep / 3, rc.top() + h/6),
                        QPoint(rc.left() + nsep + nsep *i, rc.top() + 7*h/6));
            int startAngle = 0 * 16;
            int spanAgnle = 130 * 16;
            painter->drawArc(rect1, startAngle, spanAgnle);

        }
        painter->restore();
        break;
    }
    }

}

void CMKA_ComboBox::initStyleOption(QStyleOptionComboBox *option)
{
    option->currentText.clear();
}

