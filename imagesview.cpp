#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <QFileDialog>
#include <QtConcurrent/QtConcurrentMap>
#include <QStandardPaths>
#include <QHBoxLayout>
#include <qmath.h>
#include <QShortcut>
#include "ImagesView.h"

const int c_nImageSize = 100;

// ����ͼƬ
QImage scale(const QString &imageFileName)
{
    QImage image(imageFileName);
    QThread::msleep(100);
    return image.scaled(QSize(c_nImageSize, c_nImageSize), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

ImagesView::ImagesView(QWidget *parent)
    : QWidget(parent)
{
    setWindowIcon(QIcon(":/Images/logo"));
    setWindowTitle(QStringLiteral("Qt֮QFutureWatcher"));
    resize(800, 600);

    // ��ʼ���ؼ�
    m_pWatcher = new QFutureWatcher<QImage>(this);
    m_pOpenButton = new QPushButton(QStringLiteral("��ͼƬ"));
    m_pCancelButton = new QPushButton(QStringLiteral("ȡ��"));
    m_pPauseButton = new QPushButton(QStringLiteral("��ͣ/�ָ�"));
    m_pImageWidget = new QScrollArea;
    QProgressBar *pProgressBar = new QProgressBar(this);

    m_pCancelButton->setEnabled(false);
    m_pPauseButton->setEnabled(false);

    // ����
    QHBoxLayout *pButtonLayout = new QHBoxLayout();
    pButtonLayout->addWidget(m_pOpenButton);
    pButtonLayout->addWidget(m_pCancelButton);
    pButtonLayout->addWidget(m_pPauseButton);
    pButtonLayout->addStretch();
    pButtonLayout->setSpacing(10);
    pButtonLayout->setMargin(0);

    m_pImagesLayout = new QGridLayout();

    m_pMainLayout = new QVBoxLayout();
    m_pMainLayout->addLayout(pButtonLayout);
    m_pMainLayout->addWidget(pProgressBar);
    m_pMainLayout->addWidget(m_pImageWidget);
    m_pImageWidget->setLayout(m_pImagesLayout);
    m_pMainLayout->addStretch();
    m_pMainLayout->setSpacing(10);
    m_pMainLayout->setContentsMargins(10, 10, 10, 10);
    setLayout(m_pMainLayout);

    // �����źŲ� - ���ء���ʾ���ȡ��򿪡�ȡ���Ȳ���
    connect(m_pWatcher, SIGNAL(resultReadyAt(int)), SLOT(showImage(int)));
    connect(m_pWatcher, SIGNAL(progressRangeChanged(int,int)), pProgressBar, SLOT(setRange(int,int)));
    connect(m_pWatcher, SIGNAL(progressValueChanged(int)), pProgressBar, SLOT(setValue(int)));
    connect(m_pWatcher, SIGNAL(finished()), SLOT(finished()));
    connect(m_pOpenButton, SIGNAL(clicked()), SLOT(open()));
    connect(m_pCancelButton, SIGNAL(clicked()), m_pWatcher, SLOT(cancel()));
    connect(m_pPauseButton, SIGNAL(clicked()), m_pWatcher, SLOT(togglePaused()));
    QShortcut* shortcut = new QShortcut(QKeySequence(Qt::Key_Escape), this);
    //shortcut->setContext(Qt::ApplicationShortcut);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(on_actEsc()));
}

ImagesView::~ImagesView()
{
    m_pWatcher->cancel();
    m_pWatcher->waitForFinished();
}

// ��Ŀ¼������ͼƬ
void ImagesView::open()
{
    // ����Ѿ�����ͼƬ��ȡ�������еȴ�
    if (m_pWatcher->isRunning()) {
        m_pWatcher->cancel();
        m_pWatcher->waitForFinished();
    }

    // ��ʾһ���ļ��򿪶Ի���
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      QStringLiteral("ѡ��ͼƬ"),
                                                      QStandardPaths::writableLocation(QStandardPaths::PicturesLocation),
                                                      "*.jpg *.png");

    if (files.count() == 0)
        return;

    // ��һ���򵥵Ĳ���
    qDeleteAll(labels);
    labels.clear();

    int dim = qSqrt(qreal(files.count())) + 1;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            QLabel *pLabel = new QLabel(this);
            pLabel->setFixedSize(c_nImageSize, c_nImageSize);
            m_pImagesLayout->addWidget(pLabel, i, j);
            labels.append(pLabel);
        }
    }

    // ʹ�� mapped ��Ϊ files �����̰߳�ȫ�� scale ����
    // ����ʹ�� QtConcurrent::run(...) ������һ�������ļ��ء�
    m_pWatcher->setFuture(QtConcurrent::mapped(files, scale));

    m_pOpenButton->setEnabled(false);
    m_pCancelButton->setEnabled(true);
    m_pPauseButton->setEnabled(true);
}

// ��ʾͼƬ
void ImagesView::showImage(int index)
{
    labels[index]->setPixmap(QPixmap::fromImage(m_pWatcher->resultAt(index)));
}

// ���°�ť״̬
void ImagesView::finished()
{
    m_pOpenButton->setEnabled(true);
    m_pCancelButton->setEnabled(false);
    m_pPauseButton->setEnabled(false);
}

void ImagesView::on_actEsc()
{
    qDebug()<<"esc shortcut was excuted.";
}
