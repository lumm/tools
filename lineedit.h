#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QKeyEvent>
#include <QDebug>
#include <QRegExpValidator>

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit LineEdit(QWidget *parent = 0);

protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void OnChar(QKeyEvent *e);

signals:

public slots:
    void textChanged(QString text);

private:
    bool m_isLoacalLabel;
    int maxValue;
    QChar m_curChar;
};

#endif // LINEEDIT_H
