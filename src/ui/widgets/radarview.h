#ifndef RADARVIEW_H
#define RADARVIEW_H

#include "circlerendereffect.h"

#include <QWidget>
#include <QPointF>
#include <QString>
#include <memory>
#include <optional>

enum class TargetType {Friend, Enimy, Neutral};

struct RadarTarget {
    QString label;
    double angle;
    double distance;
    double velocityAngle;
    double rotateSpeed;
    double movingSpeed;
    int id;
    TargetType type;

    QPointF getPos(const QPointF& center) const;
    inline QColor markColorByType() const noexcept;
    void move();
};

namespace Ui {
class RadarView;
}

class RadarView : public QWidget
{
    Q_OBJECT

    QList<RadarTarget> targets = {};
    QColor accentColor;
    QFont font;
    std::unique_ptr<CircleRenderEffect> effect = nullptr;
    quint8 sectors;
    quint8 circles;

    void applyFlags();

public:
    explicit RadarView(quint8 circles,
                       quint8 sectors,
                       QColor accentColor,
                       QWidget *parent = nullptr);

    ~RadarView();

    void addTarget(const RadarTarget& target);
    bool contains(int id) const;
    std::optional<RadarTarget> getTarget(int id) const;
    void removeTarget(int id);

    void setRenderEffect(std::unique_ptr<CircleRenderEffect>&& effect);

    QColor getAccentColor() const;
    void setAccentColor(const QColor &newAccentColor);

    quint8 getSectors() const;
    void setSectors(quint8 newSectors);

    quint8 getCircles() const;
    void setCircles(quint8 newCircles);

    QFont getFont() const;
    void setFont(const QFont &newFont);

private:
    Ui::RadarView* ui;

    QPointF intersectEllipse(quint16 ax, quint16 by, double angle);
    void printTargets(QPainter& painter);
    void printTarget(QPainter& painter, const RadarTarget& t, QPointF center);
    void printSectors(QPainter& painter);
    void printCircles(QPainter& painter);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
};

#endif // RADARVIEW_H
