#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include "Point.h"

class Line : public Shape {
private:
    Point start, end;
public:
    Line(int startX, int startY, int endX, int endY);
    void print() const override;
};

#endif