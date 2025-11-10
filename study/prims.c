#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 5

// Utility function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's Algorithm
void prim(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values used to pick minimum weight edge
    bool mstSet[V]; // To represent whether the vertex is included in MST

    // Initialize all keys as INFINITE, and mstSet as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start from the first vertex
    key[0] = 0;
    parent[0] = -1; // First node is always the root of MST

    // Loop to find the MST
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update the key and parent values of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of u
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than the current key value of v
            if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%c - %c \t%d\n", parent[i] + 'A', i + 'A', graph[i][parent[i]]);
    }
}

int main() {
    // Graph represented as an adjacency matrix (weights of the edges)
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 4, 2, 0, 0},
        {4, 0, 1, 5, 0},
        {2, 1, 0, 8, 10},
        {0, 5, 8, 0, 2},
        {0, 0, 10, 2, 0}
    };

    // Number of vertices in the graph
    int V = 5;

    // Call Prim's algorithm
    prim(graph, V);

    return 0;
}
