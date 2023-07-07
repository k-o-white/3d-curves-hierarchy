#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <omp.h>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

inline const double t = M_PI_4;

enum curves {CIRCLE = 1, ELLIPSE, HELIX};

double randDouble(double min, double max)
{
    return min + static_cast<double>(std::rand()) / (RAND_MAX / (max - min));
}

void fillCurvesContainer(std::vector<std::shared_ptr<Curve>> &curves)
{
    uint8_t count = 10 + std::rand() % 11;
    for (int i = 0; i < count; ++i)
    {
        uint8_t curveId = 1 + std::rand() % 3;
        switch (curveId)
        {
            case CIRCLE:
            {
                double radius = randDouble(1.0, 10.0);
                auto circle = std::make_shared<Circle>(radius);
                curves.emplace_back(circle);
                break;
            }
            case ELLIPSE:
            {
                double rx = randDouble(1.0, 10.0);
                double ry = randDouble(1.0, 10.0);
                auto ellipse = std::make_shared<Ellipse>(rx, ry);
                curves.emplace_back(ellipse);
                break;
            }
            case HELIX:
            {
                double radius = randDouble(1.0, 10.0);
                double step = randDouble(1.0, 10.0);
                auto helix = std::make_shared<Helix>(radius, step);
                curves.emplace_back(helix);
                break;
            }
        }
    }
}

void calculate3DPointsAndDerivatives(std::vector<std::shared_ptr<Curve>> &curves)
{
    std::cout << "3D points and derivatives at t = PI/4:" << std::endl;
    for (const auto &curve : curves)
    {
        auto point3D = curve->get3DPoint(t);
        auto derivative = curve->getDerivative(t);
        std::cout << std::endl;
        std::cout << "Point: " << point3D.x << ", " << point3D.y << ", " << point3D.z << "." << std::endl;
        std::cout << "Derivative: " << derivative.x << ", " << derivative.y << ", " << derivative.z << "." << std::endl;
    }
    std::cout << std::endl;
}

double calculateSumOfRadii(std::vector<std::shared_ptr<Circle>> &circles)
{
    double result = 0;
    #pragma omp parallel for default(none) reduction(+:result) shared(circles)
    for (const auto &circle : circles)
    {
        result += circle->getRadius();
    }
    return result;
}

int main()
{
    std::srand(time(nullptr));
    std::vector<std::shared_ptr<Curve>> curvesPointers;
    fillCurvesContainer(curvesPointers);
    calculate3DPointsAndDerivatives(curvesPointers);
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
    double sumOfRadii = calculateSumOfRadii(circles);

    std::cout << "Sum of radii of circles: " << sumOfRadii << "." << std::endl;
    return 0;
}
