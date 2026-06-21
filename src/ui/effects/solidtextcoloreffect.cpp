#include "solidtextcoloreffect.h"

TextColorSchemeEffect::TextColorSchemeEffect()
{}

SolidTextColorEffect::SolidTextColorEffect(MessageType source, ColorScheme &&scheme)
    : source(source), scheme(std::move(scheme))
{}

SolidTextColorEffect::SolidTextColorEffect(MessageType source, const ColorScheme &scheme)
    : source(source), scheme(scheme)
{}

QColor SolidTextColorEffect::Color(MessageType source) const
{
    return this->scheme.getColor(source);
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
