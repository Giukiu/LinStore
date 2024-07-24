#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node* p)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = 3;
    if (p == NULL){
        p = temp;
        p->next = NULL;
        return p;
    }
}
int main(void)
{
    struct node* head = NULL;
    head = insert(head);
    printf("%d", head->data);
    return 0;
}