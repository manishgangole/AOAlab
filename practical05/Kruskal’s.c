#include <stdio.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Function to sort edges based on weight (simple bubble sort for clarity)
void sortEdges(struct Edge edges[], int E) {
    struct Edge temp;
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Find parent (used in union-find)
int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union of two sets
void unionSet(int parent[], int x, int y) {
    parent[x] = y;
}

void kruskal(struct Edge edges[], int V, int E) {
    int parent[MAX];
    struct Edge result[MAX];
    int count = 0, cost = 0;

    for (int i = 0; i < V; i++)
        parent[i] = i;

    sortEdges(edges, E);

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        int parentU = find(parent, u);
        int parentV = find(parent, v);

        if (parentU != parentV) {
            result[count++] = edges[i];
            cost += w;
            unionSet(parent, parentU, parentV);
        }
    }

    printf("\nEdges in the Minimum Spanning Tree (Kruskal):\n");
    for (int i = 0; i < count; i++)
        printf("%d - %d : %d\n", result[i].u, result[i].v, result[i].weight);

    printf("Total cost = %d\n", cost);
}

int main() {
    int V, E;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        printf("Enter edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, V, E);

    return 0;
}
