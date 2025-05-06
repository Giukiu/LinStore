#include <stdio.h>
#include <stdlib.h>
    /*构建邻接表*/
typedef struct node{
    int vertex;
    struct node* next;
}node;
typedef struct Graph {
    int numVertices;
    node** adjList;
}Graph;
node* createNode(int e) {
    node* newNode = malloc(sizeof(node));
    newNode->vertex = e;
    newNode->next = NULL;
    return newNode;
}
Graph* createGraph(int vertices) {
    Graph* G = malloc(sizeof(Graph));
    G->adjList = malloc(sizeof(node*) * vertices);
    G->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        G->adjList[i] = NULL;
    }
    return G;
}
void addEdge(Graph* G, int src, int dest) {
    node* newNode = createNode(dest);
    newNode->next = G->adjList[src];
    G->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = G->adjList[dest];
    G->adjList[dest] = newNode;
}

int main() {
    Graph* graph = createGraph(5);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    return 0;

return 0;
}