#include "solidtextcoloreffect.h"

using Pair = ColorScheme::Pair;
static const ColorScheme defaultScheme(ColorScheme::Scheme{
    Pair{MessageType::Error, Qt::red},
    Pair{MessageType::Warning, Qt::yellow},
    Pair{MessageType::Info, Qt::green},
    Pair{MessageType::Operator, Qt::cyan}
});

SolidTextColorEffect::SolidTextColorEffect()
    : source(MessageType::Operator), scheme(defaultScheme)
{}

SolidTextColorEffect::SolidTextColorEffect(MessageType source)
    : source(source), scheme(defaultScheme)
{}

SolidTextColorEffect::SolidTextColorEffect(MessageType source, ColorScheme &&scheme)
    : source(source), scheme(std::move(scheme))
{}

SolidTextColorEffect::SolidTextColorEffect(MessageType source, const ColorScheme &scheme)
    : source(source), scheme(scheme)
{}

QColor SolidTextColorEffect::Color() const
{
    return this->scheme.getColor(this->source);
}

void SolidTextColorEffect::setSource(MessageType source)
{
    this->source = source;
}

MessageType SolidTextColorEffect::getSource() const
{
    return this->source;
}

StyledText SolidTextColorEffect::apply(const QString &line)
{
    return StyledText(line, this->scheme.getColor(this->source));
}

ColorScheme::ColorScheme(const QMap<MessageType, QColor> &scheme)
    : scheme(scheme)
{}

QColor ColorScheme::getColor(MessageType type) const
{
    if(!this->scheme.contains(type))
        return QColor(ColorScheme::defaultColor);

    return this->scheme[type];
}

void ColorScheme::setColor(MessageType type, QColor color)
{
    this->scheme[type] = color;
}

void ColorScheme::invert()
{
    for(auto& p : this->scheme){
        p = QColor(255 - p.red(), 255 - p.green(), 255 - p.blue(), p.alpha());
    }
}
