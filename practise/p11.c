#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findMin(int key[5], bool mst[5])
{
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < 5; i++) {
        if (key[i] < min && !mst[i]) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void printMST(int parent[5], int graph[5][5])
{
    for (int i = 1; i < 5; i++) {
        printf("%d -- %d weight %d\n", i, parent[i], graph[i][parent[i]]);
    }
}
void primMST(int graph[5][5])
{
    int parent[5];
    int key[5];
    bool mst[5];
    
    for (int i = 0; i < 5; i++) {
        mst[i] = false;
        key[i] = INT_MAX;
    }
    key[0] = 0; parent[0] = -1;
    for (int i = 0; i < 4; i++) {
        int min = findMin(key, mst);
        mst[min] = true;
        for(int j = 0; j < 5; j++) {
            if (graph[min][j] && !mst[j] && graph[min][j] < key[j]) {
                parent[j] = min;
                key[j] = graph[min][j];
            }
        }
    }
    printMST(parent, graph);
}
int main()
{
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}