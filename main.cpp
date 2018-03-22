#include "widget.h"
#include "imagesview.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QWindow>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QStringList>
#include <QMimeData>
#include <QClipboard>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QPalette pa = a.palette("");
//    pa.setColor(QPalette::Background, Qt::white);
//    pa.setColor(QPalette::Button, Qt::white);
    //a.setPalette(pa);
    Widget w;
    w.show();

    return a.exec();
}
