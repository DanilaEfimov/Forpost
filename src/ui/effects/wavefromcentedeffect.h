#ifndef WAVEFROMCENTEDEFFECT_H
#define WAVEFROMCENTEDEFFECT_H

#include "circlerendereffect.h"

#include <QTimer>

class WaveFromCentedEffect : public CircleRenderEffect, public QObject
{
    Q_OBJECT

    QColor accent;
    quint16 distance = 50;  // in pixels
    quint8 speed;           // in pixels

public:
    WaveFromCentedEffect(const QColor &accent, quint16 distance, quint8 speed);
    virtual ~WaveFromCentedEffect() override = default;

    void render(QPainter& painter, const Ellipse& ellispe) override;

    QColor getAccent() const;
    void setAccent(const QColor &newAccent);

    quint16 getDistance() const;
    void setDistance(quint16 newDistance);

    quint8 getSpeed() const;
    void setSpeed(quint8 newSpeed);
};

#endif // WAVEFROMCENTEDEFFECT_H
