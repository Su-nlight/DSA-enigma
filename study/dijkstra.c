#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

// Function to find vertex with minimum distance value i.e. not processed
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}


void dijkstra(int graph[V][V], int src) {
    int dist[V];  // Array to store the shortest distance from the source
    int sptSet[V]; // Shortest path tree set (to check if vertex is already processed)

    // Initialize distances and set of processed vertices
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX; // Set all distances to infinity
        sptSet[i] = 0; // All vertices are initially unprocessed
    }

    dist[src] = 0; // Distance of source vertex from itself is always 0

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet); // Get the vertex with the minimum distance

        sptSet[u] = 1; // Mark selected vertex as processed

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] if and only if the vertex is not processed, there is an edge,
            // and the new distance is smaller than the current distance
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printf("Vertex \t Distance from Source Vertex %d\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d \t %s\n", i, "INFINITY");
        else
            printf("%d \t %d\n", i, dist[i]);
    }
}

// Main function to test the above implementation
int main() {
    // Representation of the graph as an adjacency matrix
    // The graph is a 5x5 matrix where the value graph[i][j] represents the weight of the edge from vertex i to vertex j.
    
int graph[V][V] = {
    {0, 4, 0, 0, 0},  // Node 0 connected to Node 1 with weight 4
    {4, 0, 8, 0, 0},  // Node 1 connected to Node 0 with weight 4, Node 2 with weight 8
    {0, 8, 0, 7, 0},  // Node 2 connected to Node 1 with weight 8, Node 3 with weight 7
    {0, 0, 7, 0, 9},  // Node 3 connected to Node 2 with weight 7, Node 4 with weight 9
    {0, 0, 0, 9, 0}   // Node 4 connected to Node 3 with weight 9
};

    int source = 0; // Source vertex

    dijkstra(graph, source);

    return 0;
}
