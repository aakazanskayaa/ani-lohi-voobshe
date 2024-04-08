#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
#include "Point.h"

class Ellipse : public Shape {
private:
    Point topLeft, bottomRight;
    bool filled;
public:
    Ellipse(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY, bool filled);
    void print() const override;
};

#endif