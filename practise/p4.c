#include <stdio.h>
#include <stdlib.h>
typedef struct arc{
    int adjvex;
    struct arc* nextarc;
}arcNode;
typedef struct Vnode{
    char vex;
    arcNode* first;
}Vnode;
typedef struct Graph{
    Vnode** adj;
    int Vnum, Enum;
}Graph;

Graph* createG(int v, int e)
{
    Graph* G = malloc(sizeof(Graph));
    G->Enum = e;
    G->Vnum = v;
    G->adj = malloc(sizeof(Vnode*) * v);
    return G;
}
Vnode* createVnode(char a)
{
    Vnode* newNode = malloc(sizeof(Vnode));
    newNode->first = NULL;
    newNode->vex = a;
    return newNode;
}
void createList(Graph* G)
{
    char Vertices[] = "0123456789";
    for (int i = 0; i < G->Vnum; i++) {
        G->adj[i] = createVnode(Vertices[i]);
    }
}
void createEdge(Graph* G, int src, int dex)
{
    arcNode* temp = malloc(sizeof(arcNode));
    temp->adjvex = dex;
    temp->nextarc = G->adj[src]->first;
    G->adj[src]->first = temp;
    printf("%d->%d complished\n", src, dex);

}

int main()
{
    Graph* G = createG(5, 7);
    createList(G);
    
    return 0;
}