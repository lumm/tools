#ifndef CMKA_COMBOBOXITEMDELEGATE_H
#define CMKA_COMBOBOXITEMDELEGATE_H

#include <QObject>
#include <QComboBox>
#include <QStyledItemDelegate>
#include <QAbstractItemView>

class CMKA_ComboBoxItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CMKA_ComboBoxItemDelegate(QObject *parent = 0);

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    static void scaleDash(QVector<qreal> &dashes, qreal scale = 1);

private:
    QIcon m_currentIcon;
};

class CMKA_ComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit CMKA_ComboBox(QWidget *parent = 0);

protected:
    void    showEvent(QShowEvent *e);
    void    paintEvent(QPaintEvent *e);
    void    initStyleOption(QStyleOptionComboBox *option);

    CMKA_ComboBoxItemDelegate     *customItemDelegate;
};

#endif // CMKA_COMBOBOXITEMDELEGATE_H
