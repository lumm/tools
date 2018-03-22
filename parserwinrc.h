#ifndef PARSERWINRC_H
#define PARSERWINRC_H

#include <QObject>
#include <QFile>
#include <qmap.h>
#include <QTextStream>

class ParserWinRC : public QObject
{
    Q_OBJECT
public:
    explicit ParserWinRC(QString fileName, QObject *parent = 0);

    void startParser();

protected:
    void writeToFile();
signals:

public slots:


private:
    QMap<QString, QString> m_strMap;
    QString m_fileName;
};

#endif // PARSERWINRC_H
