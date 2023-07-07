//
// Created by teena on 05.07.2023.
//

#include "Ellipse.h"

Vector3D Ellipse::get3DPoint(double t) const
{
    double x = this->radiusX * std::cos(t);
    double y = this->radiusY * std::sin(t);
    double z = 0.0; // Ellipse lies in the XoY plane
    return Vector3D{x, y, z};
}

Vector3D Ellipse::getDerivative(double t) const
{
    double dx_dt = -this->radiusX * std::sin(t);
    double dy_dt = this->radiusY * std::cos(t);
    double dz_dt = 0.0; // Derivative of Z-coordinate is zero
    return Vector3D{dx_dt, dy_dt, dz_dt};
}