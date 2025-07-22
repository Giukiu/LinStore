#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*图的DFS遍历*/
typedef struct node{
    int vertex;
    struct node* next;
}node;
typedef struct graph{
    int numVertex;
    node* adjList[100];
    bool visited[100];
}G;
G* createGraph(int vertices)
{
    G* graph = malloc(sizeof(G));
    graph->numVertex = vertices;
    for (int i = 0; i < vertices; i++){
        graph->adjList[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}
node* createNode(int e)
{
    node* newNode = malloc(sizeof(node));
    newNode->vertex = e;
    newNode->next = NULL;
    return newNode;
}
void addEdge(G* graph, int sre, int dest)
{
    node* temp = createNode(dest);
    temp->next = graph->adjList[sre];
    graph->adjList[sre] = temp;

    temp = createNode(sre);
    temp->next = graph->adjList[dest];
    graph->adjList[dest] = temp;

}
void DFS(G* graph, int vertex) {
    graph->visited[vertex] = true;
    printf("%d ", vertex);

    node* temp = graph->adjList[vertex];
    while (temp) {
        int a = temp->vertex;
        if (!graph->visited[a]) {
            DFS(graph, a);
        }
        temp = temp->next;
    }
}
int main() {

    G* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    printf("DFS traversal: ");
    DFS(graph, 0); // 从顶点0开始    
    return 0;
}