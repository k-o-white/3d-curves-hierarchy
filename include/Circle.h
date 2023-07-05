//
// Created by teena on 05.07.2023.
//

#pragma once
#include <cmath>
#include "Curve.h"

class Circle : virtual public Curve
{
private:
    double radius;
public:
    explicit Circle(double _radius) : radius(_radius) {}

    ~Circle() = default;

    double getRadius() const;

    Point3D getPoint(double t) const override;

    Vector3D getDerivative(double t) const override;
};