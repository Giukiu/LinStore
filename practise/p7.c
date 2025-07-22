#include <stdio.h>
#include <stdlib.h>
/*构建图的邻接表*/
typedef struct arcNode{     /*边结点结构体*/
    int adjvex;
    struct arcNode* nextarc;
}arcNode;
typedef struct Vnode{       /*表头结点结构体*/
    char V;
    arcNode* firstarc;
}Vnode;
typedef struct Graph{       /*邻接表图结构体*/
    int vertices, edges;
    Vnode** adjList;
}Graph;

Graph* createGraph(int vertices, int edges)     /*邻接表图的初始化*/
{
    Graph* G = malloc(sizeof(Graph));
    G->adjList = malloc(sizeof(Vnode) * vertices);
    G->vertices = vertices;
    G->edges = edges;
    return G;
}
void createADJlise(Graph* G)        /*表头数组初始化*/
{
    char a[] = "abcdefg";
    for (int i = 0; i < G->vertices; i++) {
        G->adjList[i] = malloc(sizeof(Vnode));
        G->adjList[i]->V = a[i];
        G->adjList[i]->firstarc = NULL;
    }
    
}
int Loc(Graph* G, char e)       /*寻找结点在表头数组中的下标*/
{
    for (int i = 0; i < G->vertices; i++) {
       if (e == G->adjList[i]->V)
            return i;
    }
    return -1;
}
arcNode* createARCnode(int e)       /*创建边结点*/
{
    arcNode* newNode = malloc(sizeof(arcNode));
    newNode->adjvex = e;
    newNode->nextarc = NULL;
    return newNode;
}
void createEdge(Graph* G, int i, int j)  /*创建边*/
{
    
    arcNode* newNode = createARCnode(j);
    newNode->nextarc = G->adjList[i]->firstarc;
    G->adjList[i]->firstarc = newNode;

    newNode = createARCnode(i);
    newNode->nextarc = G->adjList[j]->firstarc;
    G->adjList[j]->firstarc = newNode;
    printf("%c--%c complished\n", G->adjList[i]->V, G->adjList[j]->V);
    
}
void run(Graph* G)
{
    for (int t = 0; t < G->edges; t++) {
        char v1, v2;
        printf("Enter vertices: ");
        scanf(" %c%c", &v1, &v2);
        int i = Loc(G, v1);
        int j = Loc(G, v2);
        createEdge(G, i, j);
    }
}

int main()
{
    Graph* G = createGraph(5, 7);
    createADJlise(G);
    run(G);
    return 0;
}