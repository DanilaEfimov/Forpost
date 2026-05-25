#include "circlerendereffect.h"

#include <QPainter>
#include <QRect>
#include <QPoint>
#include <QtGlobal>

CircleRenderEffect::CircleRenderEffect()
{}

CircleRenderEffect::~CircleRenderEffect()
{}

Ellipse::Ellipse(QPoint center, quint16 height, quint16 width)
    : center(center), height(height), width(width)
{}

Ellipse::Ellipse(QPoint center, quint16 radius)
    : center(center), height(radius), width(radius)
{}

QRect Ellipse::toRect() const
{
    QPoint atopLeft = QPoint(this->center.x() - this->width / 2,
                             this->center.y() - this->height / 2);
    QPoint abottomRight = QPoint(this->center.x() + this->width / 2,
                             this->center.y() + this->height / 2);

    return QRect(atopLeft, abottomRight);
}
