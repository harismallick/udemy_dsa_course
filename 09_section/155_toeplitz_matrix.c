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
    return 0;
}