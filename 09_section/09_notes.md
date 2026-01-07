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
    // matrix dimension -> n
    
    // Formula for row major mapping of lower triangle matrix to an array:
    index = (y_axis * (y_axis - 1) / 2) + (x_axis - 1);
    index = (i * (i - 1) / 2) + (j - 1);

    // Formula for column major mapping of lower triangle matrix to an array:
    index = (matrix_dimension * (x_axis - 1) - ((x_axis - 2) * (x_axis - 1) / 2)) + (y_axis - x_axis);
    index = (matrix_dimension * (j - 1) - ((j - 2) * (j - 1) / 2)) + (i - j);

```

#### Upper Triangle Matrix

- Lower triangle matrix, but reversed.
- The value M[i, j] is non-zero if i <= j.
- if i > j, then M[i, j] is zero.
- n * (n + 1) / 2 elements are non-zero in a matrix of size n.
- n * (n - 1) / 2 elements are zero in a matrix of size n.
- The row major mapping formula is the column major mapping formula from lower triangle matrix with the axes reversed.
- Similarly, the column major mapping formula is the row major mapping formula from lower triangle matrix with the axes reversed.
- 
```C
    // y-axis = row -> index letter: i
    // x-axis = column -> index letter: j
    // matrix dimension -> n
    
    // Formula for column major mapping of lower triangle matrix to an array:
    index = (x_axis * (x_axis - 1) / 2) + (y_axis - 1);
    index = (j * (j - 1) / 2) + (i - 1);

    // Formula for row major mapping of lower triangle matrix to an array:
    index = (matrix_dimension * (y_axis - 1) - ((y_axis - 2) * (y_axis - 1) / 2)) + (x_axis - y_axis);
    index = (matrix_dimension * (i - 1) - ((i - 2) * (i - 1) / 2)) + (j - i);

```


#### Symmetric Matrix

- A symmetric matrix is one where the values M[i,j] = M[j,i]
- An example of a symmetric matrix:

1   2   3
2   4   5
3   5   5

- It can be seen that the value at M[1,1] = M[1,1]
- M[1,2] = M[2,1]
- M[1,3] = M[3,1]
- M[3,3] = M[3,3]

- Since the top half of the matrix is idenical to the bottom half, this matrix can be stored as either an upper or lower triangle matrix, and the missing value can be inferred from the stored ones.

#### Tridiagonal Matrix

- This is similar to a diagonal matrix, where the diagonal values above and below the i=j diagonal are also stored.
- So, values are stored in a tridiagonal matrix if:
  - i - j = 0
  - i - j = 1
  - i - j = -1
- This can be simplified to: |i - j| <= 1
- Total number of values stored for a tridiagonal matrix: 3n-2, where n is the matrix dimension. 
- The linear representation of each matrix coordinate can be calculated as:
  - Case 1: if i-j = 1 => index = i - 2
  - Case 2: if i-j = 0 => index = matrix_dimension - 1 + i - 1
  - Case 3: if i-j = -1 => index = 2n - 1 + i - 1
- This linear representation works if the diagonals are stored in the order: lower -> middle -> upper
- If storing upper -> middle -> lower, then the formulas for i-j = 1 and i-j = -1 need to be reversed.
- 

#### Square Band Matrix

- In a tridiagonal matrix, there is exactly one diagonal line of value running on either side of the middle diagonal.
- In a square band matrix, there can be n number of diagonal lines running on both sides of the middle diagonal.
- Storing those additional diagonal will require adding more cases, to a total of n cases, one for each diagonal line.

#### Toeplitz Matrix

- In this type of matrix, the values in a diagonal are identical.
- Example:

2   3   4   5   6
7   2   3   4   5
8   7   2   3   4
9   8   7   2   3
10  9   8   7   2

- Only the first row and the first column of values from the matrix need to be stored in the linear array.
- The values can then be filled into the teoplitz matrix using an index calculating formula.
- When storing the row values first, followed by the column values, the array for the above example would be:
- [2,3,4,5,6,7,8,9,10]
- Formula for populating the upper triangle of the matrix:
  - if i <= j => Index = j - i
  - if i > j => Index = matrix_dimension + i - j - 1

