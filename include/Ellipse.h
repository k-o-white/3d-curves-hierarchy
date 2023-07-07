//
// Created by teena on 05.07.2023.
//

#pragma once
#include "Curve.h"

class Ellipse : virtual public Curve
{
private:
    double radiusX;
    double radiusY;
public:
    Ellipse(double _radiusX, double _radiusY) : radiusX(_radiusX), radiusY(_radiusY) {};

    Vector3D get3DPoint(double t) const override;

    Vector3D getDerivative(double t) const override;
};
