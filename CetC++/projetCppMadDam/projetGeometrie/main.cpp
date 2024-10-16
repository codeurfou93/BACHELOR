#include "Cercle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>

int main() {
    Cercle cercle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Triangle triangle(3.0, 4.0, 5.0);

    std::cout << "Cercle: \n";
    std::cout << "Aire: " << cercle.calculateArea() << "\n";
    std::cout << "Perimetre: " << cercle.calculatePerimeter() << "\n\n";

    std::cout << "Rectangle: \n";
    std::cout << "Aire: " << rectangle.calculateArea() << "\n";
    std::cout << "Perimetre: " << rectangle.calculatePerimeter() << "\n\n";

    std::cout << "Triangle: \n";
    std::cout << "Aire: " << triangle.calculateArea() << "\n";
    std::cout << "Perimetre: " << triangle.calculatePerimeter() << "\n";

    return 0;
}
