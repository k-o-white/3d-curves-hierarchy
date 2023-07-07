//
// Created by teena on 05.07.2023.
//

#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

struct Vector3D
{
    double x;
    double y;
    double z;
};

class Curve
{
public:
    virtual Vector3D get3DPoint(double t) const = 0;

    virtual Vector3D getDerivative(double t) const = 0;

    virtual ~Curve() = default;
};