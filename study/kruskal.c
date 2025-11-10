#include <stdio.h>
#include <stdlib.h>

// A structure to represent an edge
typedef struct {
    int u, v, weight;
} Edge;

// A structure to represent a subset for union-find
typedef struct {
    int parent;
    int rank;
} Subset;

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    }
    return subsets[i].parent;
}

void union_sets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Union by rank
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare edges used in sorting
int compare(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskal(int graph[][3], int E, int V) {
    // Create a list of edges
    Edge edges[E];
    for (int i = 0; i < E; i++) {
        edges[i].u = graph[i][0];
        edges[i].v = graph[i][1];
        edges[i].weight = graph[i][2];
    }

    // Sort all edges in increasing order of their weights
    qsort(edges, E, sizeof(Edge), compare);

    // Create V subsets (disjoint sets)
    Subset *subsets = (Subset*)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    printf("Edge \tWeight\n");

    // Number of edges in MST
    int e = 0;
    for (int i = 0; e < V - 1 && i < E; i++) {
        // Get the next edge
        int u = edges[i].u;
        int v = edges[i].v;

        int x = find(subsets, u);
        int y = find(subsets, v);

        // If including this edge doesn't cause a cycle, include it in the result
        if (x != y) {
            printf("%d - %d \t%d\n", u, v, edges[i].weight);
            union_sets(subsets, x, y);
            e++;
        }
    }

    free(subsets);
}

int main() {
    // Graph represented as an edge list {u, v, weight}
    int graph[][3] = {
        {0, 1, 4}, {0, 2, 2}, {1, 2, 1}, {1, 3, 5},
        {2, 3, 8}, {2, 4, 10}, {3, 4, 2}
    };
    int E = 7;  // Number of edges
    int V = 5;  // Number of vertices

    // Call Kruskal's algorithm
    kruskal(graph, E, V);

    return 0;
}
