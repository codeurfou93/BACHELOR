#include "Triangle.h"
#include <cmath>

Triangle::Triangle(double c1, double c2, double c3) : cote1(c1), cote2(c2), cote3(c3) {}

double Triangle::calculateArea() const {
    double s = calculatePerimeter() / 2;
    return std::sqrt(s * (s - cote1) * (s - cote2) * (s - cote3));
}

double Triangle::calculatePerimeter() const {
    return cote1 + cote2 + cote3;
}
