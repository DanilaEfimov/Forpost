#ifndef CIRCLERENDEREFFECT_H
#define CIRCLERENDEREFFECT_H

#include <QObject>
#include <QPainter>
#include <QRect>

struct Ellipse {
    QPoint center;
    quint16 height;
    quint16 width;

    Ellipse(QPoint center, quint16 height, quint16 width);
    Ellipse(QPoint center, quint16 radius);

    QRect toRect() const;
};

// ellipse with position
using ellipse_wp = QPair<Ellipse, QPoint>;

class CircleRenderEffect : public QObject
{
    Q_OBJECT

public:
    virtual void render(QPainter& painter, const ellipse_wp& ellipse) = 0;
};

#endif // CIRCLERENDEREFFECT_H
