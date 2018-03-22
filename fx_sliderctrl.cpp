#include "fx_sliderctrl.h"

QTPART::CFX_SliderCtrl::CFX_SliderCtrl(QWidget *parent) :
    QSlider(parent)
{
}


QTPART::CGW_CustomEdit::CGW_CustomEdit(QWidget *parent) :
    QLineEdit(parent)
{

}


QTPART::CGW_Edit::CGW_Edit(QWidget *parent) :
    CGW_CustomEdit(parent)
{

}


QTPART::CGW_NumberEdit::CGW_NumberEdit(QWidget *parent) :
    CGW_CustomEdit(parent)
{

}
