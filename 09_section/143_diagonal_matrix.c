#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
typedef struct
{
    int arr[SIZE];
    int size;
    int length;
    int matrix_dimension;
} DiagonalMatrix;

void diagonal_matrix_set(DiagonalMatrix *mtx, int x_axis, int y_axis, int value);
int diagonal_matrix_get(DiagonalMatrix *mtx, int x_axis, int y_axis);
void diagonal_matrix_display(DiagonalMatrix *mtx);
void menu_driven_program();

int main()
{
    // DiagonalMatrix test = {{0}, 20, 0, 5};
    // diagonal_matrix_set(&test, 1, 1, 9);
    // diagonal_matrix_set(&test, 2, 2, 5);
    // diagonal_matrix_set(&test, 3, 3, 1);
    // diagonal_matrix_set(&test, 4, 4, 7);
    // int value = diagonal_matrix_get(&test, 2, 2);
    // printf("The value at 2,2 in the diagonal matrix is %d\n", value);

    // diagonal_matrix_display(&test);

    // diagonal_matrix_set(&test, 1, 2, 4);

    menu_driven_program();

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

void menu_driven_program()
{
    int mtx_dimension, user_input;
    
    printf("Enter the dimension of your matrix:\n");
    scanf("%d", &mtx_dimension);
    
    if (mtx_dimension > 20)
    {
        printf("Matrix dimension is too large. Size must be less than 20.\n");
        return;
    }
    DiagonalMatrix *user_matrix = malloc(sizeof(DiagonalMatrix));
    user_matrix->size = SIZE;
    user_matrix->length = 0;
    user_matrix->matrix_dimension = mtx_dimension;

    do
    {
        printf("Your Options for the matrix:\n");
        printf("1. Set\t2. Get\t3. Print Matrix\t4. Exit\n");
        scanf("%d", &user_input);

        int x_axis, y_axis, value;
        switch (user_input)
        {
            case 1:
                printf("Enter values for x_axis and y_axis of matrix and the value to be inserted:\n");
                scanf("%d%d%d", &x_axis, &y_axis, &value);
                diagonal_matrix_set(user_matrix, x_axis, y_axis, value);
                break;
            case 2:
                printf("Enter values for x_axis and y_axis of matrix to get the value stored:\n");
                scanf("%d%d", &x_axis, &y_axis);
                int value = diagonal_matrix_get(user_matrix, x_axis, y_axis);
                printf("The value stored at %d,%d is %d\n", x_axis, y_axis, value);
                break;
            case 3:
                diagonal_matrix_display(user_matrix);
                break;
            case 4:
                printf("Deleting the matrix and exiting...\n");
                break;
        }

    } while (user_input > 0 && user_input < 4);

    free(user_matrix);

}