#include <stdio.h>


#define SIZE 20

typedef struct
{
    int arr[SIZE];
    int size;
    int length;
    int matrix_dimension;
} Matrix;

void toeplitz_matrix_set(Matrix *mtx, int x_axis, int y_axis, int value);
int toeplitz_matrix_get(Matrix *mtx, int x_axis, int y_axis);
void toeplitz_matrix_display(Matrix *mtx);
int get_matrix_array_index_mapping(int x_axis, int y_axis, int matrix_dimension);

int main()
{
    // TO DO: Write the code implementation
    Matrix test = {{0}, SIZE, 0, 5};
    toeplitz_matrix_set(&test, 1,1,2);
    toeplitz_matrix_set(&test, 2,1,3);
    toeplitz_matrix_set(&test, 3,1,4);
    toeplitz_matrix_set(&test, 4,1,5);
    toeplitz_matrix_set(&test, 5,1,6);
    toeplitz_matrix_set(&test, 1,2,7);
    toeplitz_matrix_set(&test, 1,3,8);
    toeplitz_matrix_set(&test, 1,4,9);
    toeplitz_matrix_set(&test, 1,5,10);

    toeplitz_matrix_display(&test);
    return 0;
}

void toeplitz_matrix_set(Matrix *mtx, int x_axis, int y_axis, int value)
{
    if (x_axis < 1 || y_axis < 1)
    {
        printf("Matrix coordinate cannot be less than 1.\n");
        return;
    }
    int index = get_matrix_array_index_mapping(x_axis, y_axis, mtx->matrix_dimension);

    if (index < 0)
    {
        printf("Incorrect index. Value not added to the matrix.\n");
        return;
    }

    mtx->arr[index] = value;
    mtx->length += 1;
}

int toeplitz_matrix_get(Matrix *mtx, int x_axis, int y_axis)
{
    if (x_axis < 1 || y_axis < 1)
    {
        printf("Matrix coordinate cannot be less than 1.\n");
        return -1;
    }
    int index = get_matrix_array_index_mapping(x_axis, y_axis, mtx->matrix_dimension);

    if (index < 0)
    {
        printf("Incorrect index. Value not added to the matrix.\n");
        return -1;
    }

    int value = mtx->arr[index];
    return value;

}

int get_matrix_array_index_mapping(int x_axis, int y_axis, int matrix_dimension)
{
    if (y_axis <= x_axis)
    {
        return x_axis - y_axis;
    }
    else
    {
        return matrix_dimension + y_axis - x_axis - 1;
    }
}

void toeplitz_matrix_display(Matrix *mtx)
{

    for (int i = 1; i <= mtx->matrix_dimension; i++)
    {
        for (int j = 1; j <= mtx->matrix_dimension; j++)
        {
            int index = get_matrix_array_index_mapping(j, i, mtx->matrix_dimension);
            printf("%d ", mtx->arr[index]);
        }
        printf("\n");
    }
}