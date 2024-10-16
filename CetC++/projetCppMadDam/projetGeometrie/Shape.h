#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual ~Shape() {}
};

#endif
