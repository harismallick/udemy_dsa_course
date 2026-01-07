#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct
{
    int arr[SIZE];
    int size;
    int length;
    int matrix_dimension;
} Matrix;


void tridiagonal_matrix_set(Matrix *mtx, int x_axis, int y_axis, int value);
int tridiagonal_matrix_get(Matrix *mtx, int x_axis, int y_axis);
void tridiagonal_matrix_display(Matrix *mtx);
int get_matrix_array_index_mapping(int x_axis, int y_axis, int matrix_dimension);

int main()
{
    // TO DO: write implementation for tridiagonal matrix 
    Matrix test = {{0}, SIZE, 0, 5};
    tridiagonal_matrix_set(&test, 1,1,1);
    tridiagonal_matrix_set(&test, 2,2,2);
    tridiagonal_matrix_set(&test, 3,3,3);
    tridiagonal_matrix_set(&test, 4,4,4);
    tridiagonal_matrix_set(&test, 5,5,5);
    tridiagonal_matrix_set(&test, 1,2,2);
    tridiagonal_matrix_set(&test, 2,3,3);
    tridiagonal_matrix_set(&test, 3,4,4);
    tridiagonal_matrix_set(&test, 4,5,5);
    tridiagonal_matrix_set(&test, 2,1,1);
    tridiagonal_matrix_set(&test, 3,2,2);
    tridiagonal_matrix_set(&test, 4,3,3);
    tridiagonal_matrix_set(&test, 5,4,4);

    tridiagonal_matrix_display(&test);

    int value = tridiagonal_matrix_get(&test, 2, 1);
    printf("The value at 2,1 in the tridiagonal matrix is %d\n", value);

    return 0;
}

void tridiagonal_matrix_set(Matrix *mtx, int x_axis, int y_axis, int value)
{
    if (abs(y_axis - x_axis) > 1)
    {
        printf("Value cannot be added to diagonal matrix as coordinates are out of bounds.\n");
        return;
    }

    int index = get_matrix_array_index_mapping(x_axis, y_axis, mtx->matrix_dimension);

    if (index < 0)
    {
        printf("Incorrect array index.");
        return;
    }

    mtx->arr[index] = value;
    mtx->length += 1;
}

int tridiagonal_matrix_get(Matrix *mtx, int x_axis, int y_axis)
{
    if (abs(y_axis - x_axis) > 1)
    {
        return 0;
    }

    int index = get_matrix_array_index_mapping(x_axis, y_axis, mtx->matrix_dimension);

    if (index < 0)
    {
        printf("The calculated index is out of range.");
        return -1;
    }

    return mtx->arr[index];
}

void tridiagonal_matrix_display(Matrix *mtx)
{
    for (int i = 1; i <= mtx->matrix_dimension; i++)
    {
        for (int j = 1; j <= mtx->matrix_dimension; j++)
        {
            if (abs(i - j) > 1)
            {
                printf("0 ");
            }
            else
            {
                int index = get_matrix_array_index_mapping(j, i, mtx->matrix_dimension);
                printf("%d ", mtx->arr[index]);
            }

        }
        printf("\n");
    }
}

int get_matrix_array_index_mapping(int x_axis, int y_axis, int matrix_dimension)
{
    if (x_axis < 1 || y_axis < 1)
    {
        printf("Incorrect coordinate values for matrix. Values must be greater or equal to 1.\n");
        return -1;
    }

    int diff = y_axis - x_axis;
    int index;
    switch (diff)
    {
        case 1:
            index = y_axis - 2;
            break;
        case 0:
            index = matrix_dimension - 1 + y_axis - 1;
            break;
        case -1:
            index = (2 * matrix_dimension) + y_axis - 1;
            break;
        default:
            index = -1;
            break;
    }
    
    return index;
}