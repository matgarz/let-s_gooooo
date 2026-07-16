#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x, y, z;

public:
    // Constructor with default values
    Point(int xVal = 0, int yVal = 0, int zVal = 0);
    ~Point();
    // Const getters
    int getX() const;
    int getY() const;
    int getZ() const;

    // Mutator / Translation
    int translate(int d, char axis);

    // Display utility
    void display() const;
    
};

#endif // POINT_H