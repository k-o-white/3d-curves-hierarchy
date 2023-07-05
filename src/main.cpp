#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <omp.h>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"


inline double t = M_PI_4;

enum curves {CIRCLE = 1, ELLIPSE, HELIX};

double randDouble(double min, double max)
{
    return min + static_cast<double>(std::rand()) / (RAND_MAX / (max - min));
}

void fillCurvesContainer(std::vector<std::shared_ptr<Curve>> &curves)
{
    uint8_t count = std::rand() % 20 + 1;
    for (int i = 0; i < count; ++i)
    {
        uint8_t curveId = std::rand() % 3 + 1;
        switch (curveId)
        {
            case CIRCLE:
            {
                double radius = randDouble(1, 10);
                auto circle = std::make_shared<Circle>(radius);
                curves.emplace_back(circle);
                break;
            }
            case ELLIPSE:
            {
                double rx = randDouble(1, 10);
                double ry = randDouble(1, 10);
                auto ellipse = std::make_shared<Ellipse>(rx, ry);
                curves.emplace_back(ellipse);
                break;
            }
            case HELIX:
            {
                double radius = randDouble(1, 10);
                double step = randDouble(1, 10);
                auto helix = std::make_shared<Helix>(radius, step);
                curves.emplace_back(helix);
                break;
            }
        }
    }
}

void calculateCoordAndDerivatives(std::vector<std::shared_ptr<Curve>> &curves)
{
    std::cout << "Coordinates and derivatives at t = PI/4:" << std::endl;
    for (const auto &curve : curves)
    {
        auto point3D = curve->getPoint(t);
        auto derivative = curve->getDerivative(t);
        std::cout << std::endl;
        std::cout << "Point: " << point3D.x << ", " << point3D.y << ", " << point3D.z << "." << std::endl;
        std::cout << "Derivative: " << derivative.x << ", " << derivative.y << ", " << derivative.z << "." << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::srand(time(nullptr));
    std::vector<std::shared_ptr<Curve>> curvesPointers;
    fillCurvesContainer(curvesPointers);
    calculateCoordAndDerivatives(curvesPointers);
    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto& curve : curvesPointers)
    {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve))
            circles.emplace_back(circle);
    }
    std::sort(circles.begin(), circles.end(), [](const std::shared_ptr<Circle> &a,
                                                                const std::shared_ptr<Circle> &b)
    {
        return a->getRadius() < b->getRadius();
    });
    double sumOfRadii = 0;
#pragma omp parallel for reduction(+:sumOfRadii)
    for (const auto &circle : circles)
    {
        sumOfRadii += circle->getRadius();
    }
    std::cout << "Sum of radii of circles: " << sumOfRadii << "." << std::endl;
    return 0;
}
