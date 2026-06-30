#ifndef SOLIDRECTBOUNDEFFECT_H
#define SOLIDRECTBOUNDEFFECT_H

#include <QColor>

#include "rectrendereffect.h"

#define NO_ROUND 0

class SolidRectBoundEffect : public RectRenderEffect
{
    QColor boundColor;
    qsizetype boundWidth;
    qsizetype radius;

public:
    SolidRectBoundEffect(const QColor& borderColor,
                         qsizetype boundWidth = 3,
                         qsizetype radius = NO_ROUND);
    virtual ~SolidRectBoundEffect() = default;

    QColor getBoundColor() const;
    void setBoundColor(const QColor &newBoundColor);

    qsizetype getBoundWidth() const;
    void setBoundWidth(qsizetype newBoundWidth);

    qsizetype getRadius() const;
    void setRadius(qsizetype newRadius);
    void setNoRound();

    void render(QPainter &p, const QRect &rect) override;
};

#endif // SOLIDRECTBOUNDEFFECT_H
