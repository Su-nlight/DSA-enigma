#include <stdio.h>

// Structure to represent an item
struct Item {
    int weight;
    int value;
    float ratio;
};

// Function to compare two items based on their value/weight ratio
int compare(struct Item a, struct Item b) {
    return (a.ratio > b.ratio) ? -1 : 1; // Descending order of ratio
}

// Function to solve Fractional Knapsack problem
float fractionalKnapsack(int W, struct Item items[], int n) {
    // Sort items by ratio value/weight
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Sort items based on the ratio
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (compare(items[i], items[j]) > 0) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Calculate the maximum value we can carry
    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W == 0) {
            break;
        }
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((float)W / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;

    // Take input for number of items and capacity of knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    struct Item items[n];

    // Take input for each item's weight and value
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    // Solve the fractional knapsack problem
    float maxValue = fractionalKnapsack(W, items, n);

    // Output the result
    printf("Maximum value in the Knapsack = %.2f\n", maxValue);

    return 0;
}
