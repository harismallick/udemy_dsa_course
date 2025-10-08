#include <stdio.h>
#include "array_adt.h"

int main()
{
    // Find the max and min values in an array in a single scan.
    // Two pointer approach, one to track max and one to track the min
    List arr = {{5,8,3,9,6,2,10,7,-1,4}, 20, 10};
    int max_num, min_num;

    max_num = min_num = arr.array[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.array[i] < min_num)
        {
            min_num = arr.array[i];
        }
        else if (arr.array[i] > max_num)
        {
            max_num = arr.array[i];
        }
    }
    printf("Max num: %d\nMin num: %d\n", max_num, min_num);
    
    return 0;
}