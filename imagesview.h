#ifndef IMAGES_VIEW_H
#define IMAGES_VIEW_H

#include <QFutureWatcher>
#include <QWidget>
#include <QScrollArea>

class QLabel;
class QPushButton;
class QVBoxLayout;
class QGridLayout;

class ImagesView : public QWidget
{
    Q_OBJECT

public:
    explicit ImagesView(QWidget *parent = 0);
    ~ImagesView();

private slots:
    void open();  // ��Ŀ¼������ͼƬ
    void showImage(int index);  // ��ʾͼƬ
    void finished();  // ���°�ť״̬
    void on_actEsc();

private:
    QPushButton *m_pOpenButton;
    QPushButton *m_pCancelButton;
    QPushButton *m_pPauseButton;
    QScrollArea *m_pImageWidget;
    QVBoxLayout *m_pMainLayout;
    QGridLayout *m_pImagesLayout;
    QList<QLabel *> labels;
    QFutureWatcher<QImage> *m_pWatcher;
};

#endif // IMAGES_VIEW_H
