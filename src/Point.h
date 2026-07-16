#ifndef POINT_H
#define POINT_H

class Point {
private:
    // Each Point stores its own coordinates.
    // These are simple integer values, so no dynamic memory is needed here
    int x, y, z;

public:
    // Constructor with default values
    // Using default parameters allows flexible creation of Points
    Point(int xVal = 0, int yVal = 0, int zVal = 0);
    
    ~Point();
    
    // Const getters
    int getX() const;
    int getY() const;
    int getZ() const;

    // Mutator / Translation
    // Returns -1 for invalid axis input, enforcing safe usage. return 0 if everything is fine
    int translate(int d, char axis);

    // Display utility
    void display() const;
    
};

#endif // POINT_H