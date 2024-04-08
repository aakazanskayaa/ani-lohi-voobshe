#include "Canvas.h"

int main() {
    Canvas canvas;

    // Prompt user for graphical primitives
    int color;
    std::string shape;
    double x1, y1, x2, y2;

    // Point
    shape = "Point";
    std::cout << "Enter color for " << shape << ": ";
    std::cin >> color;
    canvas.addShape(new Point(10, 10, color, shape));

    // Line
    shape = "Line";
    std::cout << "Enter color for " << shape << ": ";
    std::cin >> color;
    std::cout << "Enter x1, y1, x2, y2: ";
    std::cin >> x1 >> y1 >> x2 >> y2;
    canvas.addShape(new Line(x1, y1, x2, y2, color, shape));

    // Ellipse (unfilled)
    shape = "Ellipse";
    std::cout << "Enter color for " << shape << " (unfilled): ";
    std::cin >> color;
    std::cout << "Enter x1, y1, x2, y2: ";
    std::cin >> x1 >> y1 >> x2 >> y2;
    canvas.addShape(new Ellipse(x1, y1, x2, y2, color, false, shape));

    // Ellipse (filled)
    std::cout << "Enter color for " << shape << " (filled): ";
    std::cin >> color;
    canvas.addShape(new Ellipse(x1, y1, x2, y2, color, true, shape));

    // Rectangle (unfilled)
    shape = "Rectangle";
    std::cout << "Enter color for " << shape << " (unfilled): ";
    std::cin >> color;
    std::cout << "Enter x1, y1, x2, y2: ";
    std::cin >> x1 >> y1 >> x2 >> y2;
    canvas.addShape(new Rectangle(x1, y1, x2, y2, color, false, shape));

    // Rectangle (filled)
    std::cout << "Enter color for " << shape << " (filled): ";
    std::cin >> color;
    canvas.addShape(new Rectangle(x1, y1, x2, y2, color, true, shape));

    // Polygon (unfilled)
    shape = "Polygon";
    std::cout << "Enter color for " << shape << " (unfilled): ";
    std::cin >> color;
    std::cout << "Enter x and y coordinates of vertices (enter a negative number to stop): ";
    std::vector<double> x, y;
    double coord;
    while (std::cin >> coord && coord >= 0) {
        x.push_back(coord);
        std::cin >> coord;
        y.push_back(coord);
    }
    canvas.addShape(new Polygon(x, y, color, false, shape));

    // Polygon (filled)
    std::cout << "Enter color for " << shape << " (filled): ";
    std::cin >> color;
    canvas.addShape(new Polygon(x, y, color, true, shape));

    // Display the canvas
    canvas.show();

    return 0;
}