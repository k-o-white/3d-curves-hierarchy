//
// Created by teena on 05.07.2023.
//

#include "Circle.h"

Point3D Circle::getPoint(double t) const
{
    double x = this->radius * std::cos(t);
    double y = this->radius * std::sin(t);
    double z = 0.0; // Circle lies in the XoY plane
    return {x, y, z};
}

Vector3D Circle::getDerivative(double t) const
{
    double dx_dt = - this->radius * std::sin(t);
    double dy_dt = this->radius * std::cos(t);
    double dz_dt = 0.0; // Derivative of Z-coordinate is zero
    return {dx_dt, dy_dt, dz_dt};
}

double Circle::getRadius() const
{
    return this->radius;
}
