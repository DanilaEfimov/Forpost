#include "knob.h"
#include "ui_knob.h"

#include <QPainter>
#include <QPaintEvent>

float Knob::getAngle() const
{
    return this->angle;
}

void Knob::setAngle(float newAngle)
{
    this->angle = newAngle;
}

void Knob::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    auto center = this->rect().center();

}

void Knob::mousePressEvent(QMouseEvent *ev)
{
    this->lastPos = ev->pos();
}

void Knob::mouseMoveEvent(QMouseEvent *ev)
{
    auto currPos = ev->pos();
    int dx = currPos.x() - this->lastPos.x();
    int dy = currPos.y() - this->lastPos.y();

    this->update();
}

float Knob::normalize(float angle)
{
    angle = std::fmod(angle, 360.f);

    if(angle < 0.f)
        angle += 360;

    return angle;
}

void Knob::update()
{

}

Knob::Knob(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Knob)
{
    ui->setupUi(this);
}

Knob::~Knob()
{
    delete ui;
}
