#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (same as recursive version)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Iterative Quick Sort
void quickSortIterative(int arr[], int l, int h) {
    // Create an auxiliary stack
    int stack[h - l + 1];
    int top = -1;

    // Push initial values of l and h
    stack[++top] = l;
    stack[++top] = h;

    // Pop until stack is empty
    while (top >= 0) {
        // Pop high and low
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        int p = partition(arr, l, h);

        // If elements on left side of pivot, push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If elements on right side of pivot, push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array:\n");
    printArray(arr, n);

    quickSortIterative(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}
