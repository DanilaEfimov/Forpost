#include "checkmarkeffect.h"

#include <QPainter>

QColor CheckMarkEffect::getMarkColor() const
{
    return this->markColor;
}

void CheckMarkEffect::setMarkColor(const QColor &newMarkColor)
{
    this->markColor = newMarkColor;
}

QColor CheckMarkEffect::getBackgroundColor() const
{
    return this->backgroundColor;
}

void CheckMarkEffect::setBackgroundColor(const QColor &newBackgroundColor)
{
    this->backgroundColor = newBackgroundColor;
}

size_t CheckMarkEffect::getWidth() const
{
    return this->width;
}

void CheckMarkEffect::setWidth(size_t newWidth)
{
    this->width = newWidth;
}

CheckMarkEffect::CheckMarkEffect(QColor mark, QColor background, size_t width)
    : CircleRenderEffect(), markColor(mark), backgroundColor(background), width(width)
{}

void CheckMarkEffect::render(QPainter &painter, const ellipse_wp &ellipse)
{
    painter.setRenderHint(QPainter::Antialiasing);

    size_t h = ellipse.first.height;
    size_t w = ellipse.first.width;

    size_t downX = w/2;
    size_t downY = h * 3/4;
    QPoint down = QPoint(downX, downY);

    size_t leftX = downX / 2;
    size_t leftY = h / 2;
    QPoint left = QPoint(leftX, leftY);

    size_t rightX = downX * 3/2;
    size_t rightY = downY / 2;
    QPoint right = QPoint(rightX, rightY);

    QBrush brush(this->backgroundColor);
    painter.setBackground(brush);

    QPen pen(this->markColor);
    pen.setWidth(this->width);
    painter.setPen(pen);

    painter.drawLine(down, left);
    painter.drawLine(down, right);
    painter.drawEllipse(ellipse.first.toRect());
}
