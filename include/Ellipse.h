//
// Created by teena on 05.07.2023.
//

#pragma once
#include <cmath>
#include "Curve.h"

class Ellipse : virtual public Curve
{
private:
    double radiusX;
    double radiusY;
public:
    Ellipse(double _radiusX, double _radiusY) : radiusX(_radiusX), radiusY(_radiusY) {}

    ~Ellipse() = default;

    Point3D getPoint(double t) const override;

    Vector3D getDerivative(double t) const override;
};
