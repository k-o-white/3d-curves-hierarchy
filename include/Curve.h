//
// Created by teena on 05.07.2023.
//

#pragma once

struct Point3D
{
    double x;
    double y;
    double z;
};

struct Vector3D
{
    double x;
    double y;
    double z;
};

class Curve
{
public:
    virtual Point3D getPoint(double t) const = 0;

    virtual Vector3D getDerivative(double t) const = 0;
};