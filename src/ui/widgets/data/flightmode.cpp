#include "flightmode.h"

ControlMode FlightMode::getMode() const
{
    return this->mode;
}

void FlightMode::setMode(ControlMode newMode)
{
    this->mode = newMode;
}

FlightMode::FlightMode(ControlMode mode)
    : Data(), mode(mode)
{}
