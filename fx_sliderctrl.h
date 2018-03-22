#ifndef FX_SLIDERCTRL_H
#define FX_SLIDERCTRL_H

#include <QWidget>
#include <QSlider>
#include <QLineEdit>

namespace QTPART {

class CFX_SliderCtrl : public QSlider
{
    Q_OBJECT
public:
    explicit CFX_SliderCtrl(QWidget *parent = 0);
};

class CGW_CustomEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit CGW_CustomEdit(QWidget *parent = 0);
};

class CGW_Edit : public CGW_CustomEdit
{
    Q_OBJECT
public:
    CGW_Edit(QWidget *parent = 0);
};

class CGW_NumberEdit : public CGW_CustomEdit
{
    Q_OBJECT
public:
    explicit CGW_NumberEdit(QWidget *parent = 0);
};

}

#endif // FX_SLIDERCTRL_H
