#include "parserwinrc.h"
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

ParserWinRC::ParserWinRC(QString fileName, QObject *parent) :
    QObject(parent)
{
    m_fileName = fileName;
}

void ParserWinRC::startParser()
{
    QFile file(m_fileName);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream tx(&file);
        tx.setCodec("UTF-16");
        QString bytes = tx.readLine();
        while(!tx.atEnd())
        {
            //qDebug() << "line string " << bytes;
            if(bytes.indexOf("IDS_") != -1)
            {
                bytes = bytes.trimmed();
                int indexOfKey = bytes.indexOf(' ');
                QString key, value;
                if(indexOfKey != -1)
                {
                    key = bytes.mid(0, indexOfKey);
                    value = bytes.mid(indexOfKey).trimmed();
                    m_strMap.insert(key, value);
                }
            }
            bytes = tx.readLine();
        }
    }
    file.close();
    writeToFile();
}

void ParserWinRC::writeToFile()
{
    QFileInfo fileInfo(m_fileName);
    QString newFileName = fileInfo.path() + "/" + fileInfo.baseName() + ".h";
    QFile file(newFileName);
    if(file.open(QIODevice::Truncate | QIODevice::WriteOnly))
    {
        QStringList keys = m_strMap.keys();
        QString headFileName = QFileInfo(newFileName).fileName().toUpper().replace('.', '_');
        QString headStr = QString("#ifndef %1\n").arg(headFileName);
        file.write(headStr.toLocal8Bit());
        headStr = QString("#define %1\n\n").arg(headFileName);
        file.write(headStr.toLocal8Bit());
        for(int i = 0; i < keys.size(); i++)
        {
            QString lineStr = QString("#define     %1        QObject::tr(%2)\n").arg(keys[i]).arg(m_strMap.value(keys[i]));
            file.write(lineStr.toLocal8Bit());
        }
        //QMessageBox::information(this, "", newFileName);
        headStr = QString("\n\n#endif // %1").arg(headFileName);
        file.write(headStr.toLocal8Bit());
        QMessageBox::warning(nullptr, QString("succss"), newFileName);
    }
    file.flush();
    file.close();
}
