#include <stdio.h>

// Function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // choosing last element as pivot
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

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to display array
void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100], n = 0, choice;

    while (1) {
        printf("\n==== MENU ====\n");
        printf("1. Enter array elements\n");
        printf("2. Display array\n");
        printf("3. Sort using Quick Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter %d elements:\n", n);
            for (int i = 0; i < n; i++)
                scanf("%d", &arr[i]);
            break;

        case 2:
            display(arr, n);
            break;

        case 3:
            if (n == 0) {
                printf("Array is empty! Enter elements first.\n");
            } else {
                quickSort(arr, 0, n - 1);
                printf("Array sorted successfully.\n");
            }
            break;

        case 4:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
