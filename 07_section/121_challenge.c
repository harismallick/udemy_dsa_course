#include<stdio.h>
#include "array_adt.h"

int main()
{
    // Find the single missing element in a sorted array of n natural numbers
    List arr1 = {{1,2,3,4,5,6,8,9,10}, 20, 9};

    // Scenario 1: The array starts from 1
    int sum_of_n = arr1.array[arr1.length-1] * (arr1.array[arr1.length-1] + 1) / 2;
    printf("sum of 10 natural numbers is: %d\n", sum_of_n);
    int sum = list_sum(&arr1);
    printf("sum of the elements in the list is: %d\n", sum);
    if (sum != sum_of_n)
    {
        printf("The missing number in this list is %d\n", sum_of_n - sum);
    }

    // Scenario 2: The sorted array does not start from 1
    List arr2 = {{6,7,8,9,10,11,13,14,15,16,17}, 20, 11};
    // Implementation 1: calculating the difference between the projected sum and
    // the actual sum
    int sum_till_array_end = arr2.array[arr2.length-1] * (arr2.array[arr2.length-1] + 1) / 2;
    int num_before_list = arr2.array[0] - 1;
    int sum_till_array_start = num_before_list * (num_before_list + 1) / 2;
    int projected_sum_array = sum_till_array_end - sum_till_array_start;
    sum = list_sum(&arr2);
    if (sum != projected_sum_array)
    {
        printf("The missing number in this list is %d\n", projected_sum_array - sum);
    }

    // Implementation 2: Calculating the difference between the number and its index.
    // The difference should remain constant if there is no number missing.
    int i = 0;
    int diff = arr2.array[0] - i;
    for (; i < arr2.length; i++)
    {
        if (arr2.array[i] - i != diff)
        {
            printf("The missing number is %d\n", diff + i);
            break;
        }
    }

    return 0;
}