#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_adt.h"


// Challenge: Find all pairs whose sum equals to k
void challenge_128();

int main()
{
    List arr = {{6,3,8,10,16,7,5,2,9,14}, 20, 10};

    // Method 1: O(n^2)
    int i,j;
    i = 0;
    int k = 10;

    printf("Using solution 1:\n");
    for (i; i < arr.length - 1; i++)
    {
        j = i + 1;
        for (j; j < arr.length; j++)
        {
            if (arr.array[i] + arr.array[j] == k)
            {
                printf("%d + %d = %d\n", arr.array[i], arr.array[j], k);
                break;
            }
        }
    }

    // Method 2: O(n) using hashmap

    // Find largest int in the array
    int largest_num = list_max(&arr);
    int* bitmap = (int*)calloc(largest_num + 1, sizeof(int));

    printf("Using solution 2:\n");
    // Add element state to the bitmap
    for (i = 0; i < arr.length; i++)
    {
        int pair = k - arr.array[i];
        if (bitmap[pair])
        {
            printf("%d + %d = %d\n", arr.array[i], pair, k);
        }
        bitmap[arr.array[i]] = 1;
    }

    // Second pass to find the pairs:
    // for (j = 0; j < arr.length; j++)
    // {
    //     int pair = k - arr.array[j];
    //     if (bitmap[pair])
    //     {
    //         printf("%d + %d = %d\n", arr.array[j], pair, k);
    //     }
    // }
    free(bitmap);
    bitmap = NULL;

    printf("Challenge 128 result:\n");
    challenge_128();
    return 0;
}

void challenge_128()
{
    // Challenge 127, but starting with a sorted array.
    // Becomes a two pointer solution
    List arr = {{1,3,4,5,6,8,9,10,12,14}, 20, 10};
    int i = 0;
    int j = arr.length - 1;
    int k = 10;
    while (i < j)
    {
        if (arr.array[i] + arr.array[j] == k)
        {
            printf("%d + %d = %d\n", arr.array[i], arr.array[j], k);
            i++, j--;
        }
        else if (arr.array[i] + arr.array[j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}