#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include "ManageArray.h"

int main(){
    //PART 1: ARRAY
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    int* arr = createArray(size);
    if (arr == nullptr) {
        std::cout << "Invalid size. Exiting Part 1.\n";
    } else {
        initializeArray(arr, size);

        std::cout << "Array contents: ";
        printArray(arr, size);

        deleteArray(arr);
    }    
    
    //PART 2: GEOMETRY
    // Initialize base tracking structures
    Point nodeA(0, 0, 0);
    Point nodeB(6, 0, 0);
    Point nodeC(0, 8, 0);

    std::cout << "=== Constructing Vector Mesh ===" << std::endl;
    Triangle mesh(nodeA, nodeB, nodeC);
    mesh.display();
    std::cout << "Calculated Geometric Area: " << mesh.calcArea() << " units^2\n" << std::endl;

    std::cout << "=== Applying Linear Translation Translation Matrix (Y + 12) ===" << std::endl;
    if (mesh.translate(12, 'y') == 0) {
        std::cout << "Matrix translation sequence verified." << std::endl;
    }
    mesh.display();
    std::cout << "Post-Translation Calculated Geometric Area: " << mesh.calcArea() << " units^2\n" << std::endl;

    std::cout << "=== Testing Boundary Failures ===" << std::endl;
    if (mesh.translate(4, 'w') == -1) {
        std::cout << "Erroneous structural axis parameter caught cleanly by intercept logic." << std::endl;
    }

    return 0;
}