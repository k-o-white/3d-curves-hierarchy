//
// Created by teena on 05.07.2023.
//

#pragma once
#include <cmath>
#include "Curve.h"


class Helix : virtual public Curve
{
private:
    double radius;
    double step;
public:
    Helix(double _radius, double _step) : radius(_radius), step(_step) {}

    ~Helix() = default;

    Point3D getPoint(double t) const override;

    Vector3D getDerivative(double t) const override;
};