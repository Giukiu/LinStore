#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // 图中顶点数量

// 找出 key[] 中未被加入 MST，值最小的顶点
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// 打印构建出的最小生成树的边和权值
void printMST(int parent[], int graph[V][V]) {
    printf("Edge  weigh\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Prim 算法核心函数
void primMST(int graph[V][V]) {
    int parent[V];      // 保存最小生成树
    int key[V];         // 最小权值初始化为无穷大
    bool mstSet[V];     // mstSet[i] 为 true 表示顶点 i 已包含在 MST 中

    // 初始化
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // 从顶点 0 开始
    key[0] = 0;
    parent[0] = -1; // 起点没有父节点

    // 构建 MST
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);  // 取未加入MST的最小key顶点
        mstSet[u] = true;

        // 更新相邻顶点的 key 和 parent
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // 打印结果
    printMST(parent, graph);
}

// 主函数
int main() {
    // 图的邻接矩阵表示
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}