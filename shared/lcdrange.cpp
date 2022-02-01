#include "lcdrange.h"
#include <QSlider>
#include <QLCDNumber>
#include <QLabel>
#include <QHBoxLayout>

LcdRange::LcdRange(QWidget *parent, QString label, uint nbLcd, int min, int max, int valDep) : QWidget(parent)
{
    QLabel *ql=new QLabel(label);
    QLCDNumber *qlcd = new QLCDNumber(nbLcd);
    QSlider *qsl = new QSlider(Qt::Horizontal);
    qsl->setRange(min,max);
    qsl->setTickPosition(QSlider::TicksAbove);
    if(valDep==-1)
        valDep=(min+max)/2;
    qsl->setValue(valDep);
    qlcd->display(valDep);

    connect(qsl,SIGNAL(valueChanged(int)),qlcd,SLOT(display(int)));
    connect(qsl,SIGNAL(valueChanged(int)),this,SIGNAL(valueChanged(int)));

    QHBoxLayout *qvb=new QHBoxLayout();
    qvb->addWidget(ql);
    qvb->addWidget(qlcd);
    qvb->addWidget(qsl);
    setLayout(qvb);
}
