#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to perform DFS on a graph
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int currentVertex, int visited[MAX_VERTICES]) {
    // Mark the current vertex as visited and print it
    visited[currentVertex] = 1;
    printf("%d ", currentVertex);

    // Recur for all the adjacent vertices that have not been visited
    for (int i = 0; i < vertices; i++) {
        if (graph[currentVertex][i] == 1 && !visited[i]) {
            DFS(graph, vertices, i, visited);
        }
    }
}

// Function to initialize DFS traversal and call the DFS function
void DFSTraversal(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
    // Mark all vertices as not visited
    int visited[MAX_VERTICES];
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    printf("Depth-First Traversal starting from vertex %d: ", startVertex);

    // Call the recursive DFS function starting from the given vertex
    DFS(graph, vertices, startVertex, visited);

    printf("\n");
}

// Example usage
int main() {
    int vertices, edges, i, j, startVertex;

    // Get the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int graph[MAX_VERTICES][MAX_VERTICES];

    // Initialize the adjacency matrix
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Get the edges
    printf("Enter the edges (vertex1 vertex2):\n");
    for (i = 0; i < edges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        // Assuming undirected graph, so set both graph[vertex1][vertex2] and graph[vertex2][vertex1] to 1
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }

    // Get the starting vertex for DFS
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    // Perform DFS
    DFSTraversal(graph, vertices, startVertex);

    return 0;
}
