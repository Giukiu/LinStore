#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 100
/*图的BFS遍历*/
typedef struct Node{
    int vertex;
    struct Node* next;
}node;
typedef struct Graph
{
    int vertices;
    node* adjList[max];
    bool visited[max];
}G;
typedef struct Queue{
    int items[max];
    int front, rear;
} Q;
Q* createQ()
{
    Q* q = malloc(sizeof(Q));
    q->front = q->rear = -1;
    return q;
}
bool isEmpty(Q* q)
{
    return q->front == -1;
}
void enQ(Q* q, int value)
{
    if (q->rear == max - 1) return;
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}
int deQ(Q*q)
{
    if (isEmpty(q)) return -1;
        int item = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else 
        q->front++;
    return item;
}
G* createGraph(int vertices)
{
    G* graph = malloc(sizeof(G));
    graph->vertices = vertices;
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
void BFS(G* graph, int startVertex) {
    Q* q = createQ();
    graph->visited[startVertex] = true;
    enQ(q, startVertex);

    while (!isEmpty(q)) {
        int current = deQ(q);
        printf("%d ", current);

        node* temp = graph->adjList[current];
        while (temp) {
            int adj = temp->vertex;
            if (!graph->visited[adj]) {
                graph->visited[adj] = true;
                enQ(q, adj);
            }
            temp = temp->next;
        }
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
    BFS(graph, 0);
    return 0;
}