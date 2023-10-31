#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;


TEST(TriangleTests, testPerimeter) { //goint to pass
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

TEST(TriangleTests, testPerimeterWithSidesBeingDifferent) { //goint to fail
    Triangle *aTriangle = new Triangle(3,3,2);
    EXPECT_EQ (aTriangle->getPerimeter(),8);
}

TEST(TriangleTests, testAreaWith333) //goint to pass
{
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_NEAR(aTriangle->getArea(), 3.897, 0.001);
}

TEST(TriangleTests, testAreaWithSidesBeingDifferent) //goint to fail
{
    Triangle *aTriangle = new Triangle(3,3,2);
    EXPECT_NEAR(aTriangle->getArea(), 2.828, 0.001);
}

TEST(TriangleTests, testClassWith333Negative) //goint to pass
{
    
    EXPECT_DEATH(new Triangle(3,3,-3),"Does not satisfy triangle inequality");
}

TEST(TriangleTests, testEquilateral333) //goint to pass
{
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_TRUE(aTriangle->isEquilateral());
}

TEST(TriangleTests, testIsosceles333) //goint to pass
{
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_TRUE(aTriangle->isIsosceles());
}

TEST(TriangleTests, testKindWithDifferentSides) // going to fail
{
    Triangle *aTriangle = new Triangle(4,3,2);
    EXPECT_EQ(Triangle::Kind::SCALENE, aTriangle->getKind());
}

TEST(TriangleTests, testKind333) // going to fail
{
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ(Triangle::Kind::EQUILATERAL, aTriangle->getKind());
}

int runTests(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

