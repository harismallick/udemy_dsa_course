#include<stdio.h>

int q1(int n);
int q3(int *x, int c);
int q4(int n);

int main()
{
    //Q1 run:
    printf("Q1 Result: %d\n", q1(1));
    // Q3 run:
    int x = 5;
    int result = q3(&x, 5);
    printf("Q3 Result: %d\n", result);
    // Q4 run:
    printf("Q4 Result: %d\n", q4(5));
    return 0;
}

int q1(int n)
{
    static int i = 1;
    if (n >= 5)
    {
        return n;
    }
    n = n + i;
    i++;
    return q1(n);
}

int q3(int *x, int c)
{
    c = c - 1;
    if (c == 0)
    {
        return 1;
    }
    *x = *x + 1;
    return q3(x, c) * *x;
}


int q4(int n)
{
    int x = 1, k;
    for (k = 1; k < n; ++k)
    {
        x = x + q4(k) * q4(n - k);
    }
    return x;
}