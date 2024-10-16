#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
private:
    double cote1, cote2, cote3;

public:
    Triangle(double c1, double c2, double c3);
    double calculateArea() const override;
    double calculatePerimeter() const override;
};

#endif
