#ifndef CMKA_SILDERCTRL_H
#define CMKA_SILDERCTRL_H

#include <QWidget>
#include "fx_sliderctrl.h"

class CMKA_SilderCtrl : public QTPART::CFX_SliderCtrl
{
    Q_OBJECT
public:
    explicit CMKA_SilderCtrl(QWidget *parent = 0);

signals:

public slots:

};

#endif // CMKA_SILDERCTRL_H
