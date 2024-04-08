#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
  public:
    Point(double x, double y, int color, std::string shape_type);
    void draw() const;
    std::string toString() const;
    Point* clone() const;

  private:
    int x, y, color;
};

#endif  // POINT_H