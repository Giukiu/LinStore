#include <stdio.h>

int main()
{
    char Vertices[] = "0123456789";
    int c = (int)Vertices[1] - 48 + (int)Vertices[2] - 48;
    printf("%d", c);
    return 0;
}