#include <stdio.h>
#include <stdlib.h>
/*哈夫曼树的构造*/
typedef struct HuffmanNode{
    int weight;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
}HF;
HF* create(int weight)
{
    HF* newNode = malloc(sizeof(HF));
    newNode->weight = weight;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int findMin(HF** nodes, int n, int exclude) 
{
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (i == exclude || nodes[i] == NULL) continue;
        if (minIndex == -1 || nodes[minIndex]->weight > nodes[i]->weight) {
            minIndex = i;
        }
    }
    return minIndex;
}
HF* buildHF(int* weight, int n)
{
    int t = 2 * n - 1;
    HF** nodes = malloc(sizeof(HF*) * t);
    for (int i = 0; i < n; i++) {
        nodes[i] = create(weight[i]);
    }
    while (n < t) {
        int min1 = findMin(nodes, n, -1);
        int min2 = findMin(nodes, n, min1);
        HF* newNode = malloc(sizeof(HF));
        newNode->weight = nodes[min1]->weight + nodes[min2]->weight;
        newNode->left = nodes[min1];
        newNode->right = nodes[min2];

        nodes[min1] = nodes[min2] = NULL;
        nodes[n++] = newNode;
    }
    return nodes[n - 1];
}
void printHF(HF* root) 
{
    if (root == NULL) {
        return;
    }
    printHF(root->left);
    printf("%d ", root->weight);
    printHF(root->right);
}
int main()
{
    int weight[] = {2, 4, 6, 9, 24, 12, 21};
    int n = sizeof(weight) / sizeof(weight[0]);
    HF* root = buildHF(weight, n);
    printHF(root);
    return 0;
}