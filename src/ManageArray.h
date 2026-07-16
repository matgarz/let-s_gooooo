#ifndef MANAGEARRAY_H
#define MANAGEARRAY_H
//These functions demonstrate manual memory management in C++
//A dynamic array is allocated on the heap using pointers so that its size can be determined at runtime (based on user input). 


// Returns a pointer to the first element, allowing the caller to manage it.
int* createArray(int size);

// Initializes the array using pointer-based indexing. The function receives a raw pointer
void initializeArray(int* arr, int size);

// Prints the contents of the dynamic array.
void printArray(int* arr, int size);

// Deallocates the dynamic array using delete[]. This is importante for to freeing heap memory to avoid leaks.
void deleteArray(int* arr);
#endif
