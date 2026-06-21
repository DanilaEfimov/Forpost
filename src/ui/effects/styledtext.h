#ifndef STYLEDTEXT_H
#define STYLEDTEXT_H

#include <QColor>
#include <QVector>

enum class TextStyleFlag : quint32 {
    None        = 0,
    Underline   = 1 << 1,
    Italic      = 1 << 2,
    Bold        = 1 << 3,
};

Q_DECLARE_FLAGS(TextStyleFlags, TextStyleFlag);
Q_DECLARE_OPERATORS_FOR_FLAGS(TextStyleFlags);

class StyleSpan {
    int length;
    TextStyleFlag format;
    QColor color = Qt::black;

public:
    StyleSpan(int len, QColor color);
    StyleSpan(int len);

    bool operator==(const StyleSpan& style) const;

    int getLength() const;
    void setLength(int newLength);

    QColor getColor() const;
    void setColor(const QColor &newColor);
    TextStyleFlag getFormat() const;
    void setFormat(TextStyleFlag newFormat);
};

class StyledText {
    QString text;
    QVector<StyleSpan> style;

public:
    StyledText(const QString& text, QColor color);
    StyledText(const QString& text);

    void setStyle(qsizetype pos, StyleSpan style);

    qsizetype findIntersectionIdx(qsizetype pos) const;
    qsizetype findStartOfSpan(qsizetype idx) const;
};

#endif // STYLEDTEXT_H
