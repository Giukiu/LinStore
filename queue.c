#include <stdio.h>
#include <stdlib.h>
/*Use linked list to implement queue*/

struct node
{
    int value;
    struct node* pre;
    struct node* next;
};
struct node* head = NULL;
struct node* end = NULL;

struct node* enQ(int i)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->value = i;
    new->pre = NULL;
    
    if (end == NULL){
        end = new;
        new->next = NULL;
        head = new;
        return end;
    }
    new->next = end;
    end->pre = new;
    end = new;
    return end;
}

struct node* outQ()
{
    struct node* temp = head;
    head = head->pre;
    return temp;
}
void print()
{
    if (end == NULL)
        return;
    printf("%d  ", end->value);
    end = end->next;
    print();
}
int main(void)
{
    for (int i = 0; i < 5; i++){
        enQ(i);
    }
    enQ(8);
    enQ(9);
    print();
    outQ();
    outQ();
    int q = outQ()->value;
    printf("\n%d", q);
    return 0;
}