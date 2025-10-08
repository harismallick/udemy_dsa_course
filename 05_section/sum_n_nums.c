#include <stdio.h>

int sum(int n);

// int main()
// {
//     int n = 7;
//     //O(n) linear time complexity solution:
//     printf("Sum of all natural numbers to %d is: %d\n", n, sum(n));

//     //O(1) constant time complexity solution:
//     int sum = n * (n + 1) / 2;
//     printf("Sum of all natural numbers to %d is: %d\n", n, sum);
//     return 0;
// }

int sum(int n)
{
    if (n ==0)
    {
        return 0;
    }
    return n + sum(n - 1);
}