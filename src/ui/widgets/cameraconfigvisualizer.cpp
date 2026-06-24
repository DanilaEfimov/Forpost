#include "cameraconfigvisualizer.h"
#include "ui_cameraconfigvisualizer.h"

CameraConfigVisualizer::CameraConfigVisualizer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CameraConfigVisualizer)
{
    ui->setupUi(this);
}

CameraConfigVisualizer::~CameraConfigVisualizer()
{
    delete ui;
}


void CameraConfigVisualizer::write(CameraConfig& out) const
{

}

void CameraConfigVisualizer::visualize(const CameraConfig& in)
{
}

CameraConfig CameraConfigVisualizer::get() const
{
}
