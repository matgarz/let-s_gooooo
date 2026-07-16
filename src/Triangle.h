#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
private:
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;

    // Internal structural helper for Heron's calculations
    double getSideLength(const Point* p1, const Point* p2) const;

public:
    // Default Constructor
    Triangle();

    // Overloaded Constructor linking incoming Points by pointer
    Triangle(Point& p1, Point& p2, Point& p3);
    ~Triangle();
    // Operations
    int translate(int d, char axis);
    double calcArea() const;
    void display() const;
};


#endif // TRIANGLE_H