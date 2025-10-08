#include <stdio.h>

unsigned long long int fibonacci(int n);
unsigned long long int fib_iter(int n);
unsigned long long int fib_memo(int n);

int main()
{
    int n = 50;
    // printf("Fibonacci recursively at position %d is: %lld\n", n, fibonacci(n));
    // Without memoization, the recursive function is very slow for large values of n because n^2 recursive calls are being made.
    printf("Fibonacci iteratively at position %d is: %llu\n", n, fib_iter(n));
    // Memoization reduces the number of recursive calls from n^2 to n. This allows the function to calculate the Fibonacci number for large values of n efficiently.
    printf("Fibonacci with memoization at position %d is: %llu\n", n, fib_memo(n));
    return 0;
}

unsigned long long int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned long long int fib_iter(int n)
{
    unsigned long long int num = 2;
    unsigned long long int prev1 = 1;
    unsigned long long int prev2 = 1;
    for (int i = 3; i <= n; i++)
    {
        num = prev1 + prev2;
        prev2 = prev1;
        prev1 = num;
    }
    return num;
}

unsigned long long int fib_memo(int n)
{
    static unsigned long long int memo[100] = {0};
    if (n <= 1)
    {
        return n;
    }
    if (memo[n] != 0)
    {
        return memo[n];
    }
    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    return memo[n];
}