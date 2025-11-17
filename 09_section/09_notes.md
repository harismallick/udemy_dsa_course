## Special Matrices

In this section, we will cover different types of matrices and algorithms for them.

There are eight different types of matrices covered in this course:

1. Diagonal matrix
2. Lower Triangular Matrix
3. Upper Triangular Matrix
4. Symmetric Matrix
5. Tridiagonal Matrix
6. Band Matrix
7. Toeplitz Matrix
8. Sparse Matrix

#### Diagonal Matrix

- In this form of matrix, the only non-zero values are when i = j.
- This means that rather than computing and storing 2D arrays, diagonal matrices can be stored as a simple array.

#### Lower Triangle Matrix

- In this form of matrix, only the lower half of the matrix has non-zero elements.
- The top half of the matrix is all zeroes.
- If i is the y-axis and j is the x-axis, then M[i, j] is non-zero if i >= j.
- For a matrix of size n, n * (n + 1) / 2 elements will be non-zero.
- n^2 - n(n+1)/2 = n * (n - 1) / 2 elements will be zero.
- n(n+1)/2 is the arithmetic progression formula for natural numbers starting from 1.
- AP formula is n(a+l)/2, where a is the first number in the series and l is the last number.
- When starting from 1, n = l.

```C
    // y-axis = row -> index letter: i
    // x-axis = column -> index letter: j
    
    // Formula for row major mapping of lower triangle matrix to an array:
    index = (y_axis * (y_axis - 1) / 2) + (x_axis - 1);

    // Formula for column major mapping of lower triangle matrix to an array:
    index = (matrix_dimension * (x_axis - 1) - ((x_axis - 2) * (x_axis - 1) / 2)) + (y_axis - x_axis);

```

#### Upper Triangle Matrix

- Lower triangle matrix, but reversed.
- The value M[i, j] is non-zero if i <= j.
- if i > j, then M[i, j] is zero.
- n * (n + 1) / 2 elements are non-zero in a matrix of size n.
- n * (n - 1) / 2 elements are zero in a matrix of size n.
- The row major mapping formula is the column major mapping formula from lower triangle matrix.
- Similarly, the column major mapping formula is the row major mapping formula from lower triangle matrix.
- 