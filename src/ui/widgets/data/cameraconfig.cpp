#include "cameraconfig.h"

#include <cmath>

float CameraConfig::getCameraPitch() const
{
    return cameraPitch;
}

void CameraConfig::setCameraPitch(float newCameraPitch)
{
    cameraPitch = newCameraPitch;
}

int CameraConfig::getCameraPowerMw() const
{
    return cameraPowerMw;
}

void CameraConfig::setCameraPowerMw(int newCameraPowerMw)
{
    cameraPowerMw = newCameraPowerMw;
}

float CameraConfig::normalizePitch(float cameraPitch)
{
    float angle = std::fmod(cameraPitch, 360.f);

    if(angle > 180.f)
        angle -= 360.f;

    if(angle < -180.f)
        angle += 360.f;

    angle = std::min(angle, CameraConfig::maxPitch);
    angle = std::max(angle, CameraConfig::minPitch);

    return angle;
}

int CameraConfig::normalizePowerMw(int cameraPowerMw)
{
    int power = std::min(cameraPowerMw, CameraConfig::maxPower);
    power = std::max(power, CameraConfig::minPower);

    return power;
}

CameraConfig::CameraConfig(float cameraPitch, int cameraPowerMw)
    : Data(),
    cameraPitch(CameraConfig::normalizePitch(cameraPitch)),
    cameraPowerMw(CameraConfig::normalizePowerMw(cameraPowerMw))
{}
