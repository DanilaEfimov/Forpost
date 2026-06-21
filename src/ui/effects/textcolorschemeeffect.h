#ifndef TEXTCOLORSCHEMEEFFECT_H
#define TEXTCOLORSCHEMEEFFECT_H

#include "styledtext.h"

#include <QVector>
#include <QColor>

class TextColorSchemeEffect
{
public:
    TextColorSchemeEffect();

    virtual StyledText apply(const QString& line) = 0;
};

#endif // TEXTCOLORSCHEMEEFFECT_H
