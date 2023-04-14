#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//*************************     Matrix      ****************************
int adjMatrix[MAX][MAX];
int vertices, edges;

// create the adjacency matrix
void createAdjMatrix() {
    int vertex1, vertex2;

    // initialize adjacency matrix
    for(int i = 0; i < MAX; i++) 
        for(int j = 0; j < MAX; j++) 
            adjMatrix[i][j] = 0;    
   
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    for(int i = 0; i < edges; i++) {
        printf("Enter edge (vertex1 vertex2): ");
        scanf("%d %d", &vertex1, &vertex2);

        adjMatrix[vertex1][vertex2] = 1;
        adjMatrix[vertex2][vertex1] = 1;
    }
}

void printAdjMatrix() {
   
    printf("Adjacency Matrix:\n");

    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void DFSAdjMatrix(int vertex, int visited[]) {
  
    visited[vertex] = 1;
    printf("%d ", vertex);
    for(int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && visited[i] == 0) {
            DFSAdjMatrix(i, visited);
        }
    }
}

void BFSAdjMatrix(int vertex, int visited[]) {
    int queue[MAX];
    int front = 0, rear = 0, i, current;

    for(i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    visited[vertex] = 1;
    queue[rear++] = vertex;

    while(front != rear) {
      
        current = queue[front++];
        printf("%d ", current);

        
        for(i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

//**************************   List    *****************************

typedef struct node {
    int vertex;
    struct node *next;
} node;

node *adjList[MAX];


void addEdge(int u, int v) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}


void createAdjList() {
    int u, v;


    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

   
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }

    for (int j = 0; j < edges; j++) {
        printf("Enter the vertices for edge %d: ", j+1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
}

void printAdjList() {
    int i;
    node *temp;

    printf("\nAdjacency List:\n");
    for (i = 0; i < vertices; i++) {
        printf("%d -> ", i);
        temp = adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


void DFSAdjList(int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    node *temp = adjList[vertex];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFSAdjList(temp->vertex, visited);
        }
        temp = temp->next;
    }
}


void BFSAdjList(int start, int visited[]) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    printf("%d ", start);
    while (front < rear) {
        int vertex = queue[front++];
        node *temp = adjList[vertex];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                printf("%d ", temp->vertex);
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int choice, vertex, visited[MAX];
  

    do {
        printf("\n-------------------------------");
        printf("\n1. Create the adjacency matrix");
        printf("\n2. Create the adjacency List");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                  
                createAdjMatrix();
                printAdjMatrix();
                
                printf("\nEnter starting vertex: ");
                scanf("%d", &vertex);

                //DFS
                for(int i = 0; i < vertices; i++) {
                    visited[i] = 0;
                }
                printf("DFS Traversal: ");
                DFSAdjMatrix(vertex, visited);
                printf("\n");

                //BFS
                for(int i = 0; i < vertices; i++) {
                    visited[i] = 0;
                }
                printf("BFS Traversal: ");
                BFSAdjMatrix(vertex, visited);
                printf("\n");


                break;

            case 2:
                
                createAdjList();
                printAdjList();

                // DFS
                for (vertex = 0; vertex < vertices; vertex++) {
                    visited[vertex] = 0;
                }
                printf("\nDFS Traversal: ");                
                for (vertex = 0; vertex < vertices; vertex++) {
                    if (!visited[vertex]) {
                        DFSAdjList(vertex, visited);
                    }
                }

                // BFS
                for (vertex = 0; vertex < vertices; vertex++) {
                    visited[vertex] = 0;
                }
                printf("\nBFS Traversal: ");
                for (vertex = 0; vertex < vertices; vertex++) {
                    if (!visited[vertex]) {
                        BFSAdjList(vertex, visited);
                    }
                }
               
                break;

            case 3:               
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 3);

    return 0;
}
