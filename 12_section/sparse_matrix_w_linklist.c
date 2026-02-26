#include <stdio.h>
#include <stdlib.h>

typedef struct MatrixNode
{
    int col;
    int value;
    struct MatrixNode* next;
} MatrixNode;

typedef struct
{
    int rows;
    int cols;
    MatrixNode* matrix;
} SparseMatrix;

SparseMatrix* matrix_create(int row, int col);
void matrix_insert(SparseMatrix* matrix, int row, int col, int value);
void matrix_display(SparseMatrix* matrix);
void matrix_free(SparseMatrix* matrix);

int main()
{
    SparseMatrix* test1 = matrix_create(5,6);
    matrix_insert(test1, 1, 5, 8);
    matrix_insert(test1, 2, 4, 7);
    matrix_insert(test1, 3, 1, 5);
    matrix_insert(test1, 3, 5, 9);
    matrix_insert(test1, 4, 6, 3);
    matrix_insert(test1, 5, 1, 6);
    matrix_insert(test1, 5, 4, 4);

    matrix_display(test1);

    matrix_free(test1);
    return 0;
}

SparseMatrix* matrix_create(int row, int col)
{
    SparseMatrix* new_matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    new_matrix->cols = col;
    new_matrix->rows = row;

    MatrixNode* ll_array = (MatrixNode*)calloc(row, sizeof(MatrixNode));
    new_matrix->matrix = ll_array;
    return new_matrix;
}

void matrix_insert(SparseMatrix* matrix, int row, int col, int value)
{
    if (row < 1 || row > matrix->rows || col < 1 || col > matrix->cols)
    {
        printf("Given insertion coordinate out of bounds.\n");
        return;
    }
    MatrixNode *new_node = (MatrixNode*)malloc(sizeof(MatrixNode));
    new_node->col = col;
    new_node->value = value;
    new_node->next = NULL;
    MatrixNode *p = &matrix->matrix[row-1];
    while (p->next && p->next->col < col)
        {
            p = p->next;
        }

        // 4. Handle existing column or insert new node
        if (p->next && p->next->col == col)
        {
            // If the column already exists, update the value and free the unused node
            p->next->value = value;
            free(new_node);
        }
        else
        {
            // Insert the new node between 'p' and 'p->next'
            new_node->next = p->next;
            p->next = new_node;
        }
}
void matrix_display(SparseMatrix* matrix)
{
    MatrixNode *p;
    for (int i = 0; i < matrix->rows; i++)
    {
        p = matrix->matrix[i].next; // first value in the array is a dummy, so need to start with next
        for (int j = 1; j <= matrix->cols; j++)
        {
            if (p && (p->col == j))
            {
                printf("%d ", p->value);
                p = p->next;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void matrix_free(SparseMatrix* matrix)
{
    if (!matrix)
    {
        return;
    }

    MatrixNode *temp, *current;
    for (int i = 0; i < matrix->rows; i++)
    {
        current = matrix->matrix[i].next;
        
        while (current)
        {
            temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(matrix->matrix);
    free(matrix);
}