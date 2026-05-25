#ifndef SOLIDRENDEREFFECT_H
#define SOLIDRENDEREFFECT_H

#include "circlerendereffect.h"

class SolidRenderEffect : public CircleRenderEffect
{
    QColor accent;

public:
    SolidRenderEffect(const QColor& fill);
    virtual ~SolidRenderEffect() override = default;

    void render(QPainter &painter, const Ellipse &ellipse) override;

    QColor getAccent() const;
    void setAccent(const QColor &newAccent);
};

#endif // SOLIDRENDEREFFECT_H
