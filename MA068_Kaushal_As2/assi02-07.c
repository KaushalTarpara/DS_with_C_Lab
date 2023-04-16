#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
int visited[MAX_VERTICES];
int numVertices, numEdges;

void dijkstra(int source) {
    int i, j;
    for (i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[source] = 0;
    for (i = 0; i < numVertices - 1; i++) {
        int u = -1;
        for (j = 0; j < numVertices; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        visited[u] = 1;
        for (j = 0; j < numVertices; j++) {
            if (graph[u][j] != 0 && !visited[j]) {
                int alt = dist[u] + graph[u][j];
                if (alt < dist[j]) {
                    dist[j] = alt;
                }
            }
        }
    }
}

int main() {
    int i, j, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter the edges (u, v, weight):\n");
    for (i = 0; i < numEdges; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(source);
    printf("Shortest path from vertex %d:\n", source);
    for (i = 0; i < numVertices; i++) {
        if (dist[i] == INT_MAX) {
            printf("Vertex %d: No path\n", i);
        } else {
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
    return 0;
}
