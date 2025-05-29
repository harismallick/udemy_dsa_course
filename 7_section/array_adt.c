#include<stdio.h>
#include<stdlib.h>

// typedef struct
// {
//     /* data */
//     int *array;
//     int size;
//     int length;
// } List;

typedef struct
{
    int array[20];
    int size;
    int length; // The number of elements currently in the array
} List;

void list_print(List arr);
int list_append(List* arr, int num);
int list_insert(List* arr, int num, int position);

int main()
{
    // Heap memory implementation
    // List arr;
    // printf("Enter the size of your array:\n");
    // scanf("%d", &arr.size);
    // arr.array = (int *)malloc(sizeof(int) * arr.size);
    // arr.length = 0;

    // printf("Enter the length of your array:\n");
    // scanf("%d", &arr.length);

    // for (int i = 0; i < arr.length; i++)
    // {
    //     printf("Enter a number to add to the array:\n");
    //     scanf("%d", &arr.array[i]);
    // }
    // list_print(arr);
    // free(arr.array);

    // Stack memory implementation for demonstration
    List arr = {{1,2,3,4,5}, 20, 5};
    List* arr_p = &arr;
    list_print(arr);
    list_append(arr_p, 6);
    list_print(arr);
    list_insert(arr_p, 8, 3);
    list_print(arr);
    return 0;
}

void list_print(List arr)
{
    printf("[");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d", arr.array[i]);
        if (i != arr.length - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}

int list_append(List* arr, int num)
{
    if (arr->length == arr->size)
    {
        printf("The array is full. Cannot add more elements!");
        return 1;
    }
    // Add feature to allocate more heap memory for list
    arr->array[arr->length] = num;
    arr->length++;
    return 0;
}

int list_insert(List* arr, int num, int position)
{
    if (position >= arr->size || position < 0)
    {
        printf("Insertion position is outside the bounds of the array.");
        return 1;
    }
    if (arr->length == arr->size)
    {
        printf("The array is full. Cannot add more elements!");
        return 1;
    }
    for (int i = arr->length; i > position; i--)
    {
        arr->array[i] = arr->array[i-1];
    }
    arr->array[position] = num;
    arr->length++;
    return 0;
}
