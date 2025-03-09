// Here we look at implelemting the combination formula to find now many ways we can choose r items from n items.
// The combination formula is given by:
// nCr = n! / (r! * (n-r)!)

// The number of combinations can also be calculated resursively using the pascal triangle.

#include <stdio.h>
#include "factorial.h"

int combination(int n, int r);
int combination_pascal(int n, int r);

int main()
{
    int n = 5;
    int r = 2;
    printf("The number of ways to choose %d items from %d items is: %d\n", r, n, combination(n, r));
    printf("The result using %d as n and %d as r by checking Pascal's triangle: %d\n", r, n, combination_pascal(n, r));
    return 0;
}

int combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int combination_pascal(int n, int r)
{
    if (r == 0 || r == n)
    {
        return 1;
    }
    return combination_pascal(n - 1, r - 1) + combination_pascal(n - 1, r);
}