#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "Shape.h"

class Canvas {
private:
    std::vector<Shape*> shapes;
public:
    ~Canvas();
    void addShape(Shape* shape);
    void removeShape(Shape* shape);
    void clear();
    void printShapes() const;
    void show() const;
};

#endif