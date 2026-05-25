#ifndef PINGEFFECT_H
#define PINGEFFECT_H

#include "circlerendereffect.h"

#include <QElapsedTimer>

class PingEffect : public CircleRenderEffect
{
    QColor accent;
    QElapsedTimer timer;
    int radius;
    int period = 1000;      // msec
    float delay = 0.2f;     // per cents

public:
    PingEffect(const QColor& accent, int msec, int radius);
    virtual ~PingEffect() override = default;

    void render(QPainter& painter, const Ellipse& ellipse) override;

    void setDelay(float percents);
    float getDelay() const;

    void setRadius(int radius);
    int getRadius() const;

    void setPeriod(int msec);
    int getPeriod() const;

    QColor getAccent() const;
    void setAccent(const QColor &newAccent);
};

#endif // PINGEFFECT_H
