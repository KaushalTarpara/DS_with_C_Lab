#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX_EDGES];

int find(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void union_(int u, int v) {
    parent[find(u)] = find(v);
}

int cmp(const void* a, const void* b) {
    Edge* e1 = (Edge*) a;
    Edge* e2 = (Edge*) b;
    return e1->weight - e2->weight;
}

void kruskal(Edge* edges, int numEdges, int numVertices) {
    int mstWeight = 0;
    int numMstEdges = 0;
    int i;
   
    for (i = 0; i < numVertices; i++) {
        parent[i] = i;
    }
    
	qsort(edges, numEdges, sizeof(Edge), cmp);
    for (i = 0; i < numEdges && numMstEdges < numVertices - 1; i++) {
        
		int u = edges[i].u;
        int v = edges[i].v;
        int uroot = find(u);
        int vroot = find(v);
        
		if (uroot != vroot) {
            union_(u, v);
            printf("%d - %d = %d\n", u, v, edges[i].weight);
            mstWeight += edges[i].weight;
            numMstEdges++;
        }
    }
    
	if (numMstEdges < numVertices - 1) {
        printf("Graph is not connected\n");
    } else {
        printf("MST weight: %d\n", mstWeight);
    }
}

int main() {
    int numVertices, numEdges;
    Edge edges[MAX_EDGES];
    int i;
    
	printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    
	printf("Enter the edges (u, v, weight):\n");
    for (i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    
	printf("Minimum spanning tree:\n");
    kruskal(edges, numEdges, numVertices);
    return 0;
}
