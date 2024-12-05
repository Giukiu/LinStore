# include <stdio.h>
# include <stdlib.h>
# define size 3
struct linkNode* stackTop = NULL;
struct linkNode* queue = NULL;

struct linkNode{
    int value;
    struct linkNode* next;
};
struct bstNode{
    int value;
    struct bstNode* right;
    struct bstNode* left;
};

struct linkNode* getLinkNode(int data)
{
    struct linkNode* newNode = (struct linkNode*)malloc(sizeof(struct linkNode));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}
struct linkNode* linkInsert_(struct linkNode* head, int data)
{
    if (head == NULL){
        head = getLinkNode(data);
        return head;
    }
    struct linkNode* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = getLinkNode(data);
    return head;
}
struct linkNode* linkInsert(struct linkNode* head, int array[])
{
    for (int i = 0; i < size; i++){
        head = linkInsert_(head, array[i]);
    }
    return head;
}
void traverseLinked(struct linkNode* head)
{
    if (head == NULL){
        return;
    }
    printf("%d  ", head->value);
    traverseLinked(head->next);
}

struct linkNode* createStack(int data)
{
    if (stackTop== NULL){
        stackTop = getLinkNode(data);
        return;
    }
    struct linkNode* temp = getLinkNode(data);
    temp->next = stackTop;
    stackTop = temp;

}
struct linkNode* stackInsert(struct linkNode* head)
{
    for (int i = 0; i < size; i++){
    stackTop = createStack(head->value);
    head = head->next;
 }
    return;
}
int Pop()
{
    if (stackTop == NULL){
        printf("The stack is empty...");
        return;
    }
    int data = stackTop->value;
    stackTop = stackTop->next;
    return data;
}

struct linkNode* queuePush(int data)
{
    if (queue == NULL){
        queue = getLinkNode(data);
        return;
    }
    struct linkNode* temp = queue;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = getLinkNode(data);
}
struct linkNode* queueInsert()
{
    for (int i = 0; i < size; i++){
        int data = Pop();
        queuePush(data);
    }
}
int queuePop()
{
    if (queue == NULL){
        printf("The queue is empty..");
        return;
    }
    int data = queue->value;
    queue = queue->next;
    return data;
}

struct bstNode* getBstNode(int data)
{
    struct bstNode* new = (struct bstNode*)malloc(sizeof(struct bstNode));
    new->value = data;
    new->left = new->right = NULL;
    return new;
}
struct bstNode* treePush_(struct bstNode* Tree,int data)
{
    if (Tree == NULL){
        Tree = getBstNode(data);
    }
    else if (data < Tree->value){
        Tree->left = treePush_(Tree->left, data);
    }
    else {
        Tree->right = treePush_(Tree->right, data);
    }
    return Tree;
}
struct bstNode* treePush(struct bstNode* Tree)
{
    for (int i = 0; i < size; i++){
        int data = queuePop();
        Tree = treePush_(Tree, data);
    }
    return Tree;
}
void inorderTree(struct bstNode* Tree)
{
    if (Tree == NULL){
        return;
    }
    inorderTree(Tree->left);
    printf("%d  ", Tree->value);
    inorderTree(Tree->right);
}
int main()
{
    int array[size] = {1, 2, 4};
    struct linkNode* linkHead = NULL;
    linkHead = linkInsert(linkHead, array);
    printf("This is a linked list: ");
    traverseLinked(linkHead);
    
    
    stackInsert(linkHead);
    printf("\nThis is a stack: ");
    traverseLinked(stackTop);

    queueInsert();
    printf("\nThis is a queue: ");
    traverseLinked(queue);

    struct bstNode* Tree = NULL;
    Tree = treePush(Tree);
    printf("\n");
    inorderTree(Tree);
    return 0; 

}
