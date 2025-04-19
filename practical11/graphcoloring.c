#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX]; // adjacency matrix
int color[MAX];       // stores color assigned to each vertex
int V;                // number of vertices

// Function to check if color assignment is safe
bool isSafe(int v, int c, int m) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

// Backtracking function to solve m-coloring
bool graphColoring(int v, int m) {
    if (v == V) {
        printf("Solution: ");
        for (int i = 0; i < V; i++)
            printf("%d ", color[i]);
        printf("\n");
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c, m)) {
            color[v] = c;
            if (graphColoring(v + 1, m))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    int m;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoring(0, m))
        printf("No solution exists.\n");

    return 0;
}
