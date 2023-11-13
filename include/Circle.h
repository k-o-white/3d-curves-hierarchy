//
// Created by teena on 05.07.2023.
//

#pragma once
#include "Curve.h"

class Circle : public Curve
{
private:
    double radius;
public:
    explicit Circle(double _radius) : radius(_radius) {}

    double getRadius() const;

    Vector3D get3DPoint(double t) const override;

    Vector3D getDerivative(double t) const override;
};