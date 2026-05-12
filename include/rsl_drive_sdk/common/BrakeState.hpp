#pragma once
#include <ostream>
namespace rsl_drive_sdk
{
    enum class BrakeState
    {
        Engaged = 0,
        Excited = 1,
        Holding = 2
    };
    inline std::ostream &operator<<(std::ostream &os, BrakeState state)
    {
        switch (state)
        {
        case BrakeState::Engaged:
            return os << "Engaged";

        case BrakeState::Excited:
            return os << "Excited";

        case BrakeState::Holding:
            return os << "Holding";

        default:
            return os << "Unknown";
        }
    }
}