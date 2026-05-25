#ifndef CIRCLERENDEREFFECT_H
#define CIRCLERENDEREFFECT_H

#include <QPainter>
#include <QRect>
#include <QObject>

struct Ellipse {
    QPoint center;
    quint16 height;
    quint16 width;

    Ellipse(QPoint center, quint16 height, quint16 width);
    Ellipse(QPoint center, quint16 radius);

    QRect toRect() const;
};

class CircleRenderEffect : public QObject
{
    Q_OBJECT

public:
    CircleRenderEffect();
    virtual ~CircleRenderEffect();

    virtual void render(QPainter& painter, const Ellipse& ellipse) = 0;
};

#endif // CIRCLERENDEREFFECT_H
