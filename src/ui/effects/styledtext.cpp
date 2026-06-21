#include "styledtext.h"

qsizetype StyledText::findIntersectionIdx(qsizetype pos) const
{
    qsizetype res = 0;

    for(const auto& span : this->style) {
        if(pos >= res + span.getLength())
            res += span.getLength();
    }

    return res;
}

qsizetype StyledText::findStartOfSpan(qsizetype idx) const
{
    if(idx >= this->style.size())
        throw std::out_of_range(QString(
                                    "StyledText::findStartOfSpan: no such span: %1")
                                    .arg(idx).toStdString()
                                );

    qsizetype res = 0;

    for(qsizetype i = 0; i < idx; i++){
        res += this->style.at(i).getLength();
    }

    return res;
}

StyledText::StyledText(const QString &text, QColor color)
    : text(text), style({StyleSpan(text.length(), color)})
{}

StyledText::StyledText(const QString &text)
    : text(text), style({StyleSpan(text.length())})
{}

void StyledText::setStyle(qsizetype pos, StyleSpan style)
{
    qsizetype spanLen = style.getLength();
    qsizetype from = this->findIntersectionIdx(pos);
    qsizetype to = this->findIntersectionIdx(pos + spanLen);

    if(from < to) return;

    qsizetype startSpanFrom = this->findStartOfSpan(from);
    qsizetype startSpanTo = this->findStartOfSpan(to);

    this->style[from].setLength(pos - startSpanFrom);
    this->style[to].setLength(pos + spanLen - startSpanTo);

    auto it = this->style.cbegin();
    this->style.erase(it + from + 1, it + to);

    this->style.insert(from, style);
}

int StyleSpan::getLength() const
{
    return this->length;
}

void StyleSpan::setLength(int newLength)
{
    this->length = newLength;
}

QColor StyleSpan::getColor() const
{
    return this->color;
}

void StyleSpan::setColor(const QColor &newColor)
{
    this->color = newColor;
}

TextStyleFlag StyleSpan::getFormat() const
{
    return this->format;
}

void StyleSpan::setFormat(TextStyleFlag newFormat)
{
    this->format = newFormat;
}

StyleSpan::StyleSpan(int len, QColor color)
    : length(len), color(color)
{}

StyleSpan::StyleSpan(int len)
    : length(len)
{}
