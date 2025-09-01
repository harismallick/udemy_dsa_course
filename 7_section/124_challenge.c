#include <stdio.h>
#include <stdlib.h>
#include "array_adt.h"

const int SIZE = 20;

int main()
{
    // Find and provide a count of the duplicate elements in a sorted array

    List arr1 = {{3,6,8,8,10,12,15,15,15,20}, SIZE, 10};
    int dups_tracker[SIZE][2] = {};
    int dups_tracker_length = 0;

    int dups_counter = 1;
    int duplicate = arr1.array[0];

    for (int i = 1; i < arr1.length; i++)
    {
        if (arr1.array[i] == duplicate)
        {
            dups_counter++;
        }
        else if (dups_counter > 1)
        {
            dups_tracker[dups_tracker_length][0] = duplicate;
            dups_tracker[dups_tracker_length][1] = dups_counter;
            dups_tracker_length++;
            dups_counter = 1;
            duplicate = arr1.array[i];
        }
        else
        {
            duplicate = arr1.array[i];
        }
    }

    printf("The following duplicates were found in the given array:\n");
    for (int j = 0; j < dups_tracker_length; j++)
    {
        printf("%d instances of %d\n", dups_tracker[j][1], dups_tracker[j][0]);
    }

    return 0;
}