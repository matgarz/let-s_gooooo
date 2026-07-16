#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
private:
    /*The triangle stores its three vertices as pointers. 
    Using pointers allows the Triangle to reference existing Point objects without creating internal copies. 
    This keeps memory usage low and ensures that translations modify the actual Point instances rather than temporary duplicates.*/
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;

    // Internal structural helper for Heron's calculations
    // Parameters are passed as const pointers to avoid copying and to guarantee that the function does not modify the original Points.
    double getSideLength(const Point* p1, const Point* p2) const;

public:
    // Default Constructor
    // Default constructor initializes pointers to null.
    Triangle();

    // Overloaded Constructor linking incoming Points by pointer
    // References ensure the caller must pass valid Point objects, and the Triangle stores pointers to those same objects.
    Triangle(Point& p1, Point& p2, Point& p3);
    
    ~Triangle();
    
    // Operations
    int translate(int d, char axis);
    double calcArea() const;
    void display() const;
};


#endif // TRIANGLE_H