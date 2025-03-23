#include<stdio.h>

void q2();

int main()
{
    q2();
    return 0;
}

void q2()
{
    unsigned int x[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    printf("%u,%u, %u, %d\n", x+3, *(x+3),*(x+2)+3, *(*(x + 3)));
}