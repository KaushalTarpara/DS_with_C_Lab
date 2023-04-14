#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Adjacency matrix implementation
int adjMatrix[MAX][MAX];

// Adjacency list implementation
typedef struct node {
    int vertex;
    struct node* next;
} Node;

Node* adjList[MAX];

// Initialize the adjacency matrix and list
void initializeGraph(int numVertices) {
    int i, j;
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
        adjList[i] = NULL;
    }
}

// Add an edge to the graph
void addEdge(int src, int dest) {
    
    // Add edge to adjacency matrix
    adjMatrix[src][dest] = 1;

    // Add edge to adjacency list
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// Print the number of edges, edge list, and degree of each vertex
void printGraph(int numVertices) {
    int i, j;
    int numEdges = 0;

    printf("Adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
            if (adjMatrix[i][j] == 1) {
                numEdges++;
            }
        }
        printf("\n");
    }

    printf("\nAdjacency list:\n");
    for (i = 0; i < numVertices; i++) {
        printf("%d: ", i);
        Node* currNode = adjList[i];
        while (currNode != NULL) {
            printf("%d ", currNode->vertex);
            currNode = currNode->next;
        }
        printf("\n");
    }

    printf("\nNumber of edges: %d\n", numEdges);

    printf("Degree of each vertex:\n");
    for (i = 0; i < numVertices; i++) {
        int degree = 0;
        for (j = 0; j < numVertices; j++) {
            degree += adjMatrix[i][j];
        }
        printf("%d: %d\n", i, degree);
    }
}

// Depth-first search traversal using adjacency matrix
void dfsMatrix(int numVertices, int vertex, int visited[]) {
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && visited[i] == 0) {
            dfsMatrix(numVertices, i, visited);
        }
    }
}

// Depth-first search traversal using adjacency list
void dfsList(int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    Node* currNode = adjList[vertex];
    while (currNode != NULL) {
        if (visited[currNode->vertex] == 0) {
            dfsList(currNode->vertex, visited);
        }
        currNode = currNode->next;
    }
}

// Breadth-first search traversal using adjacency matrix
void bfsMatrix(int numVertices, int vertex, int visited[]) {
    int queue[MAX];
    int front = -1, rear =-1;
        visited[vertex] = 1;
    queue[++rear] = vertex;
    while (front != rear) {
        int currVertex = queue[++front];
        printf("%d ", currVertex);
        int i;
        for (i = 0; i < numVertices; i++) {
            if (adjMatrix[currVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

// Breadth-first search traversal using adjacency list
void bfsList(int vertex, int visited[]) {
    int queue[MAX];
    int front = -1, rear = -1;
    visited[vertex] = 1;
    queue[++rear] = vertex;
    while (front != rear) {
        int currVertex = queue[++front];
        printf("%d ", currVertex);
        Node* currNode = adjList[currVertex];
        while (currNode != NULL) {
            if (visited[currNode->vertex] == 0) {
                visited[currNode->vertex] = 1;
                queue[++rear] = currNode->vertex;
            }
            currNode = currNode->next;
        }
    }
}

int main() {
    int numVertices = 5;
    initializeGraph(numVertices);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);

    printf("Graph information:\n");
    printGraph(numVertices);

    printf("\nDFS traversal (using adjacency matrix): ");
    int visited1[MAX] = {0};
    dfsMatrix(numVertices, 0, visited1);

    printf("\nDFS traversal (using adjacency list): ");
    int visited2[MAX] = {0};
    dfsList(0, visited2);

    printf("\nBFS traversal (using adjacency matrix): ");
    int visited3[MAX] = {0};
    bfsMatrix(numVertices, 0, visited3);

    printf("\nBFS traversal (using adjacency list): ");
    int visited4[MAX] = {0};
    bfsList(0, visited4);

    return 0;
}

