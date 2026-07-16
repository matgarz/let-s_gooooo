#include "Point.h"
#include <iostream>

Point::Point(int xVal, int yVal, int zVal) : x(xVal), y(yVal), z(zVal) {}
Point::~Point() {
    std::cout << "Point ";
    display();
    std::cout << " is being destroyed and memory freed." << std::endl;
}
int Point::getX() const { return x; }
int Point::getY() const { return y; }
int Point::getZ() const { return z; }

int Point::translate(int d, char axis) {
    switch (axis) {
        case 'x': case 'X':
            x += d;
            return 0;
        case 'y': case 'Y':
            y += d;
            return 0;
        case 'z': case 'Z':
            z += d;
            return 0;
        default:
            return -1; // Invalid axis identifier
    }
}

void Point::display() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")";
}