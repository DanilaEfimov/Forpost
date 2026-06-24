#ifndef FLIGHTMODE_H
#define FLIGHTMODE_H

#include "data.h"

enum class ControlMode
{
    Manual = 0,
    Autopilot,
};

class FlightMode : public Data
{
    ControlMode mode;

public:
    FlightMode(ControlMode mode);

    ControlMode getMode() const;
    void setMode(ControlMode newMode);
};

#endif // FLIGHTMODE_H
