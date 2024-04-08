#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual ~Shape() {}
    virtual void print() const = 0;
};

#endif