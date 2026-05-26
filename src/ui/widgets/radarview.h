#ifndef RADARVIEW_H
#define RADARVIEW_H

#include "circlerendereffect.h"

#include <QWidget>
#include <memory>

namespace Ui {
class RadarView;
}

class RadarView : public QWidget
{
    Q_OBJECT

    QColor accentColor;
    std::unique_ptr<CircleRenderEffect> effect;
    quint8 sectors;
    quint8 circles;

    void applyFlags();

public:
    explicit RadarView(std::unique_ptr<CircleRenderEffect> effect,
                       quint8 circles,
                       quint8 sectors,
                       QColor accentColor,
                       QWidget *parent = nullptr);

    ~RadarView();

    void setRenderEffect(std::unique_ptr<CircleRenderEffect>&& effect);

    QColor getAccentColor() const;
    void setAccentColor(const QColor &newAccentColor);

    quint8 getSectors() const;
    void setSectors(quint8 newSectors);

    quint8 getCircles() const;
    void setCircles(quint8 newCircles);

private:
    Ui::RadarView* ui;

    QPointF intersectEllipse(quint16 ax, quint16 by, double angle);
    void printSectors(QPainter& painter);
    void printCircles(QPainter& painter);

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // RADARVIEW_H
