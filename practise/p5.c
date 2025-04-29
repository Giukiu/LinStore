#include <stdio.h>
#include <stdlib.h>
typedef struct HuffmanTreeNode{
    int weight;
    struct HuffmanTreeNode* left;
    struct HuffmanTreeNode* right;
}HF;
HF* create(int e)
{
    HF* newNode = malloc(sizeof(HF));
    newNode->weight = e;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int findMin(HF** nodes, int n, int exclude) 
{
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (!nodes[i] || exclude == i) continue;
        if (minIndex == -1 || nodes[i]->weight < nodes[minIndex]->weight) {
            minIndex = i;
        }
    }
    return minIndex;
}
HF* build(int* weight, int n)
{
    int capacity = 2 * n - 1;
    HF** nodes = malloc(sizeof(HF*) * capacity);
    for (int i = 0; i < n; i++) {
        nodes[i] = create(weight[i]);
    }
    while (n < capacity) {
        int min1 = findMin(nodes, n, -1);
        int min2 = findMin(nodes, n, min1);
        HF* sum = create(nodes[min1]->weight + nodes[min2]->weight);
       
        sum->left = nodes[min1];
        sum->right = nodes[min2];
        nodes[min1] = nodes[min2] = NULL;
        nodes[n++] = sum;
    }
    return nodes[n - 1];  
}
void printHF(HF* root)
{
    if (root == NULL) return;
    printHF(root->left);
    printf("%d ", root->weight);
    printHF(root->right);
}
void inspect(HF** nodes, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", nodes[i]->weight);
    }
}
int main()
{
    int weight[] = {4, 6, 3, 1, 7, 8, 12, 2};
    int number = sizeof(weight) / sizeof(weight[0]);
    HF* root = build(weight, number);
    
    printHF(root);
    return 0;
}