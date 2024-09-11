#include <stdio.h>
#include <stdlib.h>

struct BSTnode{
    int value;
    struct BSTnode* right;
    struct BSTnode* left;
};

struct BSTnode* getNode(int data)
{
    struct BSTnode* new = (struct BSTnode*)malloc(sizeof(struct BSTnode));
    new->value = data;
    new->right = new->left = NULL;
    return new;
}
struct BSTnode* Insert(int data, struct BSTnode* root)
{
    if (root == NULL){
        root = getNode(data);
    }
    else if(data < root->value){
        root->left = Insert(data, root->left);
    }
    else
        root->right = Insert(data, root->right);

    return root;
}

struct BSTnode* findMIN(struct BSTnode* root)
{
    if (root == NULL) printf("The Bst tree is NULL");
    else if (root->left == NULL){
        printf("This tree min data is %d", root->value);     
    }
    else
        return findMIN(root->left);
}

struct BSTnode* findMAX(struct BSTnode* root)
{
    if (root == NULL){
        printf("This tree is NULL");
    }
    else if (root->right == NULL){
        printf("\nThis tree max data is %d", root->value);
    }
    else
        return findMAX(root->right);
}
int main()
{
    struct BSTnode* root = NULL;
    root = Insert(7, root);
    root = Insert(3, root);
    root = Insert(8, root);
    root = Insert(1, root);
    root = Insert(4, root);

    findMIN(root);
    findMAX(root);
    return 0;
}