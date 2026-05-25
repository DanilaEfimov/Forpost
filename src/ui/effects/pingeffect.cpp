#include "pingeffect.h"

#include <QTime>

QColor PingEffect::getAccent() const
{
    return this->accent;
}

void PingEffect::setAccent(const QColor &newAccent)
{
    this->accent = newAccent;
}

PingEffect::PingEffect(const QColor& accent, int msec, int radius)
    : CircleRenderEffect(),
    accent(accent),
    timer(),
    radius(radius),
    period(msec)
{
    this->timer.start();
}

void PingEffect::render(QPainter& painter, const Ellipse& ellipse)
{
    float progress = (this->timer.elapsed() % this->period) / (float) this->period;

    if (progress > (1.0f - this->delay))
        return;

    float intensity = 1.0f - progress;
    int currentRadius = this->radius * progress;

    QPen pen(this->accent);
    pen.setWidth(2);

    QColor c = this->accent;
    c.setAlphaF(intensity);
    pen.setColor(c);

    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);

    Ellipse ping(ellipse.center, currentRadius);
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

void PingEffect::setPeriod(int msec)
{
    this->period = std::abs(msec);
}

int PingEffect::getPeriod() const
{
    return this->period;
}

