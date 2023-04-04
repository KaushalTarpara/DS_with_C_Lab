#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100
#define INFINITY 9999

// Node struct to store information about each node in the graph
typedef struct Node {
    int key;
    int parent;
    bool visited;
    int weight;
} Node;

// Function to find the node with the minimum weight in the set of unvisited nodes
int findMin(Node nodes[], int numNodes) {
    int minIndex = -1;
    int minWeight = INFINITY;
    for (int i = 0; i < numNodes; i++) {
        if (!nodes[i].visited && nodes[i].weight < minWeight) {
            minIndex = i;
            minWeight = nodes[i].weight;
        }
    }
    return minIndex;
}

// Prim's algorithm to find the MST of the graph
void prim(Node nodes[], int adjacencyMatrix[][MAX_NODES], int numNodes) {
    // Set the weight of the first node to 0 and parent to -1
    nodes[0].weight = 0;
    nodes[0].parent = -1;

    // Loop through all unvisited nodes and find the one with the minimum weight
    for (int i = 0; i < numNodes - 1; i++) {
        int u = findMin(nodes, numNodes);
        nodes[u].visited = true;

        // Update the weight of all adjacent unvisited nodes
        for (int v = 0; v < numNodes; v++) {
            if (adjacencyMatrix[u][v] != 0 && !nodes[v].visited && adjacencyMatrix[u][v] < nodes[v].weight) {
                nodes[v].weight = adjacencyMatrix[u][v];
                nodes[v].parent = u;
            }
        }
    }

    // Print the edges in the MST
    for (int i = 1; i < numNodes; i++) {
        printf("%d - %d\n", nodes[i].parent, i);
    }
}

int main() {
    int numNodes = 0;
    Node nodes[MAX_NODES];
    int adjacencyMatrix[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    // Initialize the nodes
    for (int i = 0; i < numNodes; i++) {
        nodes[i].key = i;
        nodes[i].visited = false;
        nodes[i].weight = INFINITY;
    }

    // Scan the adjacency matrix from the user
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Find the MST using Prim's algorithm
    prim(nodes, adjacencyMatrix, numNodes);

    return 0;
}
