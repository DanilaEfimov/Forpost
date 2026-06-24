#include "noisetexteffect.h"

#include <QRandomGenerator>

StyleSpan NoiseTextEffect::splitSpan(StyleSpan& span)
{
    qsizetype len = span.getLength();
    if(len <= 1)
        return StyleSpan(0);

    qsizetype border = QRandomGenerator::global()->bounded(1, len);
    span.setLength(border);

    return StyleSpan(len - border, span.getColor());
}

QColor NoiseTextEffect::randomColor()
{
    auto* rg = QRandomGenerator::global();

    return QColor(rg->bounded(0,256),
                  rg->bounded(0,256),
                  rg->bounded(0,256));
}

NoiseTextEffect::NoiseTextEffect()
{}

void NoiseTextEffect::addNoiseFlag(NoiseMode mode)
{
    this->modes |= mode;
}

void NoiseTextEffect::resetFlags()
{
    this->modes = NoiseMode::None;
}

NoiseModes NoiseTextEffect::getFlags() const
{
    return this->modes;
}

StyledText& NoiseTextEffect::noiseSplit(StyledText& text)
{
    auto& spans = text.getSpans();

    for(qsizetype i = 0; i < text.getSpans().length(); i++) {
        auto span = spans[i];
        if(span.getLength() <= 1) continue;

        auto& spanRef = span;
        auto splited = NoiseTextEffect::splitSpan(spanRef);

        spans[i] = spanRef;
        spans.insert(i, splited);
    }

    return text;
}

StyledText& NoiseTextEffect::noiseColor(StyledText& text)
{
    auto& spans = text.getSpans();

    for(qsizetype i = 0; i < text.getSpans().length(); i++) {
        spans[i].setColor(NoiseTextEffect::randomColor());
    }

    return text;
}

StyledText& NoiseTextEffect::noiseSize(StyledText& text)
{
    auto& spans = text.getSpans();

    for(qsizetype i = 0; i < text.getSpans().length(); i++) {
        spans[i].setFontSize(QRandomGenerator::global()->bounded(12, 24));
    }

    return text;
}

StyledText& NoiseTextEffect::noiseFormats(StyledText& text)
{
    auto& spans = text.getSpans();
    auto* rg = QRandomGenerator::global();

    for(qsizetype i = 0; i < text.getSpans().length(); i++) {
        auto& span = spans[i];
        TextStyleFlag option = static_cast<TextStyleFlag>(rg->bounded(0,3));

        switch(option){
            case TextStyleFlag::Bold:
                span.setFormat(TextStyleFlag::Bold); continue;
            case TextStyleFlag::Italic:
                span.setFormat(TextStyleFlag::Italic); continue;
            case TextStyleFlag::Underline:
                span.setFormat(TextStyleFlag::Underline); continue;
        default:
            span.setFormat(TextStyleFlag::None); continue;
        }
    }

    return text;
}


StyledText NoiseTextEffect::apply(const QString &line)
{
    StyledText ret(line);

    if(this->modes.testFlag(NoiseMode::None))
        return ret;

    ret = NoiseTextEffect::noiseSplit(ret);
    if(this->modes.testFlag(NoiseMode::Color))
        NoiseTextEffect::noiseColor(ret);
    if(this->modes.testFlag(NoiseMode::Size))
        NoiseTextEffect::noiseSize(ret);
    if(this->modes.testFlag(NoiseMode::Formats))
        NoiseTextEffect::noiseFormats(ret);

    return ret;
}
