#include "Rectangle.h"

Rectangle::Rectangle(double l, double h) : largeur(l), hauteur(h) {}

double Rectangle::calculateArea() const {
    return largeur * hauteur;
}

double Rectangle::calculatePerimeter() const {
    return 2 * (largeur + hauteur);
}
