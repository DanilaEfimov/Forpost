#ifndef STYLEDTEXT_H
#define STYLEDTEXT_H

#include <QColor>
#include <QVector>
#include <QTextCharFormat>

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
    int fontSize = 14;
    TextStyleFlags format = TextStyleFlag::None;
    QColor color = Qt::black;

    void applyFlags(QTextCharFormat& format) const;

public:
    StyleSpan(int len, QColor color);
    StyleSpan(int len);

    bool operator==(const StyleSpan& style) const;

    int getLength() const;
    void setLength(int newLength);

    QColor getColor() const;
    void setColor(const QColor &newColor);

    TextStyleFlags getFormat() const;
    void setFormat(TextStyleFlag newFormat);

    QTextCharFormat toFormat() const;
    void resetFormat();

    int getFontSize() const;
    void setFontSize(int newFontSize);
};

class StyledText {
    QString text;
    QVector<StyleSpan> style;

public:
    StyledText(const QString& text, QColor color);
    StyledText(const QString& text);

    void setStyle(qsizetype pos, StyleSpan style);

    const QString& getText() const;
    const QVector<StyleSpan>& getSpans() const;
    QVector<StyleSpan>& getSpans();

    qsizetype findIntersectionIdx(qsizetype pos) const;
    qsizetype findStartOfSpan(qsizetype idx) const;
};

#endif // STYLEDTEXT_H
