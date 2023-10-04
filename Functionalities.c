#include <stdio.h>

//
//  Traversal in an array
void display(int arr[], int n) {

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

//
//  Insertion in an array
int SortedInsertion(int *arr, int size, int element, int capacity, int index) {
    if(capacity <= size)
        return 0;

    for (int i=size-1; i>= index; i--) {
        arr[i+1] = arr[i];
    }
    arr[index] = element;

    return 1;
}


//
//  Deletion in an array
int Deletion(int *arr, int size, int index) {
    if(!size)
        return 0;

    for (int i = index; i < size; i++) {
        arr[i] = arr[i+1];
    }
    return 1;
}

//
//  Linear Search
int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == element)
            return arr[i];
    }
    
    return -99;
}

//
//  Binary Search
int binarySearch(int arr[], int size, int element) {
    int high = size-1, low = 0;
    int mid;

    while(high>=low) {
        mid = (int)((high+low)/2);

        if(arr[mid] == element)
            return arr[mid];
        
        else {
            if(element > arr[mid])
                low = mid;
            else
                high = mid;
        }
    }

    return -99;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    // int size = sizeof(arr)/sizeof(int);              //trickery 101
    int size = 5, element = 45, capacity = 100, index = 3;

    display(arr, size);

    if(SortedInsertion(&arr, size, element, capacity, index))
    {
        size++;
        display(arr, size);
    }

    if(Deletion(&arr, size, index)) {
        size--;
        display(arr, size);
    }
    return 0;
}