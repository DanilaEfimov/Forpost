#ifndef NOISETEXTEFFECT_H
#define NOISETEXTEFFECT_H

#include "textcolorschemeeffect.h"

enum class NoiseMode : quint8 {
    None    = 0,
    Color   = 1 << 0,
    Size    = 1 << 1,
    Formats = 1 << 2,
};

Q_DECLARE_FLAGS(NoiseModes, NoiseMode);
Q_DECLARE_OPERATORS_FOR_FLAGS(NoiseModes);

class NoiseTextEffect : public TextColorSchemeEffect
{
    NoiseModes modes;

    static StyleSpan splitSpan(StyleSpan& span);
    static QColor randomColor();

public:
    NoiseTextEffect();

    void addNoiseFlag(NoiseMode mode);
    void resetFlags();

    NoiseModes getFlags() const;

    static StyledText& noiseSplit(StyledText& text);
    static StyledText& noiseColor(StyledText& text);
    static StyledText& noiseSize(StyledText& text);
    static StyledText& noiseFormats(StyledText& text);

    StyledText apply(const QString &line) override;
};

#endif // NOISETEXTEFFECT_H
