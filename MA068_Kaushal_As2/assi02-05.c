#include <stdio.h>

#define MAX 100
#define INFINITY 9999

typedef struct Node {
    int key;
    int parent;
    int visited;
    int weight;
} Node;

// find the node with the minimum weight in the set of unvisited nodes
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

// Prim's algorithm 
void prim(Node nodes[], int adjacencyMatrix[][MAX], int numNodes) {
    
    // Set first node to 0 and parent to -1
    nodes[0].weight = 0;
    nodes[0].parent = -1;


    for (int i = 0; i < numNodes - 1; i++) {
        int u = findMin(nodes, numNodes);
        nodes[u].visited = 1;

       
        for (int v = 0; v < numNodes; v++) {
            if (adjacencyMatrix[u][v] != 0 && !nodes[v].visited && adjacencyMatrix[u][v] < nodes[v].weight) {
                nodes[v].weight = adjacencyMatrix[u][v];
                nodes[v].parent = u;
            }
        }
    }

    for (int i = 1; i < numNodes; i++) {
        printf("%d - %d\n", nodes[i].parent, i);
    }
}

int main() {
    int numNodes = 0;
    Node nodes[MAX];
    int adjacencyMatrix[MAX][MAX];

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        nodes[i].key = i;
        nodes[i].visited = 0;
        nodes[i].weight = INFINITY;
    }

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    
    prim(nodes, adjacencyMatrix, numNodes);

    return 0;
}
