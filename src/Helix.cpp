//
// Created by teena on 05.07.2023.
//

#include "Helix.h"

Vector3D Helix::get3DPoint(double t) const
{
    double x = this->radius * std::cos(t);
    double y = this->radius * std::sin(t);
    double z = this->step * t / (2 * M_PI);
    return Vector3D{x, y, z};
}

Vector3D Helix::getDerivative(double t) const
{
    double dx_dt = -this->radius * std::sin(t);
    double dy_dt = this->radius * std::cos(t);
    double dz_dt = this->step / (2 * M_PI);
    return Vector3D{dx_dt, dy_dt, dz_dt};
}