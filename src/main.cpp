// main.cpp
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm> // For std::find and std::remove
#include "Point.h"
#include "Triangle.h"
#include "ManageArray.h"

// Helper function to safely read integer input
int getSafeInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        } else {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Helper function to safely read a character input
char getSafeChar(const std::string& prompt) {
    char value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        } else {
            std::cout << "Invalid input. Please enter a single character.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Helper function to remove a Point pointer from our tracking vector
void removePointFromVector(std::vector<Point*>& vec, const Point* target) {
    auto it = std::find(vec.begin(), vec.end(), target);
    if (it != vec.end()) {
        vec.erase(it);
    }
}

void printMenu() {
    std::cout << "\n=========================================\n";
    std::cout << "        GEOMETRY & MEMORY TESTER         \n";
    std::cout << "=========================================\n";
    std::cout << "1. Create New Points & a Triangle\n";
    std::cout << "2. Display All Triangles and Points\n";
    std::cout << "3. Calculate Area of a Triangle\n";
    std::cout << "4. Translate a Triangle\n";
    std::cout << "5. Translate an Individual Point\n";
    std::cout << "6. Test Dynamic Array Management (Heap Memory)\n";
    std::cout << "7. Delete a Triangle (and its Points)\n";
    std::cout << "0. Exit Program\n";
    std::cout << "-----------------------------------------\n";
}

int main() {
    // Dynamic storage using vectors of pointers to ensure elements 
    // never move in memory (preventing dangling pointer issues in Triangle)
    std::vector<Point*> allPoints;
    std::vector<Triangle*> allTriangles;
    
    // Dynamic Array tracking variables
    int* myDynamicArray = nullptr;
    int arraySize = 0;

    int choice = -1;
    do {
        printMenu();
        choice = getSafeInt("Enter your choice (0-7): ");
        std::cout << "\n--- Execution Output ---\n";

        switch (choice) {
            case 1: {
                std::cout << "Let's define 3 custom Points to form your Triangle.\n";
                
                int x, y, z;
                std::cout << "\n[Point 1]\n";
                x = getSafeInt("  Enter X: "); y = getSafeInt("  Enter Y: "); z = getSafeInt("  Enter Z: ");
                Point* p1 = new Point(x, y, z);

                std::cout << "\n[Point 2]\n";
                x = getSafeInt("  Enter X: "); y = getSafeInt("  Enter Y: "); z = getSafeInt("  Enter Z: ");
                Point* p2 = new Point(x, y, z);

                std::cout << "\n[Point 3]\n";
                x = getSafeInt("  Enter X: "); y = getSafeInt("  Enter Y: "); z = getSafeInt("  Enter Z: ");
                Point* p3 = new Point(x, y, z);

                // Save individual points to our global list
                allPoints.push_back(p1);
                allPoints.push_back(p2);
                allPoints.push_back(p3);

                // Initialize the Triangle on the heap using our newly allocated points
                Triangle* newTriangle = new Triangle(*p1, *p2, *p3);
                allTriangles.push_back(newTriangle);

                std::cout << "\nSUCCESS: Triangle " << allTriangles.size() - 1 << " successfully created!\n";
                break;
            }
            case 2:
                std::cout << "=== ALL REGISTERED POINTS ===\n";
                if (allPoints.empty()) {
                    std::cout << "(No points created yet)\n";
                } else {
                    for (size_t i = 0; i < allPoints.size(); ++i) {
                        std::cout << "  Point [" << i << "]: ";
                        allPoints[i]->display();
                        std::cout << "\n";
                    }
                }

                std::cout << "\n=== ALL REGISTERED TRIANGLES ===\n";
                if (allTriangles.empty()) {
                    std::cout << "(No triangles created yet)\n";
                } else {
                    for (size_t i = 0; i < allTriangles.size(); ++i) {
                        std::cout << "  Triangle [" << i << "]: ";
                        allTriangles[i]->display();
                    }
                }
                break;

            case 3: {
                if (allTriangles.empty()) {
                    std::cout << "No Triangles exist yet. Use Option 1 first.\n";
                    break;
                }
                std::cout << "Available Triangles:\n";
                for (size_t i = 0; i < allTriangles.size(); ++i) {
                    std::cout << "  [" << i << "] ";
                    allTriangles[i]->display();
                }
                int index = getSafeInt("Select a Triangle index to calculate its area: ");
                if (index >= 0 && index < static_cast<int>(allTriangles.size())) {
                    double area = allTriangles[index]->calcArea();
                    std::cout << "Calculated Area: " << area << " square units.\n";
                } else {
                    std::cout << "Invalid index choice.\n";
                }
                break;
            }

            case 4: {
                if (allTriangles.empty()) {
                    std::cout << "No Triangles exist yet. Use Option 1 first.\n";
                    break;
                }
                std::cout << "Available Triangles:\n";
                for (size_t i = 0; i < allTriangles.size(); ++i) {
                    std::cout << "  [" << i << "] ";
                    allTriangles[i]->display();
                }
                int index = getSafeInt("Select a Triangle index to translate: ");
                if (index >= 0 && index < static_cast<int>(allTriangles.size())) {
                    char axis = getSafeChar("Enter translation axis (X/Y/Z): ");
                    int distance = getSafeInt("Enter translation distance: ");
                    
                    int result = allTriangles[index]->translate(distance, axis);
                    if (result == 0) {
                        std::cout << "SUCCESS: Triangle translated successfully.\n";
                    } else {
                        std::cout << "FAILURE: Invalid axis.\n";
                    }
                } else {
                    std::cout << "Invalid index choice.\n";
                }
                break;
            }
            case 5: {
                if (allPoints.empty()) {
                    std::cout << "No individual Points exist yet. Create a triangle first.\n";
                    break;
                }
                std::cout << "Available Points:\n";
                for (size_t i = 0; i < allPoints.size(); ++i) {
                    std::cout << "  [" << i << "] ";
                    allPoints[i]->display();
                    std::cout << "\n";
                }
                int index = getSafeInt("Select Point index to translate: ");
                if (index >= 0 && index < static_cast<int>(allPoints.size())) {
                    char axis = getSafeChar("Enter translation axis (X/Y/Z): ");
                    int distance = getSafeInt("Enter translation distance: ");
                    
                    int result = allPoints[index]->translate(distance, axis);
                    if (result == 0) {
                        std::cout << "SUCCESS: Point [" << index << "] updated.\n";
                    } else {
                        std::cout << "FAILURE: Invalid axis.\n";
                    }
                } else {
                    std::cout << "Invalid index choice.\n";
                }
                break;
            }
            case 6: {
                std::cout << "--- Dynamic Array Sub-Menu ---\n";
                std::cout << "1. Create and Initialize Dynamic Array\n";
                std::cout << "2. Print Current Dynamic Array\n";
                std::cout << "3. Safely Delete Dynamic Array\n";
                
                int subChoice = getSafeInt("Enter array option (1-3): ");
                
                if (subChoice == 1) {
                    if (myDynamicArray != nullptr) {
                        deleteArray(myDynamicArray);
                        myDynamicArray = nullptr;
                    }
                    arraySize = getSafeInt("Enter desired array size: ");
                    myDynamicArray = createArray(arraySize);
                    if (myDynamicArray == nullptr) {
                        std::cout << "Error: Invalid array size chosen.\n";
                    } else {
                        initializeArray(myDynamicArray, arraySize);
                        std::cout << "SUCCESS: Array of size " << arraySize << " created.\n";
                    }
                } 
                else if (subChoice == 2) {
                    printArray(myDynamicArray, arraySize);
                } 
                else if (subChoice == 3) {
                    if (myDynamicArray == nullptr) {
                        std::cout << "No array exists to delete.\n";
                    } else {
                        deleteArray(myDynamicArray);
                        myDynamicArray = nullptr;
                        std::cout << "SUCCESS: Heap-allocated array freed safely.\n";
                    }
                } 
                break;
            }
            case 7: {
                if (allTriangles.empty()) {
                    std::cout << "No Triangles exist to delete.\n";
                    break;
                }

                std::cout << "Available Triangles:\n";
                for (size_t i = 0; i < allTriangles.size(); ++i) {
                    std::cout << "  [" << i << "] ";
                    allTriangles[i]->display();
                }

                int index = getSafeInt("Select a Triangle index to delete: ");
                if (index >= 0 && index < static_cast<int>(allTriangles.size())) {
                    Triangle* targetTriangle = allTriangles[index];

                    // Cascade delete: 
                    // Point.h/Point.cpp destructor prints a message, which will execute here.
                    // To do this, we need to locate the Point instances this Triangle references.
                    // Standard C++ doesn't let us read private variables of Triangle from main, but 
                    // we can safely leverage our knowledge of their relationship or add getters to Triangle.
                    // Since Triangle destructor clears references, we delete the points *first* or *last*.
                    
                    // Note: If you want to delete the underlying points, we can safely delete them from heap.
                    // Let's delete the triangle object first to sever the links, then safely delete the points.
                    // (We will simulate finding which points belong to this triangle by keeping track of the 3-point chunks)
                    
                    // In our current layout, Point 1, 2, and 3 of Triangle index `K` are stored at positions `3*K`, `3*K+1`, `3*K+2` 
                    // in our `allPoints` vector.
                    size_t pointStartIdx = index * 3;
                    
                    std::cout << "Deleting Triangle [" << index << "] and cascading to its points...\n";

                    // 1. Delete Triangle
                    delete targetTriangle;
                    allTriangles.erase(allTriangles.begin() + index);

                    // 2. Delete and clean up the 3 associated Points
                    for (int i = 2; i >= 0; --i) { // Iterating backwards ensures we don't mess up our vector indexing
                        size_t targetPointIdx = pointStartIdx + i;
                        if (targetPointIdx < allPoints.size()) {
                            Point* p = allPoints[targetPointIdx];
                            delete p; // Triggers ~Point() destructor printing
                            allPoints.erase(allPoints.begin() + targetPointIdx);
                        }
                    }

                    std::cout << "SUCCESS: Triangle and its 3 vertex Points successfully freed from heap memory.\n";

                } else {
                    std::cout << "Invalid index choice.\n";
                }
                break;
            }
            case 0:
                std::cout << "Exiting program. Cleaning up memory...\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
                break;
        }
        std::cout << "------------------------\n";

    } while (choice != 0);

    // Final global dynamic memory cleanup to guarantee no leaks on exit!
    for (Triangle* t : allTriangles) {
        delete t; 
    }
    for (Point* p : allPoints) {
        delete p; 
    }
    if (myDynamicArray != nullptr) {
        deleteArray(myDynamicArray);
    }

    std::cout << "Goodbye!\n";
    return 0;
}