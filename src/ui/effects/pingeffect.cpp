#include "pingeffect.h"

#include <QTime>

PingEffect::PingEffect(const QColor& accent, const QTime& period, int radius)
    : CircleRenderEffect(), QObject(), accent(accent), timer(this), radius(radius)
{
    this->timer.setInterval(period.msec());
    connect(&this->timer, &QTimer::timeout, this, [this](){
        auto interval = this->timer.interval();
        this->timer.start(interval);
    });
}

PingEffect::PingEffect(const QColor& accent, int msec, int radius)
    : PingEffect(accent, QTime(0, 0, 0, msec), radius)
{}

void PingEffect::render(QPainter& painter, const Ellipse& ellipse)
{
    int remains = this->timer.remainingTime();
    bool pingMark = remains / this->getPeriod() < this->delay;

    if(!pingMark)
        return;

    QBrush brush(this->accent);
    Ellipse ping(ellipse.center, this->radius);
    painter.drawEllipse(ping.toRect());
}

void PingEffect::setDelay(float percents)
{
    this->delay = std::abs(percents);
}

float PingEffect::getDelay() const
{
    return this->delay;
}

void PingEffect::setRadius(int radius)
{
    this->radius = std::abs(radius);
}

int PingEffect::getRadius() const
{
    return this->radius;
}

void PingEffect::setPeriod(const QTime& period)
{
    this->timer.setInterval(period.msec());
}

QTime PingEffect::getPeriodTime() const
{
    return QTime(0, 0, 0, this->timer.interval());
}

void PingEffect::setPeriod(int msec)
{
    this->timer.setInterval(msec);
}

int PingEffect::getPeriod() const
{
    return this->timer.interval();
}
