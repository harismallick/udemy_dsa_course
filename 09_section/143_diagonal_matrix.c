#include <stdio.h>

#define SIZE 20
typedef struct
{
    int arr[SIZE];
    int size;
    int length;
} DiagonalMatrix;

void diagonal_matrix_set(DiagonalMatrix *mtx, int x_axis, int y_axis, int value);
int diagonal_matrix_get(DiagonalMatrix *mtx, int x_axis, int y_axis);
void diagonal_matrix_display(DiagonalMatrix *mtx);

int main()
{
    DiagonalMatrix test = {{0}, 20, 0};
    diagonal_matrix_set(&test, 1, 1, 9);
    diagonal_matrix_set(&test, 2, 2, 5);
    diagonal_matrix_set(&test, 3, 3, 1);
    diagonal_matrix_set(&test, 4, 4, 7);
    int value = diagonal_matrix_get(&test, 2, 2);
    printf("The value at 2,2 in the diagonal matrix is %d\n", value);

    diagonal_matrix_display(&test);

    diagonal_matrix_set(&test, 1, 2, 4);

    return 0;
}

void diagonal_matrix_set(DiagonalMatrix *mtx, int x_axis, int y_axis, int value)
{
    if (x_axis != y_axis)
    {
        printf("Value cannot be added as %d does not match %d\n", x_axis, y_axis);
    }

    mtx->arr[x_axis - 1] = value;
    mtx->length += 1;
}

int diagonal_matrix_get(DiagonalMatrix *mtx, int x_axis, int y_axis)
{
    if (x_axis != y_axis)
    {
        return 0;
    }
    return mtx->arr[x_axis - 1];
}

void diagonal_matrix_display(DiagonalMatrix *mtx)
{
    for (int i = 0; i < mtx->length; i++)
    {
        for (int j = 0; j < mtx->length; j++)
        {
            if (i == j)
            {
                printf("%d ", mtx->arr[j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}