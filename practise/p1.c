#include <stdio.h>
#include <stdlib.h>
/*线索二叉树的构建*/

typedef struct ThreadTreeNode{
    int data;
    struct ThreadTreeNode* left, *right;
    int L, R;
}Tnode;
void init(Tnode* root)
{
    root->data = 16;
    root->L = root->R = 0;
    root->left = root->right = NULL;
}
Tnode* getNode(int e)
{
    Tnode* new = (Tnode*)malloc(sizeof(Tnode));
    new->data = e;
    new->left = new->right = NULL;
    return new;
}
Tnode* creat(Tnode* root, int e)        /*递归建立一棵普通二叉树*/
{
    if (!root) return root = getNode(e);
    if (e < root->data) {
        root->left = creat(root->left, e);
    }else {
        root->right = creat(root->right, e);
    }
}
void input(Tnode* root, int* array)
{
    int i = 0;
    while (array[i]) {
        creat(root, array[i]);
        i++;
    }
}
void Print(Tnode* root)     /*递归中序遍历普通二叉树*/
{
    if (!root) return;

    Print(root->left);
    printf("%d ", root->data);
    Print(root->right);
}
Tnode* pre = NULL;
void inorder(Tnode* root)       /*二叉树的中序线索化*/
{
    if (root != NULL) {
        inorder(root->left);
        root->L = root->R = 0;
        if (!root->left) {
            root->left = pre;
            root->L = 1;    
        } 
        else if (pre != NULL && pre->right == NULL) {
            pre->right = root;
            pre->R = 1;
        }
        pre = root;
        inorder(root->right);
    }  
   
}
void P(Tnode* r)           /*遍历线索二叉树*/
{  
    while (r && r->L == 0) {
    r = r->left;
   }
   while (r) {
    printf("%d ", r->data);
    if (r->R == 1) {
        r = r->right;
    }else {
        r = r->right;
        while (r && r->L == 0) {
            r = r->left;
        }
    }
   }
}
   
int main()
{
    Tnode* root = (Tnode*)malloc(sizeof(Tnode));
    init(root);
    int array[21] = {10, 25, 8, 13, 17, 28, 5, 9, 12, 14, 15, 19, 4, 7, 6};
    input(root, array);
    
    inorder(root);
    P(root);
    return 0;
}