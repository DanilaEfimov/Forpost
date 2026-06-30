#ifndef PULSEEFFECT_H
#define PULSEEFFECT_H

#include "circlerendereffect.h"

#include <QTimer>

class PulseEffect : public CircleRenderEffect
{
    Q_OBJECT

    QColor accent;
    QTimer timer;

public:
    PulseEffect(const QTime& period, const QColor& accent);
    PulseEffect(int msec, const QColor& accent);
    virtual ~PulseEffect() = default;

    void render(QPainter& painter, const ellipse_wp& ellipse) override;

    QColor getAccent() const;
    void setAccent(const QColor &newAccent);

    int getPeriod() const;

    void setPeriod(const QTime& newPeriod);
    void setPeriod(int msec);

    QColor currentColor() const;
};

#endif // PULSEEFFECT_H
