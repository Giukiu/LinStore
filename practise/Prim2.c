#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAXVEX 100  // 最大顶点数
#define INFINITY INT_MAX

typedef char VertexType;        // 顶点的数据类型
typedef int EdgeType;           // 边的权值类型

// 图的邻接矩阵结构
typedef struct {
    VertexType vexs[MAXVEX];    // 顶点表
    EdgeType arcs[MAXVEX][MAXVEX]; // 邻接矩阵
    int vexnum, arcnum;         // 顶点数和边数
} AMGraph;

// 辅助结构体：用于 Prim 算法
typedef struct {
    int adjvex;     // 与当前结点相连的顶点编号
    int lowcost;    // 权值（最小代价）
} CloseEdge;

// 查找顶点在数组中的位置
int LocateVex(AMGraph G, VertexType v) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (G.vexs[i] == v) return i;
    }
    return -1;
}

// Prim 最小生成树算法实现
void MiniSpanTree_Prim(AMGraph G, VertexType start) {
    CloseEdge closedge[MAXVEX];
    int k = LocateVex(G, start);  // 起始点编号

    // 初始化 closedge[]
    for (int j = 0; j < G.vexnum; ++j) {
        if (j != k) {
            closedge[j].adjvex = k;
            closedge[j].lowcost = G.arcs[k][j];
        }
    }
    closedge[k].lowcost = 0;  // 起点加入 U 集合

    // 构建最小生成树，其实就是添加 n-1 条边
    for (int i = 1; i < G.vexnum; ++i) {
        int min = INFINITY;
        for (int j = 0; j < G.vexnum; ++j) {
            if (closedge[j].lowcost != 0 && closedge[j].lowcost < min) {
                min = closedge[j].lowcost;
                k = j;
            }
        }

        // 输出当前最小边
        printf("%c - %c  weight: %d\n",
               G.vexs[closedge[k].adjvex], G.vexs[k], closedge[k].lowcost);

        closedge[k].lowcost = 0;  // 将顶点 k 加入 U 集合

        // 更新 closedge 中的信息
        for (int j = 0; j < G.vexnum; ++j) {
            if (G.arcs[k][j] < closedge[j].lowcost && closedge[j].lowcost != 0) {
                closedge[j].adjvex = k;
                closedge[j].lowcost = G.arcs[k][j];
            }
        }
    }
}

// 创建一个测试图（邻接矩阵）
void CreateTestGraph(AMGraph* G) {
    G->vexnum = 5;
    G->arcnum = 7;
    G->vexs[0] = 'A';
    G->vexs[1] = 'B';
    G->vexs[2] = 'C';
    G->vexs[3] = 'D';
    G->vexs[4] = 'E';

    // 初始化矩阵
    for (int i = 0; i < G->vexnum; ++i) {
        for (int j = 0; j < G->vexnum; ++j) {
            if (i == j)
                G->arcs[i][j] = 0;
            else
                G->arcs[i][j] = INFINITY;
        }
    }

    // 添加边（无向图）
    G->arcs[0][1] = G->arcs[1][0] = 2;
    G->arcs[0][3] = G->arcs[3][0] = 6;
    G->arcs[1][2] = G->arcs[2][1] = 3;
    G->arcs[1][3] = G->arcs[3][1] = 8;
    G->arcs[1][4] = G->arcs[4][1] = 5;
    G->arcs[2][4] = G->arcs[4][2] = 7;
    G->arcs[3][4] = G->arcs[4][3] = 9;
}

int main() {
    AMGraph G;
    CreateTestGraph(&G);

    printf("Prim :\n");
    MiniSpanTree_Prim(G, 'A');  // 从顶点 'A' 开始

    return 0;
}