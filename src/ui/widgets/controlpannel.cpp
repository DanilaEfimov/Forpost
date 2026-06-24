#include "controlpannel.h"
#include "ui_controlpannel.h"

ControlPannel::ControlPannel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ControlPannel)
{
    ui->setupUi(this);
}

ControlPannel::~ControlPannel()
{
    delete ui;
}
