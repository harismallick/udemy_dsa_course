#include <stdio.h>

int power(int m, int n);
// Optimised solution to reduce the number of multiplications:
int power2(int m, int n);

// int main()
// {
//     int num = 2;
//     int pow = 9;
//     printf("%d raised to the power %d is: %d\n", num, pow, power(num, pow));
//     printf("Result using optimised solution: %d\n", power2(num, pow));
//     return 0;
// }

int power(int m, int n)
{
    if (n ==0)
    {
        return 1;
    }
    return m * power(m, n - 1);
}

int power2(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return power2(m * m, n / 2);
    }
    return m * power2(m * m, (n - 1) / 2);
}