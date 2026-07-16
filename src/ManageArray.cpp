#include <iostream>
using namespace std;

// Create a dynamic array of given size
int* createArray(int size) {
    if (size <= 0) {
        return nullptr;
    }
    int* arr = new int[size];
    return arr;
}

// Initialize array with values 0 to size-1
void initializeArray(int* arr, int size) {
    if (arr == nullptr) return;

    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

// Print array elements
void printArray(int* arr, int size) {
    if (arr == nullptr) {
        cout << "Array is empty." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Delete the dynamic array
void deleteArray(int* arr) {
    delete[] arr;
}
