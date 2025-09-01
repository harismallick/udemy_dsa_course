#include <stdio.h>
#include <stdlib.h>
#include "array_adt.h"

int main()
{
    // Find duplicate elements in an unsorted array.
    // Using a bit map is the most time efficient, at the cost of more space

    List arr = {{8,3,6,4,6,5,6,8,2,7}, 20, 10};
    int arr_max = list_max(&arr);
    int* bitmap = (int *)calloc(arr_max+1, sizeof(int));

    for (int i = 0; i < arr.length; i++)
    {
        bitmap[arr.array[i]]++;
    }

    for (int j = 0; j <= arr_max; j++)
    {
        if (bitmap[j] > 1)
        {
            printf("%d instance of %d\n", bitmap[j], j);
        }
    }
    free(bitmap);
    bitmap = NULL;

    return 0;
}