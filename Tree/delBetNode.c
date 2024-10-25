#include <stdio.h>
# include <stdlib.h>
struct BSTnode{
    int value;
    struct BSTnode* right;
    struct BSTnode* left;
};

struct BSTnode* getNode(struct BSTnode* root, int data)
{
    struct BSTnode* newNode = (struct BSTnode*)malloc(sizeof(struct BSTnode));
    newNode->value = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct BSTnode* insert(struct BSTnode* root, int data)
{
    if (root == NULL){
        root = getNode(root, data);
        return root;
    }
    else if (data < root->value){
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorderTree(struct BSTnode* root)
{
    if (root == NULL){
        return;
    }
    inorderTree(root->left);
    printf("%d  ", root->value);
    inorderTree(root->right);
}

struct BSTnode* findMAX(struct BSTnode* root)
{
    if (root->right == NULL){
        return root;
    }
    root = findMAX(root->right);
}
struct BSTnode* del(struct BSTnode* root, int data)
{
    if (data < root->value){
        root->left = del(root->left, data);
    }
    else if (data > root->value){
        root->right = del(root->right, data);
    }
    else{
        if (root->right == NULL && root->left == NULL){
            free(root);
            root = NULL;
        }
        else if (root->right == NULL){
            struct BSTnode* temp = root;
            root = root->left;
            free(temp);
        }
        else if (root->left == NULL){
            struct BSTndoe* temp =  root;
            root = root->right;
            free(temp);
        }
        else{
            struct BSTnode* temp = findMAX(root->left);
            root->value = temp->value;
            root->left = del(root->left, temp->value);
        }
    }
    return root;
}
int main()
{
    struct BSTnode* root = NULL;
    int array[10] = {6,  7, 4, 8 ,3, 9, 2, 10, 1, 5};
    for (int i = 0; i < 10; i++){
        root = insert(root, array[i]);
    }
    inorderTree(root);
    root = del(root, 4);
    printf("\n");
    inorderTree(root);
    return 0;
}