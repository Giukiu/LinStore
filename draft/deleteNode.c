#include <stdlib.h>
#include <stdio.h>
#include <time.h>
struct node{
    int value;
    struct node* right;
    struct node* left;
};

struct node* getNode(int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->value = data;
    new->right = new->left = NULL;
    return new;
}
struct node* initializeTree(struct node* root, int data)
{
    if (root == NULL){
        root = getNode(data);
    }
    else if (data <= root->value){
        root->left = initializeTree(root->left, data);
    }
    else{
        root->right = initializeTree(root->right, data);
    }
    return root;
}

void inorderTree(struct node* root)
{
    if (root == NULL){
        return;
    }
    inorderTree(root->left);
    printf("%d  ", root->value);
    inorderTree(root->right);
}

void initializeArray(int array[], int size)
{
    for (int i = 0; i < size; i++){
        int enter;
        scanf("%d", &enter);
        array[i] = enter;
    }
}

struct node* getTree(struct node* root, int array[], int size)
{
    root = initializeTree(root, 20);
    for (int i = 0; i < size ; i++){
        
        root = initializeTree(root, array[i]);
    }
    return root;
}

struct node* findMin(struct node* root)
{
    if (root->left == NULL){
        return root;
    }
    root = findMin(root->left);
}
struct node* delete(struct node* root, int data)
{
    if (root == NULL) return root;
    else if (data < root->value){
        root->left = delete(root->left, data);
    }
    else if (data > root->value){
        root->right = delete(root->right, data);
    }
    else{
        if (root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if (root->left == NULL){
            struct node* temp = root;
            root = root->right;
            free(temp);     
            }
         else if (root->right == NULL){
            struct node* temp = root;
            root = root->left;
            free(temp);     
            }
        else{
            struct node* temp = findMin(root->right);
            root->value = temp->value;
            root->right = delete(root->right, temp->value);
        }
    }
    return root;
}
int main()
{
    struct node* root = NULL;
    int size = 10;
    int array[10] = {15, 36, 13, 18, 37, 7, 14, 16, 19, 1};
    //initializeArray(array, 10);
    root = getTree(root, array, size);
    inorderTree(root);
    root = delete(root, 15);
    printf("\n");
    inorderTree(root);
    return 0;
}