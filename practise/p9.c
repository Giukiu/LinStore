#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define Max 100
typedef struct node{
    int vertex;
    struct node* next;
}node;
typedef struct Graph{
    int numV;
    node* adjList[Max];
    bool visited[Max];
}G;

G* createGraph(int vertices)
{
    G* graph = malloc(sizeof(G));
    graph->numV = vertices;
    for (int i = 0; i < vertices; i++) {
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
void Edge(G* graph, int sre, int dest)
{
    node* newNode = createNode(dest);
    newNode->next = graph->adjList[sre];
    graph->adjList[sre] = newNode;

    newNode = createNode(sre);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
    

}
void DFS(G* graph, int vertex)
{
    graph->visited[vertex] = true;
    printf("%d ", vertex);

    node* temp = graph->adjList[vertex];
    while (temp) {
        if (!graph->visited[temp->vertex]) {
            DFS(graph, temp->vertex);
        }
        temp = temp->next;
    }
    
}
int main()
{
    G* graph = createGraph(5);
    Edge(graph, 0, 1);
    Edge(graph, 0, 2);
    Edge(graph, 1, 3);
    Edge(graph, 1, 4);

    printf("DFS traversal: ");
    DFS(graph, 0); // 从顶点0开始    
    return 0;
}