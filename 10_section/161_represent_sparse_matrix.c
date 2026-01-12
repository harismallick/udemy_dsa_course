#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int y_axis;
    int x_axis;
    int value;
} Element;

typedef struct
{
    int y_dimension;
    int x_dimension;
    int non_zero_values;
    Element* array;
} SparseMatrix;

void create_sparse_matrix(SparseMatrix* matrix);
void display_sparse_matrix(SparseMatrix* matrix);
SparseMatrix* add_sparse_matrices(SparseMatrix* m1, SparseMatrix* m2);

int main()
{
    // Program to create a sparse matrix

    SparseMatrix sm;
    create_sparse_matrix(&sm);
    
    SparseMatrix sm2;
    create_sparse_matrix(&sm2);
    
    SparseMatrix* sm_added = add_sparse_matrices(&sm, &sm2);

    printf("First Matrix:\n");
    display_sparse_matrix(&sm);

    printf("Second Matrix:\n");
    display_sparse_matrix(&sm2);

    if (sm_added)
    {
        printf("Sum Matrix:\n");
        display_sparse_matrix(sm_added);
    }

    free(sm.array);
    free(sm2.array);

    if (sm_added)
    {
        free(sm_added->array);
        free(sm_added);
    }

    return 0;
}

void create_sparse_matrix(SparseMatrix* matrix)
{
    printf("Enter the dimensions for the sparse matrix:\n");
    scanf("%d%d", &matrix->y_dimension, &matrix->x_dimension);
    // Manual test values: 4 5

    printf("Enter number of non-zero values in the sparse matrix:\n");
    scanf("%d", &matrix->non_zero_values);
    // Manual test value: 5

    matrix->array = (Element*)malloc(sizeof(Element) * matrix->non_zero_values);

    printf("The size of you array is %d x %d with %d non-zero values.\n", 
        matrix->y_dimension, matrix->x_dimension, matrix->non_zero_values);

    // User input values:
    for (int i = 0; i < matrix->non_zero_values; i++)
    {
        printf("Enter the y_coordinate, x_coordinate and value of your non-zero element:\n");
        scanf("%d%d%d", &matrix->array[i].y_axis, &matrix->array[i].x_axis, &matrix->array[i].value);
    }
    
    // // Test with manually added values:
    // // 1
    // matrix->array[0].y_axis = 1;
    // matrix->array[0].x_axis = 3;
    // matrix->array[0].value = 7;

    // // 2
    // matrix->array[1].y_axis = 2;
    // matrix->array[1].x_axis = 1;
    // matrix->array[1].value = 2;

    // // 3
    // matrix->array[2].y_axis = 2;
    // matrix->array[2].x_axis = 4;
    // matrix->array[2].value = 5;

    // // 4
    // matrix->array[3].y_axis = 3;
    // matrix->array[3].x_axis = 1;
    // matrix->array[3].value = 9;

    // // 5
    // matrix->array[4].y_axis = 4;
    // matrix->array[4].x_axis = 5;
    // matrix->array[4].value = 4;


}

void display_sparse_matrix(SparseMatrix* matrix)
{

    int k = 0;
    for (int i = 1; i <= matrix->y_dimension; i++)
    {
        for (int j = 1; j <= matrix->x_dimension; j++)
        {
            if (matrix->array[k].y_axis == i && matrix->array[k].x_axis == j)
            {
                printf("%d ", matrix->array[k].value);
                k++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

SparseMatrix* add_sparse_matrices(SparseMatrix* m1, SparseMatrix* m2)
{
    SparseMatrix* sum;

    if ((m1->x_dimension != m2->x_dimension) || (m1->y_dimension != m2->y_dimension))
    {
        printf("The two matrices cannot be summed because they have different dimensions.");
        return NULL;
    }
    sum = (SparseMatrix*)malloc(sizeof(SparseMatrix));

    sum->x_dimension = m1->x_dimension;
    sum->y_dimension = m1->y_dimension;
    sum->array = (Element*)malloc(sizeof(Element) * (m1->non_zero_values + m2->non_zero_values));

    int i, j, k;
    i = j = k = 0;
    while (i < m1->non_zero_values && j < m2->non_zero_values)
    {
        if (m1->array[i].y_axis < m2->array[j].y_axis)
        {
            sum->array[k++] = m1->array[i++];
        }
        else if (m1->array[i].y_axis > m2->array[j].y_axis)
        {
            sum->array[k++] = m2->array[j++];
        }
        else
        {
            if (m1->array[i].x_axis < m2->array[j].x_axis)
            {
                sum->array[k++] = m1->array[i++];
            }
            else if (m1->array[i].x_axis > m2->array[j].x_axis)
            {
                sum->array[k++] = m2->array[j++];
            }
            else
            {
                // Both coordinates are the same, so values must be summed:
                sum->array[k] = m1->array[i++];
                sum->array[k++].value += m2->array[j++].value;
            }
        }
    }

    // Copy remaining elements from m1:
    for (; i < m1->non_zero_values; i++)
    {
        sum->array[k++] = m1->array[i];
    }
    // Copy remaining elements from m2:
    for (; j < m2->non_zero_values; j++)
    {
        sum->array[k++] = m2->array[j];
    }
    sum->non_zero_values = k;

    return sum;
}