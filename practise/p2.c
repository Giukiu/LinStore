#include <stdio.h>
#include <stdlib.h>
/*哈夫曼树的构建*/
typedef struct HuffmanNode{
    int weight;
    struct HuffmanNode* right;
    struct HuffmanNode* left;
}Huffman;
Huffman* createNode(int weight) 
{
    Huffman* node = (Huffman*)malloc(sizeof(Huffman));
    node->weight = weight;
    node->left = node->right = NULL;
    return node;
}
int findMin(Huffman** nodes, int n, int exclude)
{
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (i == exclude || nodes[i] == NULL) {
            continue;
        }
        if (minIndex == -1 || nodes[i]->weight < nodes[minIndex]->weight) {
            minIndex = i;
        }
    }
    return minIndex;
}
Huffman* build(int weights[], int n)
{
    int t = 2 * n - 1;
    Huffman** nodes = (Huffman**)malloc(sizeof(Huffman*) * t);
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(weights[i]);
    }
    while (n < t) {
        int min1 = findMin(nodes, n, -1);
        int min2 = findMin(nodes, n, min1);

        Huffman* new = createNode(nodes[min1]->weight +nodes[min2]->weight);
        new->left = nodes[min1];
        new->right = nodes[min2];

        nodes[min1] = NULL;
        nodes[min2] = NULL;
        nodes[n++] = new;
    }
    return nodes[n - 1];
}
void printHuffman(Huffman* root) {
    if (root == NULL) return;
    printHuffman(root->left);
    printf("%d ", root->weight);
    printHuffman(root->right);
}
int main()
{
    int weights[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(weights) / sizeof(weights[0]);
    Huffman* root = build(weights, n);
    printHuffman(root);
    return 0;
}