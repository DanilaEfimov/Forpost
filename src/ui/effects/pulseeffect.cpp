#include "pulseeffect.h"

#include <QObject>
#include <QTime>

QColor PulseEffect::getAccent() const
{
    return this->accent;
}

void PulseEffect::setAccent(const QColor &newAccent)
{
    this->accent = newAccent;
}

int PulseEffect::getPeriod() const
{
    return this->timer.interval();
}

void PulseEffect::setPeriod(const QTime& newPeriod)
{
    this->timer.setInterval(newPeriod.msec());
}

void PulseEffect::setPeriod(int msec)
{
    this->timer.setInterval(msec);
}

QColor PulseEffect::currentColor() const
{
    int remains = this->timer.remainingTime();  // msec
    double aspect = static_cast<double>(remains) / this->getPeriod();
    int alpha = std::floor(std::abs(std::sin(aspect * 2 * M_PI) * 255));

    QColor current = QColor(this->accent.red(),
                            this->accent.green(),
                            this->accent.blue(),
                            alpha);
    return current;
}

PulseEffect::PulseEffect(const QTime& period, const QColor& accent)
    : CircleRenderEffect(), accent(accent)
{
    this->timer.setInterval(period.msec());

    connect(&this->timer, &QTimer::timeout, this, [this](){
        auto interval = this->timer.interval();
        this->timer.start(interval);
    });
}

PulseEffect::PulseEffect(int msec, const QColor &accent)
    : PulseEffect(QTime(0, 0, 0, msec), accent)
{}

void PulseEffect::render(QPainter& painter, const Ellipse& ellipse)
{
    QColor current = this->currentColor();
    QBrush brush(current);

    painter.setBackground(brush);
    painter.drawEllipse(ellipse.toRect());
}
