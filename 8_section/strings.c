#include <stdio.h>

void lesson_131();

int main()
{
    lesson_131();
    return 0;
}

void lesson_131()
{
    char x[] = {'a', 'b', 'c', 'd', 'e'};
    char y[5] = {'a', 'b', 'c', 'd', 'e'}; 
    char z[5] = {97, 98, 99, 100, 101};
    
    // %c formatter prints the character
    printf("%c\n", x[1]);
    printf("%c\n", y[1]);
    printf("%c\n", z[1]);

    // %d prints the ASCII of the character
    printf("%d\n", x[1]);
    printf("%d\n", y[1]);
    printf("%d\n", z[1]);
}