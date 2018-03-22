#include "lineedit.h"

LineEdit::LineEdit(QWidget *parent) : QLineEdit(parent)
{
    m_isLoacalLabel = false;
    maxValue = 1310;
    //QRegExp rx ("/(\d-)+/g");
    QRegularExpression rx ("([1-9][0-9]{0,}[,|-])+");
    setValidator (new QRegularExpressionValidator (rx, this));
    connect(this, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));
}

void LineEdit::keyPressEvent(QKeyEvent *e)
{
    QLineEdit::keyPressEvent(e);
}

void LineEdit::OnChar(QKeyEvent *e)
{
    qDebug() << "  ONChar" << e->key();
}

void LineEdit::textChanged(QString text)
{
    int start = 0;
    int end = 0;

    int curPos = this->cursorPosition();

    QRegExp regexp("[,|-]");

    if(!text.contains(regexp))
    {
        if( text.toInt() > maxValue )
        {
            setText(QString("%1").arg(maxValue));
        }
        return;

    }

    for(int i = 0; i < text.size(); i++)
    {
        start = text.indexOf(regexp, i);
        end = text.indexOf(regexp, start+1);
        QString tmpStr = text.mid(start+1, end-start-1);
        if(tmpStr.toInt() > maxValue)
        {
            text.remove(start+1, tmpStr.length());
            text.insert(start+1, QString("%1").arg(maxValue));
        }

    }
    this->setText(text);
    this->setCursorPosition(curPos);

}
