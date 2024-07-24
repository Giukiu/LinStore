#include <stdio.h>
#include <stdlib.h>

/* Create a linkde list to store the integers entered by the user. */
struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node* p, int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (p == NULL){
        p = temp;
        p->next = NULL;
        return p;
    }
    struct node* t = p;
    while (t->next != NULL){
        t = t->next;
    }
    t->next = temp;
    return p;
}

struct node* createLinked(struct node* p, int x)
{
    for (int i = 0; i < x; i++){
        int a;
        printf("Enter the number:  ");
        scanf("%d", &a);
        p = insert(p, a);
    }
    return p;
}

void Print(struct node* p)
{
    if (p == NULL) return;
    printf("%d  ", p->data);
    Print(p->next);

}
int main(void)
{
    struct node* head = NULL;
    int x;
    printf("Enter linked size: ");
    scanf("%d", &x);
    head = createLinked(head, x);
    printf("The linked list is:  ");
    Print(head);
    return 0;
}