#ifndef WAVETOCENTEREFFECT_H
#define WAVETOCENTEREFFECT_H

#include "circlerendereffect.h"

#include <QColor>

class WaveToCenterEffect : public CircleRenderEffect
{
    QColor accent;
    quint16 distance;   // in pixels
    quint8 width = 2;   // in pixels
    quint8 step = 1;    // in pixels

public:
    WaveToCenterEffect(const QColor &accent, quint16 distance = 50);
    virtual ~WaveToCenterEffect() override = default;

    void render(QPainter& painter, const ellipse_wp& ellispe) override;

    QColor getAccent() const;
    void setAccent(const QColor &newAccent);

    quint16 getDistance() const;
    void setDistance(quint16 newDistance);

    quint8 getWidth() const;
    void setWidth(quint8 newWidth);

    quint8 getStep() const;
    void setStep(quint8 newStep);
};

#endif // WAVETOCENTEREFFECT_H
