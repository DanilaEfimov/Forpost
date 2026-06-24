#ifndef SOLIDTEXTCOLOREFFECT_H
#define SOLIDTEXTCOLOREFFECT_H

#include "textcolorschemeeffect.h"
#include "styledtext.h"

#include <QMap>

enum class MessageType : quint8 {
    Info,
    Error,
    Warning,
    Operator,
};

class ColorScheme {
public:
    using Pair = std::pair<MessageType, QColor>;
    using Scheme = QMap<MessageType, QColor>;

private:
    Scheme scheme;

    static constexpr int defaultColor = Qt::black;

public:
    ColorScheme(const QMap<MessageType, QColor>& scheme);

    QColor getColor(MessageType type) const;
    void setColor(MessageType type, QColor color);

    void invert();
};

class SolidTextColorEffect : public TextColorSchemeEffect
{
    MessageType source;
    ColorScheme scheme;

public:
    SolidTextColorEffect();
    SolidTextColorEffect(MessageType source);
    SolidTextColorEffect(MessageType source, ColorScheme&& scheme);
    SolidTextColorEffect(MessageType source, const ColorScheme& scheme);

    QColor Color() const;

    void setSource(MessageType source);
    MessageType getSource() const;

    StyledText apply(const QString &line) override;
};

#endif // SOLIDTEXTCOLOREFFECT_H
