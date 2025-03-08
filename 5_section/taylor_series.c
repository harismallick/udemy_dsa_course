#include <stdio.h>
#include "power.h"
#include "factorial.h"
#include "sum_n_nums.h"

double e(int x, int n);
double e2(int x, int n);

int main()
{
    int x = 2;
    int n = 10;
    printf("e^%d using %d terms is: %lf\n", x, n, e(x, n));
    // result using many recursive functions combined:
    printf("e^%d using %d terms is: %lf\n", x, n, e2(x, n));
    return 0;
}

double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}

double e2(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return e2(x, n - 1) + ((double)power(x, n) / (double)factorial(n));
}
// Output: e^2 using 4 terms is: 7.000000
// Explanation: The Taylor series expansion of e^x is given by:
// e^x = 1 + x/1! + x^2/2! + x^3/3! + x^4/4! + ... + x^n/n!
// The function e(x, n) calculates the value of e^x using n terms of the Taylor series expansion.
// The function uses static variables p and f to store the values of x^n and n! respectively.
// The function recursively calculates the value of e^x using the formula:
// e(x, n) = e(x, n-1) + x^n/n!
// The function returns the value of e^x using n terms of the Taylor series expansion.
// The main function calls the e function to calculate e^2 using 4 terms of the Taylor series expansion and prints the result.