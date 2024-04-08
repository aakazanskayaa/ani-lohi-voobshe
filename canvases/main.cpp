#include <iostream>
#include "Canvas.h"
#include "Point.h"
#include "Line.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Polygon.h"
using namespace std;

int main() {
    Canvas canvas;

    int x, y;
    char shape;
    bool filled;

    while (true) {
        cout << "Enter shape type (P, L, E, R, H): ";
        cin >> shape;

        switch (shape) {
            case 'P':
                cout << "Enter x, y: ";
                cin >> x >> y;
                canvas.addShape(new Point(x, y));
                break;
            case 'L':
                cout << "Enter start x, start y, end x, end y: ";
                cin >> x >> y;
                int ex, ey;
                cin >> ex >> ey;
                canvas.addShape(new Line(x, y, ex, ey));
                break;
            case 'E':
                cout << "Enter top left x, top left y, bottom right x, bottom right y, filled (1/0): ";
                cin >> x >> y;
                int bx, by;
                cin >> bx >> by;
                cin >> filled;
                canvas.addShape(new Ellipse(x, y, bx, by, filled));
                break;
            case 'R':
                cout << "Enter top left x, top left y, bottom right x, bottom right y, filled (1/0): ";
                cin >> x >> y;
                cin >> bx >> by;
                cin >> filled;
                canvas.addShape(new Rectangle(x, y, bx, by, filled));
                break;
            case 'H':
                cout << "Enter number of points: ";
                int n;
                cin >> n;
                vector<Point> points(n);
                for (int i = 0; i < n; i++) {
                    cin >> x >> y;
                    points[i] = Point(x, y);
                }
                cin >> filled;
                canvas.addShape(new Polygon(points, filled));
                break;
            default:
    cout << "Invalid shape type. Please try again.\n";
    break;
        }

        cout << "Shape added. Press any key to continue, 'q' to quit.\n";
        char c;
        cin >> c;
        if (c == 'q') {
            goto exit;
        }

        cout << "Current shapes:\n";
        canvas.printShapes();
        cout << "\n";
    }

exit:
    return 0;
}