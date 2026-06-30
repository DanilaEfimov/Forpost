#ifndef CHECKMARKEFFECT_H
#define CHECKMARKEFFECT_H

#include "circlerendereffect.h"

class CheckMarkEffect : public CircleRenderEffect
{
    QColor markColor;
    QColor backgroundColor;
    size_t width = 5;

public:
    CheckMarkEffect(QColor mark, QColor background, size_t width = 5);
    virtual ~CheckMarkEffect() = default;

    void render(QPainter &painter, const ellipse_wp &ellipse) override;

    QColor getMarkColor() const;
    void setMarkColor(const QColor &newMarkColor);

    QColor getBackgroundColor() const;
    void setBackgroundColor(const QColor &newBackgroundColor);

    size_t getWidth() const;
    void setWidth(size_t newWidth);
};

#endif // CHECKMARKEFFECT_H
