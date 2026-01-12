## Sparse Matrix

#### 159. Sparse Matrix Representation

- In this type of matrix, there are significantly more zero elements than there are non-zero elements.
- But unlike the matrices that we studies in the previous section, there is no simple pattern to differentiate which indices in the matrix contain zero-elements and which contain non-zero elements.
- In such a scenario, there are two ways to represent a sparse matrix:
  - Coordinate List
    - Also called the three-column representation.
    - In this case, we store the non-zero elements as a tuple of three values: the x- and y-coordinates and the value itself.
    - Consistency of the order in which each element is stored is key.
    - The first tuple stored in the array should be metadata about the matrix: the matrix dimensions and the total number of non-zero elements stored.
  - Compressed Sparse Row
    - In this method, rather than creating one array of tuples, three different arrays are created, each storing different metadata about the sparse matrix.
    - One array to store all the non-zero values - Lets call it array A.
    - One array to store cumulatively increasing count of the number of items in each row - This array called iA
    - One array to store the exact column index for each non-zero element in array A - This array called jA
    - A and jA should be arrays of equal length.
    - The 0th element in the iA array should be 0. This is because the matrix indexing starts from 1, not 0.
    - The array index for each element in array A should match the index of its column number in array jA.


#### 160. Addition of two sparse matrices

- Addition operation can only be performed on two matrices if their dimensions are identical.
- 