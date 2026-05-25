#ifndef PINGEFFECT_H
#define PINGEFFECT_H

#include "circlerendereffect.h"

#include <QTimer>

class PingEffect : public CircleRenderEffect, public QObject
{
    Q_OBJECT

    QColor accent;
    QTimer timer;
    int radius;
    float delay = 20.f;    // per cents of timer.interval()

public:
    PingEffect(const QColor& accent, const QTime& period, int radius);
    PingEffect(const QColor& accent, int msec, int radius);
    virtual ~PingEffect() override = default;

    void render(QPainter& painter, const Ellipse& ellipse) override;

    void setDelay(float percents);
    float getDelay() const;

    void setRadius(int radius);
    int getRadius() const;

    void setPeriod(const QTime& period);
    QTime getPeriodTime() const;
    void setPeriod(int msec);
    int getPeriod() const;
};

#endif // PINGEFFECT_H
