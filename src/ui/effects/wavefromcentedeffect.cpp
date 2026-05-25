#include "wavefromcentedeffect.h"

#include <QPainterPath>

QColor WaveFromCenterEffect::getAccent() const
{
    return this->accent;
}

void WaveFromCenterEffect::setAccent(const QColor &newAccent)
{
    this->accent = newAccent;
}

quint16 WaveFromCenterEffect::getDistance() const
{
    return this->distance;
}

void WaveFromCenterEffect::setDistance(quint16 newDistance)
{
    this->distance = newDistance;
}

quint8 WaveFromCenterEffect::getWidth() const
{
    return this->width;
}

void WaveFromCenterEffect::setWidth(quint8 newWidth)
{
    this->width = newWidth;
}

quint8 WaveFromCenterEffect::getStep() const
{
    return this->step;
}

void WaveFromCenterEffect::setStep(quint8 newStep)
{
    this->step = newStep;
}

WaveFromCenterEffect::WaveFromCenterEffect(
    const QColor &accent,
    quint16 distance
    ) : CircleRenderEffect(),
    accent(accent),
    distance(distance)
{
    if(this->distance == 0)
        throw std::invalid_argument("WaveFromCentedEffect::WaveFromCentedEffect: distance between waves cannot be 0");
}

void WaveFromCenterEffect::render(QPainter& painter, const Ellipse& ellipse)
{
    painter.setRenderHint(QPainter::Antialiasing);

    float aspect = static_cast<float>(ellipse.width) / static_cast<float>(ellipse.height);
    quint16 count = ellipse.height / this->distance;
    QPainterPath outer, inner;
    QPoint center = ellipse.center;

    for(qsizetype i = 1; i < count; i++){
        quint16 aaxis = i * this->distance + this->step;
        quint16 baxis = static_cast<float>(std::floor(aaxis * aspect));
        inner.addEllipse(center, aaxis, baxis);
        outer.addEllipse(center, aaxis + this->width, baxis + this->width);

        QPainterPath path = outer.subtracted(inner);
        QBrush brush(this->accent);
        painter.drawPath(path);
    }

    this->step = (this->step + 1) % this->distance;
}
