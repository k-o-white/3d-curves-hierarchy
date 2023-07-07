//
// Created by teena on 05.07.2023.
//

#include <vector>
#include <gtest/gtest.h>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

inline const double t = M_PI_2;

TEST(TestCaseCircle, CircleTest)
{
    Circle circle(2.0);
    Vector3D expectedPoint{0.0, 2.0, 0.0};
    Vector3D expectedDerivative{-2.0, 0.0, 0.0};
    auto resultPoint = circle.get3DPoint(t);
    auto resultDerivative = circle.getDerivative(t);
    EXPECT_NEAR(resultPoint.x, expectedPoint.x, 1e-15);
    EXPECT_NEAR(resultPoint.y, expectedPoint.y, 1e-15);
    EXPECT_NEAR(resultPoint.z, expectedPoint.z, 1e-15);
    EXPECT_NEAR(resultDerivative.x, expectedDerivative.x, 1e-15);
    EXPECT_NEAR(resultDerivative.y, expectedDerivative.y, 1e-15);
    EXPECT_NEAR(resultDerivative.z, expectedDerivative.z, 1e-15);
}

TEST(TestCaseEllipse, EllipseTest)
{
    Ellipse ellipse(3.0, 2.0);
    Vector3D expectedPoint{0.0, 2.0, 0.0};
    Vector3D expectedDerivative{-3.0, 0.0, 0.0};
    auto resultPoint = ellipse.get3DPoint(t);
    auto resultDerivative = ellipse.getDerivative(t);
    EXPECT_NEAR(resultPoint.x, expectedPoint.x, 1e-15);
    EXPECT_NEAR(resultPoint.y, expectedPoint.y, 1e-15);
    EXPECT_NEAR(resultPoint.z, expectedPoint.z, 1e-15);
    EXPECT_NEAR(resultDerivative.x, expectedDerivative.x, 1e-15);
    EXPECT_NEAR(resultDerivative.y, expectedDerivative.y, 1e-15);
    EXPECT_NEAR(resultDerivative.z, expectedDerivative.z, 1e-15);
}

TEST(TestCaseHelix, HelixTest)
{
    Helix helix(2.0, 1.0);
    Vector3D expectedPoint{0.0, 2.0, 0.25};
    Vector3D expectedDerivative{-2.0, 0.0, 0.15915494309189535};
    auto resultPoint = helix.get3DPoint(t);
    auto resultDerivative = helix.getDerivative(t);
    EXPECT_NEAR(resultPoint.x, expectedPoint.x, 1e-15);
    EXPECT_NEAR(resultPoint.y, expectedPoint.y, 1e-15);
    EXPECT_NEAR(resultPoint.z, expectedPoint.z, 1e-15);
    EXPECT_NEAR(resultDerivative.x, expectedDerivative.x, 1e-15);
    EXPECT_NEAR(resultDerivative.y, expectedDerivative.y, 1e-15);
    EXPECT_NEAR(resultDerivative.z, expectedDerivative.z, 1e-15);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}