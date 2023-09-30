#include <stdio.h>

void display(int arr[], int n) {

    // Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int SortedInsertion(int *arr, int size, int element, int capacity, int index) {
    if(capacity <= size)
        return 0;

    for (int i=size-1; i>= index; i--) {
        arr[i+1] = arr[i];
    }
    arr[index] = element;

    return 1;
}

int Deletion(int *arr, int size, int index) {
    if(!size)
        return 0;

    for (int i = index; i < size; i++) {
        arr[i] = arr[i+1];
    }
    return 1;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
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