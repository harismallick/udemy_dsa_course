#include <stdio.h>

// The order of operations matter greatly in a recursive function.
// The example shown here illustrates the difference between the two.
void print_num_reverse(int n);
void print_num_forward(int n);
int recursive_sum(int n);

int main() {
    printf("Operation first, then recursion:\n");
    print_num_reverse(5);
    printf("Recursion first, then operation:\n");
    print_num_forward(5);
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