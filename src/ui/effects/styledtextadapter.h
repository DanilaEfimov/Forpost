#ifndef STYLEDTEXTADAPTER_H
#define STYLEDTEXTADAPTER_H

#include "styledtext.h"

#include <QTextDocument>
#include <QTextEdit>

class StyledTextAdapter
{
public:
    static void print(const StyledText& styled, QTextEdit* edit);
};

#endif // STYLEDTEXTADAPTER_H
