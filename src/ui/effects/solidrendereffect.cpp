#include "solidrendereffect.h"

SolidRenderEffect::SolidRenderEffect(const QColor& fill)
    : CircleRenderEffect(), accent(fill)
{}

QColor SolidRenderEffect::getAccent() const
{
    return this->accent;
}

void SolidRenderEffect::setAccent(const QColor &newAccent)
{
    this->accent = newAccent;
}


void SolidRenderEffect::render(QPainter &painter, const Ellipse &ellipse)
{
    QBrush brush(this->accent);
    painter.drawEllipse(ellipse.toRect());
}
