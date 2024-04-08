#ifndef POLYGON_H
#define POLYGON_H
using namespace std;
#include <vector>

#include "Shape.h"
#include "Point.h"

class Polygon : public Shape {
private:
    vector<Point> points;
    bool filled;
public:
    Polygon(const vector<Point>& points, bool filled);
    void print() const override;
};

#endif