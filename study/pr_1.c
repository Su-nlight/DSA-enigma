#include <stdio.h>

// Binary Search
int binary_search(int arr[], int n, int ele) {
    int LB = 0, UB = n - 1, mid;

    while (LB <= UB) {
        mid = (LB + UB) / 2;

        if (ele == arr[mid]) {
            printf("Element %d found at index %d (Binary Search)\n", ele, mid);
            return mid;
        }
        else if (ele > arr[mid]) {
            LB = mid + 1;
        }
        else {
            UB = mid - 1;
        }
    }
    printf("Element %d not found (Binary Search)\n", ele);
    return -1;
}

// Linear Search
int linear_search(int arr[], int n, int ele) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == ele) {
            printf("Element %d found at index %d (Linear Search)\n", ele, i);
            return i;
        }
    }
    printf("Element %d not found (Linear Search)\n", ele);
    return -1;
}

int main() {
    int i, ele, n, choice;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("Enter %d index element of array: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be found: ");
    scanf("%d", &ele);

    printf("\nChoose Search Method:\n");
    printf("1. Binary Search\n");
    printf("2. Linear Search\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            binary_search(arr, n, ele);
            break;
        case 2:
            linear_search(arr, n, ele);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
