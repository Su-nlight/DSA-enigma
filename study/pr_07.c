#include <stdio.h>
#include <stdlib.h> 
#define MAX_SIZE 100

void readArray(int arr[], int *n);
void printArray(int arr[], int n);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);


void readArr(int arr[], int *n) {
    printf("\n--- Array Input ---\n");
    printf("Enter the number of elements (max %d): ", MAX_SIZE); // Arr size inp
    if (scanf("%d", n) != 1 || *n <= 0 || *n > MAX_SIZE) {
        printf("Invalid size. Please enter a positive number up to %d.\n", MAX_SIZE);
        while (getchar() != '\n'); *n = 0; 
        return;
    } // new meth to avoid errors of blank inp

    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Terminating input process.\n");
            while (getchar() != '\n');
            return;
        }
    }
    printf("Array successfully read.\n");
}

void printArr(int arr[], int n) {
    if (n <= 0) {
        printf("The array is currently empty.\n");
        return;
    }
    printf("\nCurrent Array =\n[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void heapify(int arr[], int n, int i) {
    int largest = i; //root = largest
    int l=2*i+1; // left child idx
    int r=l+1; // right child idx
    int temp;
    if(l<n && arr[l] > arr[largest]) largest = l;
    if(r<n && arr[r] > arr[largest]) largest = r;
    if(largest !=i ){
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest); // recursive heap
    }
    
}

void heapSort(int arr[], int n) {
    // to Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n = 0; // Current size of the array
    int choice;

    printf("Menu-Driven Heap Sort Program!\n");
    readArr(arr, &n); // initial arr inp

    do {
        printf("Menu\n");
        printf("1. Input a new array\n");
        printf("2. Display current array\n");
        printf("3. Perform Heap Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            choice = 0; // Set invalid choice
            continue;
        }

        switch (choice) {
            case 1:
                readArr(arr, &n);
                break;
            case 2:
                printArr(arr, n);
                break;
            case 3:
                if (n > 0) {
                    printf("\n--- Sorting Array ---\n");
                    heapSort(arr, n);
                    printf("Heap Sort completed.\n");
                    printArr(arr, n);
                } else {
                    printf("Cannot sort an empty array. Please input an array first.\n");
                }
                break;
            case 4:
                printf("\nExiting\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option (1-4).\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
/*
Sample OUTPUT:
Menu-Driven Heap Sort Program!

--- Array Input ---
Enter the number of elements (max 100): 9
Enter 9 elements:
Element 1: 34
Element 2: 12
Element 3: 42
Element 4: 8
Element 5: 22
Element 6: 37
Element 7: 16
Element 8: 8
Element 9: 48
Array successfully read.
Menu
1. Input a new array
2. Display current array
3. Perform Heap Sort
4. Exit
Enter your choice: 3

--- Sorting Array ---
Heap Sort completed.

Current Array =
[8, 8, 12, 16, 22, 34, 37, 42, 48]
Menu
1. Input a new array
2. Display current array
3. Perform Heap Sort
4. Exit
Enter your choice: 4

Exiting

*/