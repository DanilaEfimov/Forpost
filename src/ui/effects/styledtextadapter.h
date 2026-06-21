#ifndef STYLEDTEXTADAPTER_H
#define STYLEDTEXTADAPTER_H

#include "textcolorschemeeffect.h"

#include <QTextDocument>

class StyledTextAdapter
{
public:
    static QTextDocument* toDocument(const StyledText& styled);
};

#endif // STYLEDTEXTADAPTER_H
