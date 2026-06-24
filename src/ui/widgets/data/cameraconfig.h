#ifndef CAMERACONFIG_H
#define CAMERACONFIG_H

#include "data.h"

class CameraConfig : public Data
{
    float cameraPitch;
    int cameraPowerMw;

    static constexpr int minPower = 25;
    static constexpr int maxPower = 1000;
    static constexpr float minPitch = -90;
    static constexpr float maxPitch = 30;

    static float normalizePitch(float cameraPitch);
    static int normalizePowerMw(int cameraPowerMw);

public:
    CameraConfig(float cameraPitch, int cameraPowerMw);

    float getCameraPitch() const;
    void setCameraPitch(float newCameraPitch);

    int getCameraPowerMw() const;
    void setCameraPowerMw(int newCameraPowerMw);
};

#endif // CAMERACONFIG_H
