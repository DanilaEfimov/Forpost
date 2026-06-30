#include "solidrectboundeffect.h"

qsizetype SolidRectBoundEffect::getRadius() const
{
    return this->radius;
}

void SolidRectBoundEffect::setRadius(qsizetype newRadius)
{
    this->radius = newRadius;
}

void SolidRectBoundEffect::setNoRound()
{
    this->radius = NO_ROUND;
}

QColor SolidRectBoundEffect::getBoundColor() const
{
    return this->boundColor;
}

void SolidRectBoundEffect::setBoundColor(const QColor &newBoundColor)
{
    this->boundColor = newBoundColor;
}

qsizetype SolidRectBoundEffect::getBoundWidth() const
{
    return this->boundWidth;
}

void SolidRectBoundEffect::setBoundWidth(qsizetype newBoundWidth)
{
    this->boundWidth = newBoundWidth;
}

void SolidRectBoundEffect::render(QPainter &p, const QRect &rect)
{
    QPen pen(this->boundColor);
    pen.setWidth(this->boundWidth);
    p.setBrush(Qt::NoBrush);
    p.setPen(pen);

    if(this->radius == NO_ROUND)
        p.drawRect(rect);
    else
        p.drawRoundedRect(rect, this->radius, this->radius);
}
