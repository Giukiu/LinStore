#include <stdio.h>
#include <stdlib.h>
#define max 23
typedef struct link{
    int ls[max];
    int num;
}link;

void initlin(link* Lin)
{
    Lin->num = 0;
}
void insert(link* Lin, int index, int e)
{
    if (index > Lin->num || index < 0) {
        printf("Index error\n");
        return;
    }
    if (Lin->num == 0) {
        Lin->ls[0] = e;
    }else {
        for (int i = Lin->num; i > index; i--) {

            Lin->ls[i] = Lin->ls[i - 1];
        }
        Lin->ls[index] = e;
    }
    Lin->num++;
}
void del(link* Lin, int index)
{
    for (int i = index; i < Lin->num; i++) {
        Lin->ls[i] = Lin->ls[i + 1];
    }
    Lin->num--;
}
void change(link* Lin, int index, int e)
{
    if (index > Lin->num || index < 0) {
        printf("Index error\n");
        return;
    }
    Lin->ls[index] = e;
}
void print(link *Lin)
{
    for (int i = 0; i < Lin->num; i++) {
        printf("%d ", Lin->ls[i]);
    }
    printf("\n");
}
int main()
{
    link Lin;
    initlin(&Lin);
    insert(&Lin, 0, 13);
    insert(&Lin, 0, 5);
    insert(&Lin, 1, 3);
    print(&Lin);
    del(&Lin , 2);
    change(&Lin, 0, 8);
    print(&Lin);
    
    return 0;
}