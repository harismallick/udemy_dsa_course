#include<stdio.h>
#include<stdlib.h>

void print_array(int *arr, int size);
int *increase_array_size(int *arr, int current_size, int size_multiplier);
void twoD_array();
void print_2d_array(int arr[][4], int rows, int cols);
int** create_2d_array(int rows, int cols);
void free_2d_array(int** arr, int rows);
void print_dynamic_2d_array(int** arr, int rows, int cols);

int main()
{
    int SIZE = 5;
    int size_multiplier = 2;
    // Array declaration for creating an array in stack memory:
    int arr[5] = {1, 2, 3, 4, 5};
    // The different ways to access array elements:
    printf("The value at index 3 is %d\n", arr[3]);
    printf("The value at index 3 is %d\n", 3[arr]);
    printf("The value at index 3 is %d\n", *(arr + 3));

    // Array in heap memory:
    int *arr2 = (int *)malloc(SIZE * sizeof(int));
    arr2[0] = 6;
    arr2[1] = 7;
    arr2[2] = 8;
    arr2[3] = 9;
    arr2[4] = 10;
    print_array(arr, SIZE);
    print_array(arr2, SIZE);
    arr2 = increase_array_size(arr2, SIZE, size_multiplier);
    arr2[5] = 11;
    arr2[6] = 12;
    print_array(arr2, SIZE*size_multiplier);
    free(arr2);

    // 2D array demo:
    twoD_array();
    return 0;
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("The value at index %d is %d\n", i, arr[i]);
    }
}

int *increase_array_size(int *arr, int current_size, int size_multiplier)
{
    int *temp = (int *)malloc(sizeof(int) * (current_size * size_multiplier));
    for (int i = 0; i < current_size; i++)
    {
        temp[i] = arr[i];
        // printf("%d\n", temp[i]);
    }
    free(arr);
    return temp;
}

void twoD_array()
{
    int ROWS = 3;
    int COLS = 4;
    // Static 2D array created in stack memory:
    int arr1[3][4] = {{1,2,3,4}, {2,4,6,8}, {1,3,5,7}};
    print_2d_array(arr1, ROWS, COLS);

    // Dynamic 2D array created in heap memory:
    int** arr2 = create_2d_array(ROWS, COLS);
    // Initialize dynamic array with data.
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            arr2[i][j] = (i + 1) * (j + 1); //Example initialization
        }
    }
    print_dynamic_2d_array(arr2, ROWS, COLS);
    free_2d_array(arr2, ROWS);
}

void print_2d_array(int arr[][4], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int** create_2d_array(int rows, int cols)
{
    int** temp = (int **)malloc(sizeof(int*) * rows);
    if (temp == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < rows; i++)
    {
        temp[i] = (int *)malloc(sizeof(int) * cols);
        if (temp[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(temp[j]);
            }
            free(temp);
            return NULL;
        }
    }
    return temp;
}
void free_2d_array(int** arr, int rows)
{
    if (arr != NULL)
    {
        for (int i = 0; i < rows; i++)
        {
            // free nested arrays:
            free(arr[i]);
        }
        // free main array of pointers to an array:
        free(arr);
    }
}
void print_dynamic_2d_array(int** arr, int rows, int cols)
{
    if (arr != NULL)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
}