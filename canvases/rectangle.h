#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape {
private:
    Point topLeft, bottomRight;
    bool filled;
public:
    Rectangle(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY, bool filled);
    void print() const override;
};

#endif