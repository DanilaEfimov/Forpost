#include "euleranglesvisualizer.h"
#include "ui_euleranglesvisualizer.h"

EulerAnglesVisualizer::EulerAnglesVisualizer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EulerAnglesVisualizer)
{
    ui->setupUi(this);
}

EulerAnglesVisualizer::~EulerAnglesVisualizer()
{
    delete ui;
}

void EulerAnglesVisualizer::write(EulerAngles& out) const
{

}
