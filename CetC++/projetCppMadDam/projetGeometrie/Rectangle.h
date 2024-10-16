#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double largeur;
    double hauteur;

public:
    Rectangle(double l, double h);
    double calculateArea() const override;
    double calculatePerimeter() const override;
};

#endif
