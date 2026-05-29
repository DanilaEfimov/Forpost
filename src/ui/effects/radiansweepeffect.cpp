#include "radiansweepeffect.h"

QColor RadianSweepEffect::getAccent() const
{
    return this->accent;
}

void RadianSweepEffect::setAccent(const QColor &newAccent)
{
    this->accent = newAccent;
}

double RadianSweepEffect::getOmega() const
{
    return this->omega;
}

void RadianSweepEffect::setOmega(double newOmega)
{
    this->omega = newOmega;
}

double RadianSweepEffect::getAngle() const
{
    return angle;
}

void RadianSweepEffect::setAngle(double newAngle)
{
    this->angle = newAngle;
}

quint8 RadianSweepEffect::getWidth() const
{
    return this->width;
}

void RadianSweepEffect::setWidth(quint8 newWidth)
{
    this->width = newWidth;
}

RadianSweepEffect::RadianSweepEffect(QColor accent, double omega)
    : CircleRenderEffect(),
    accent(accent),
    omega(omega)
{}

void RadianSweepEffect::render(QPainter& painter, const Ellipse& ellipse)
{
    QPen pen(this->accent);
    pen.setWidth(this->width);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);

    this->angle += this->omega;
    painter.drawLine(ellipse.center, this->currentPoint(ellipse));
}

QPointF RadianSweepEffect::currentPoint(const Ellipse &ellipse) const
{
    const double a = ellipse.width  * 0.5;
    const double b = ellipse.height * 0.5;

    const double c = std::cos(angle);
    const double s = std::sin(angle);

    const double t =
        1.0 /
        std::sqrt(
            (c * c) / (a * a) +
            (s * s) / (b * b)
            );

    return QPointF(
        ellipse.center.x() + t * c,
        ellipse.center.y() + t * s
        );
}
