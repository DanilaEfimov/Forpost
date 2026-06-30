#ifndef RADIANSWEEPEFFECT_H
#define RADIANSWEEPEFFECT_H

#include "circlerendereffect.h"

class RadianSweepEffect : public CircleRenderEffect
{
    QColor accent;
    double omega;       // radian speed
    double angle = 0.0; // current
    quint8 width = 2;   // in pixels

public:
    RadianSweepEffect(QColor accent, double omega);

    void render(QPainter& painter, const ellipse_wp& ellipse) override;

    QColor getAccent() const;
    void setAccent(const QColor &newAccent);

    double getOmega() const;
    void setOmega(double newOmega);

    double getAngle() const;
    void setAngle(double newAngle);

    quint8 getWidth() const;
    void setWidth(quint8 newWidth);

private:
    QPointF currentPoint(const Ellipse& ellipse) const;
};

#endif // RADIANSWEEPEFFECT_H
