#include "Canvas.h"
#include "Point.h"
#include "Line.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Polygon.h"

Canvas::~Canvas() {
    for (Shape* shape : shapes) {
        delete shape;
    }
}

void Canvas::addShape(Shape* shape) {
    shapes.push_back(shape);
}

void Canvas::removeShape(Shape* shape) {
    shapes.erase(std::remove(shapes.begin(), shapes.end(), shape), shapes.end());
    delete shape;
}

void Canvas::clear() {
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();
}

void Canvas::printShapes() const {
    for (const Shape* shape : shapes) {
        shape->print();
    }
}

void Canvas::show() const {
    // Implement the Show method here
}