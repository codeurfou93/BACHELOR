#include "Cercle.h"
#include <cmath>

Cercle::Cercle(double r) : rayon(r) {}

double Cercle::calculateArea() const {
    return M_PI * rayon * rayon;
}

double Cercle::calculatePerimeter() const {
    return 2 * M_PI * rayon;
}
