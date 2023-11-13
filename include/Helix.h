//
// Created by teena on 05.07.2023.
//

#pragma once
#include "Curve.h"


class Helix : public Curve
{
private:
    double radius;
    double step;
public:
    Helix(double _radius, double _step) : radius(_radius), step(_step) {};

    Vector3D get3DPoint(double t) const override;

    Vector3D getDerivative(double t) const override;
};