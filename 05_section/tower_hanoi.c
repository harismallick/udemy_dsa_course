#include <stdio.h>

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod);

int main()
{
    int n = 3;
    tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
}

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n > 0)
    {
        tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, aux_rod);
        tower_of_hanoi(n - 1, to_rod, from_rod, aux_rod);
    }
}