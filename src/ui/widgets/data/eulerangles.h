#ifndef EULERANGLES_H
#define EULERANGLES_H

#include "data.h"

class EulerAngles : public Data
{
    float pitch;
    float roll;
    float yaw;

    static constexpr float maxPitch = 180;
    static constexpr float minPitch = -180;

    static float normalizePitch(float pitch);
    static float normalizeRoll(float roll);
    static float normalizeYaw(float yaw);

public:
    EulerAngles(float pitch = 0.0f, float roll = 0.0f, float yaw = 0.0f);

    float getPitch() const;
    void setPitch(float newPitch);

    float getRoll() const;
    void setRoll(float newRoll);

    float getYaw() const;
    void setYaw(float newYaw);
};

#endif // EULERANGLES_H
