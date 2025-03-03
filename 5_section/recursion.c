#include <stdio.h>

// The order of operations matter greatly in a recursive function.
// The example shown here illustrates the difference between the two.
void print_num_reverse(int n);
void print_num_forward(int n);
int recursive_sum(int n);
int recursive_sum_static_var(int n);
void tree_recursion(int n);
void indirect_recursion_a(int n);
void indirect_recursion_b(int n);
int nested_recursion(int n);


int main() {
    // printf("Operation first, then recursion:\n");
    // print_num_reverse(5);
    // printf("Recursion first, then operation:\n");
    // print_num_forward(5);
    
    // printf("Sum of 5: %d\n", recursive_sum(5));
    // printf("Sum of 5 with static variable: %d\n", recursive_sum_static_var(5));
    
    tree_recursion(3);
    printf("\n");
    indirect_recursion_a(20);
    printf("\n");
    int output = nested_recursion(95);
    printf("Result of nested recursion: %d\n", output);
    return 0;
}

void print_num_reverse(int n) {
    if (n == 0) {
        return;
    }
    printf("%d\n", n);
    print_num_reverse(n - 1);
}

void print_num_forward(int n) {
    if (n == 0) {
        return;
    }
    print_num_forward(n - 1);
    printf("%d\n", n);
}

int recursive_sum(int n) {
    if (n == 0) {
        return 0;
    }
    return n + recursive_sum(n - 1);
}

int recursive_sum_static_var(int n) {
    // static variables are initialized only once.
    static int x = 0;
    if (n == 0) {
        return 0;
    }
    x++;
    return x + recursive_sum_static_var(n - 1);
}

void tree_recursion(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        tree_recursion(n - 1);
        tree_recursion(n - 1);
        // tree_recursion(n - 1);
    }
}

void indirect_recursion_a(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        indirect_recursion_b(n - 1);
    }
}

void indirect_recursion_b(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        indirect_recursion_a(n / 2);
    }
}

int nested_recursion(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return nested_recursion(nested_recursion(n + 11));
    }
}