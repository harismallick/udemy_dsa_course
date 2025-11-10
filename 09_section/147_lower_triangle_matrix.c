#include <stdio.h>

#define SIZE 20
#define ROW_MAPPING 0
#define COLUMN_MAPPING 1
typedef struct
{
    int arr[SIZE];
    int size;
    int length;
    int matrix_dimension;
} Matrix;

void triangle_matrix_set(Matrix *mtx, int x_axis, int y_axis, int value, int mapping);
int triangle_matrix_get(Matrix *mtx, int x_axis, int y_axis, int mapping);
void triangle_matrix_display(Matrix *mtx, int mapping);
int get_matrix_array_index_mapping(int x_axis, int y_axis, int mapping_type, int matrix_dimension);

int main()
{
    Matrix test = {{0}, SIZE, 0, 5};
    triangle_matrix_set(&test, 1, 1, 9, ROW_MAPPING);
    triangle_matrix_set(&test, 2, 2, 5, ROW_MAPPING);
    triangle_matrix_set(&test, 3, 3, 1, ROW_MAPPING);
    triangle_matrix_set(&test, 4, 4, 7, ROW_MAPPING);
    triangle_matrix_set(&test, 1, 2, 4, ROW_MAPPING);
    triangle_matrix_set(&test, 5, 5, 6, ROW_MAPPING);
    int value = triangle_matrix_get(&test, 2, 2, ROW_MAPPING);
    printf("The value at 2,2 in the lower triangle matrix is %d\n", value);
    
    triangle_matrix_display(&test, ROW_MAPPING);
    triangle_matrix_set(&test, 5, 4, 6, ROW_MAPPING);

    Matrix test2 = {{0}, SIZE, 0, 5};
    triangle_matrix_set(&test2, 1, 1, 9, COLUMN_MAPPING);
    triangle_matrix_set(&test2, 2, 2, 5, COLUMN_MAPPING);
    triangle_matrix_set(&test2, 3, 3, 1, COLUMN_MAPPING);
    triangle_matrix_set(&test2, 4, 4, 7, COLUMN_MAPPING);
    triangle_matrix_set(&test2, 1, 2, 4, COLUMN_MAPPING);
    triangle_matrix_set(&test2, 5, 5, 6, COLUMN_MAPPING);
    value = triangle_matrix_get(&test2, 2, 2, COLUMN_MAPPING);
    printf("The value at 2,2 in the lower triangle matrix is %d\n", value);
    
    triangle_matrix_display(&test2, COLUMN_MAPPING);
    triangle_matrix_set(&test2, 5, 4, 6, COLUMN_MAPPING);
    return 0;
}

int get_matrix_array_index_mapping(int x_axis, int y_axis, int mapping_type, int matrix_dimension)
{
    int index;
    if (mapping_type == ROW_MAPPING)
    {
        index = (y_axis * (y_axis - 1) / 2) + (x_axis - 1);
        return index;
    }
    
    else if (mapping_type == COLUMN_MAPPING)
    {
        index = matrix_dimension * (x_axis - 1) + ((x_axis - 2) * (x_axis - 1) / 2) + (y_axis - x_axis);
        return index;
    }
    
    else
    {
        printf("Incorrect mapping type passed. 0 for row-mapping or 1 for column-mapping.\n");
        return -1;
    }
}

void triangle_matrix_set(Matrix *mtx, int x_axis, int y_axis, int value, int mapping)
{
    if (x_axis > y_axis)
    {
        printf("Value cannot be added to lower triangle matrix as x-axis %d is greater than y-axis %d\n", x_axis, y_axis);
    }

    // Key aspect of the algorithm is calculating the correct index position for the mapping:
    int index;
    if (mapping == ROW_MAPPING)
    {
        index = get_matrix_array_index_mapping(x_axis, y_axis, ROW_MAPPING, mtx->matrix_dimension);
    }
    else if (mapping == COLUMN_MAPPING)
    {
        index = get_matrix_array_index_mapping(x_axis, y_axis, COLUMN_MAPPING, mtx->matrix_dimension);
    }

    if (index < 0)
    {
        printf("Incorrect index.\n");
        return;
    }

    mtx->arr[index] = value;
    mtx->length += 1;
}

int triangle_matrix_get(Matrix *mtx, int x_axis, int y_axis, int mapping)
{
    if (x_axis > y_axis)
    {
        return 0;
    }

    int index;
    if (mapping == ROW_MAPPING)
        index = get_matrix_array_index_mapping(x_axis, y_axis, ROW_MAPPING, mtx->matrix_dimension);
    else if (mapping == COLUMN_MAPPING)
        index = get_matrix_array_index_mapping(x_axis, y_axis, COLUMN_MAPPING, mtx->matrix_dimension);

    if (index < 0)
    {
        printf("Incorrect index.\n");
        return -1;
    }
    return mtx->arr[index];
}

void triangle_matrix_display(Matrix *mtx, int mapping)
{
    for (int i = 1; i <= mtx->matrix_dimension; i++)
    {
        for (int j = 1; j <= mtx->matrix_dimension; j++)
        {
            if (j > i)
            {
                printf("0 ");
            }
            else
            {
                int index;
                if (mapping == ROW_MAPPING)
                    index = get_matrix_array_index_mapping(j, i, ROW_MAPPING, mtx->matrix_dimension);
                else if (mapping == COLUMN_MAPPING)
                    index = get_matrix_array_index_mapping(j, i, COLUMN_MAPPING, mtx->matrix_dimension);

                printf("%d ", mtx->arr[index]);
            }
        }
        printf("\n");
    }
}