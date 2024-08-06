#include <stdio.h>
#include <stdlib.h>

struct bstNode{
    int data;
    struct bstNode* left;
    struct bstNode* right;
};

struct bstNode* getNode(int x)
{
    struct bstNode* newNode = (struct bstNode*)malloc(sizeof(struct bstNode));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct bstNode* insert(struct bstNode* r, int x)
{
    if (r == NULL){
        r = getNode(x);
    }
    else if (x <= r->data){
        r->left = insert(r->left, x);
    }
    else {
        r->right = insert(r->right, x);
    }
    return r;
}
_Bool search(struct bstNode* r, int x){
    if (r == NULL) return 0;
    else if (r->data == x) return 1;
    else if (x < r->data) return search(r->left, x);
    else return search(r->right, x);
}
int main(void)  /*Implement a simple binary tree in C*/
{
    struct bstNode* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 16);
    if (search(root, 16)) printf("Found");
    else printf("Not found");
    return 0;
}