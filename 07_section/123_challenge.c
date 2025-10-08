#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "array_adt.h"

int main()
{
    // Find missing elements in an unsorted array of natural numbers.
    // Use a helper bool array to mark which numbers were present in the numbers list.
    List arr1 = {{3,7,4,9,12,6,1,11,2,10}, 20, 10};
    int max_num = list_max(&arr1);
    bool* present = (bool *)calloc(max_num + 1, sizeof(bool));
    int i = 0;
    for (;i < arr1.length; i++)
    {
        present[arr1.array[i]] = true;
    }

    // Check which numbers were missing:
    int min_num = list_min(&arr1);
    for (i = min_num; i < max_num+1; i++)
    {
        if (!present[i])
        {
            printf("This number is missing in the list: %d\n", i);
        }
    }
    free(present);
    present = NULL;

    return 0;
}