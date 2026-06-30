#ifndef RECTRENDEREFFECT_H
#define RECTRENDEREFFECT_H

#include <QRect>
#include <QPainter>

class RectRenderEffect
{
public:
    virtual void render(QPainter& p, const QRect& rect) = 0;
};

#endif // RECTRENDEREFFECT_H
