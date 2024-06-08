#include<stdio.h>

/*
functions:
    Arrayinit -> to initialize an Array
    printArray -> to print Array 
*/

struct myArray {
    int maxSize;            //Total size
    int usedSize;
    int *ptr;               // points to the first element of the array
};

void Arrayinit(struct myArray *a, int tSize) {
    // Dereferencing the pointer to set values
    (*a).maxSize = tSize;
    (*a).ptr = (int *) malloc(tSize*sizeof(int));            // Allocates memory of tSize block where each block is of the size of an int (4 bytes)

    // Using arrow operator to do the same thing
    a->maxSize = tSize;
    a->ptr = (int *) malloc(tSize*sizeof(int));
}

int main() {
    struct myArray marks;
    return 0;
}