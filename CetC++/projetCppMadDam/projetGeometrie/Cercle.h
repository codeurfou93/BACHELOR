#ifndef CERCLE_H
#define CERCLE_H

#include "Shape.h"

class Cercle : public Shape {
private:
    double rayon;

public:
    Cercle(double r);
    double calculateArea() const override;
    double calculatePerimeter() const override;
};

#endif
