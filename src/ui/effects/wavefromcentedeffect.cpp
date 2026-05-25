#include "wavefromcentedeffect.h"


QColor WaveFromCentedEffect::getAccent() const
{
    return this->accent;
}

void WaveFromCentedEffect::setAccent(const QColor &newAccent)
{
    this->accent = newAccent;
}

quint16 WaveFromCentedEffect::getDistance() const
{
    return this->distance;
}

void WaveFromCentedEffect::setDistance(quint16 newDistance)
{
    this->distance = newDistance;
}

quint8 WaveFromCentedEffect::getSpeed() const
{
    return this->speed;
}

void WaveFromCentedEffect::setSpeed(quint8 newSpeed)
{
    this->speed = newSpeed;
}

WaveFromCentedEffect::WaveFromCentedEffect(
    const QColor &accent, quint16 distance, quint8 speed)
    : CircleRenderEffect(), QObject(),
    accent(accent),
    distance(distance),
    speed(speed)
{}

void WaveFromCentedEffect::render(QPainter& painter, const Ellipse& ellispe)
{

}
