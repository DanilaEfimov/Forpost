#include "eulerangles.h"

#include <cmath>

float EulerAngles::getPitch() const
{
    return this->pitch;
}

void EulerAngles::setPitch(float newPitch)
{
    this->pitch = newPitch;
}

float EulerAngles::getRoll() const
{
    return this->roll;
}

void EulerAngles::setRoll(float newRoll)
{
    this->roll = newRoll;
}

float EulerAngles::getYaw() const
{
    return this->yaw;
}

void EulerAngles::setYaw(float newYaw)
{
    this->yaw = newYaw;
}

float EulerAngles::normalizePitch(float pitch)
{
    float angle = std::fmod(pitch, 360.f);

    if(angle > EulerAngles::maxPitch)
        angle -= 360.f;

    if(angle < EulerAngles::minPitch)
        angle += 360.f;

    return angle;
}

float EulerAngles::normalizeRoll(float roll)
{
    return EulerAngles::normalizePitch(roll);
}

float EulerAngles::normalizeYaw(float yaw)
{
    return EulerAngles::normalizePitch(yaw);
}

EulerAngles::EulerAngles(float pitch, float roll, float yaw)
    : Data(),
    pitch(EulerAngles::normalizePitch(pitch)),
    roll(EulerAngles::normalizeRoll(roll)),
    yaw(EulerAngles::normalizeYaw(yaw))
{}
