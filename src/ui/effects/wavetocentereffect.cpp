#include "wavetocentereffect.h"

#include <QPainterPath>

QColor WaveToCenterEffect::getAccent() const
{
    return this->accent;
}

void WaveToCenterEffect::setAccent(const QColor &newAccent)
{
    this->accent = newAccent;
}

quint16 WaveToCenterEffect::getDistance() const
{
    return this->distance;
}

void WaveToCenterEffect::setDistance(quint16 newDistance)
{
    this->distance = newDistance;
}

quint8 WaveToCenterEffect::getWidth() const
{
    return this->width;
}

void WaveToCenterEffect::setWidth(quint8 newWidth)
{
    this->width = newWidth;
}

quint8 WaveToCenterEffect::getStep() const
{
    return this->step;
}

void WaveToCenterEffect::setStep(quint8 newStep)
{
    this->step = newStep;
}

WaveToCenterEffect::WaveToCenterEffect(
    const QColor &accent,
    quint16 distance
    ) : CircleRenderEffect(),
    accent(accent),
    distance(distance)
{
    if(this->distance == 0)
        throw std::invalid_argument("WaveToCentedEffect::WaveToCentedEffect: distance between waves cannot be 0");
}

void WaveToCenterEffect::render(QPainter& painter, const ellipse_wp &elps)
{
    painter.setRenderHint(QPainter::Antialiasing);

    const auto& ellipse = elps.first;
    float aspect = static_cast<float>(ellipse.width) / static_cast<float>(ellipse.height);
    quint16 count = ellipse.height / this->distance;
    QPainterPath outer, inner;
    QPoint center = ellipse.center;

    for(qsizetype i = 1; i < count; i++) {
        quint16 aaxis = i * this->distance + this->step;
        quint16 baxis = static_cast<float>(std::floor(aaxis * aspect));
        inner.addEllipse(center, aaxis, baxis);
        outer.addEllipse(center, aaxis + this->width, baxis + this->width);

        QPainterPath path = outer.subtracted(inner);
        QBrush brush(this->accent);
        painter.drawPath(path);
    }

    this->step = (this->step - 1) % this->distance;
}
