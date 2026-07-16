#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : vertex_1(nullptr), vertex_2(nullptr), vertex_3(nullptr) {}

Triangle::Triangle(Point& p1, Point& p2, Point& p3) 
    : vertex_1(&p1), vertex_2(&p2), vertex_3(&p3) {}

Triangle::~Triangle() {
    // Safely clear the pointer relationships without deleting the external Points
    vertex_1 = nullptr;
    vertex_2 = nullptr;
    vertex_3 = nullptr;
    std::cout << "Triangle destroyed (vertices safely unlinked)." << std::endl;
}

int Triangle::translate(int d, char axis) {
    // Structural pointer safety check
    if (!vertex_1 || !vertex_2 || !vertex_3) {
        std::cerr << "Execution Warning: Attempted operation on null-pointer vertices." << std::endl;
        return -1;
    }

    // Try translating structural pivot vertex_1 to check argument axis validity
    int validationCode = vertex_1->translate(d, axis);
    if (validationCode == -1) {
        return -1; // Abort operation sequence if code invalid
    }

    // Process remaining shifts safely
    vertex_2->translate(d, axis);
    vertex_3->translate(d, axis);
    return 0;
}

double Triangle::getSideLength(const Point* p1, const Point* p2) const {
    double deltaX = p1->getX() - p2->getX();
    double deltaY = p1->getY() - p2->getY();
    double deltaZ = p1->getZ() - p2->getZ();
    return std::sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
}

double Triangle::calcArea() const {
    if (!vertex_1 || !vertex_2 || !vertex_3) {
        return 0.0;
    }

    double a = getSideLength(vertex_1, vertex_2);
    double b = getSideLength(vertex_2, vertex_3);
    double c = getSideLength(vertex_3, vertex_1);

    double semiPerimeter = (a + b + c) / 2.0;
    return std::sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
}

void Triangle::display() const {
    if (!vertex_1 || !vertex_2 || !vertex_3) {
        std::cout << "[Uninitialized Triangle Structure]" << std::endl;
        return;
    }
    std::cout << "Triangle [ ";
    vertex_1->display(); std::cout << " -> ";
    vertex_2->display(); std::cout << " -> ";
    vertex_3->display(); std::cout << " ]" << std::endl;
}