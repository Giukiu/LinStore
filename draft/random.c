#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct BSTnode{
    int value;
    struct BSTnode* right;
    struct BSTnode* left;
};
struct BSTnode* getNode(int data)
{
    struct BSTnode* newNode = (struct BSTnode*)malloc(sizeof(struct BSTnode));
    newNode->value = data;
    newNode->right = newNode->left = NULL;
    return newNode;
}
struct BSTnode* insert(struct BSTnode* root, int data)
{
    if (root == NULL) root = getNode(data);
    else if (data <= root->value){
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct BSTnode* root)
{
    if (root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d  ", root->value);
    inorder(root->right);
}
int main()
{
    int randomArray[11];
    struct BSTnode* root = NULL;
    srand(time(0));
    for (int i = 0; i < 11; i++){
        int randData = rand() % 100 + 1;
        randomArray[i] = randData;
    }
    for (int i = 0; i < 11; i++){
        printf("%d  ", randomArray[i]);
        root = insert(root, randomArray[i]);
    }
    printf("\n");
    inorder(root);
    return 0;
}