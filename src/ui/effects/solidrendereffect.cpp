#include "solidrendereffect.h"

#include <QPainterPath>

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


void SolidRenderEffect::render(QPainter &painter, const ellipse_wp &ellipse)
{
    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush(this->accent);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    painter.drawEllipse(ellipse.first.toRect());
}
