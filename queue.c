#include <stdio.h>
#include <stdlib.h>
/*Use linked list to implement queue*/

struct node
{
    int value;
    struct node* next;
};
struct node* head = NULL;
struct node* end = NULL;

struct node* enQ(int i)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->value = i;
    
    if (end == NULL){
        end = new;
        new->next = NULL;
        head = new;
        return end;
    }
    new->next = end;
    end = new;
    return end;
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
    printf("\n%d", head->value);
    return 0;
}