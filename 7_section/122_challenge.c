#include<stdio.h>
#include "array_adt.h"

int main()
{
    // Find multiple missing elements in a list of sorted natural numbers
    List arr1 = {{6,7,8,9,11,12,15,16,17,18,19}, 20, 11};
    // Implementation 1: Calculate the diff between the index and number.
    // The diff will increase for each missing number in the series.
    int i = 0;
    int diff = arr1.array[0] - i;
    for (; i < arr1.length; i++)
    {
        if (diff != arr1.array[i] - i)
        {
            while (diff < arr1.array[i] - i)
            {
                printf("This number is missing in the list: %d\n", diff + i);
                diff++;
            }
        }
    }
    return 0;
}