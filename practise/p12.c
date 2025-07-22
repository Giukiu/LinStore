#include <stdio.h>
#include <stdalign.h>
#define max 100

typedef struct Graph{
    char vertices[max];
    int arcs[max][max];
    int numVex, numArc;
}G;
typedef struct{
    int adjvex;
    int weight;
}Edge;

void createGraph(G* graph)
{
    graph->numVex = 5;
    graph->numArc = 7;
    char names[] = "ABCDE";
    for (int i = 0; i < graph->numVex; i++) {
        graph->vertices[i] = names[i];
    }
}