## Section 12: Sparse Matrix and Polynomials using Linked Lists

- In section 10, we learnt how to represent these using arrays.
- Here, we will learn how to represent these values using arrays and linked lists.
- Needed 2D arrays to hold the row,col values of the matrix.
- With array + linked lists, the rows are length of the array, and each column value for the row is stored as a linked list node.
- The array is initialised with dummy nodes. This dummy node's next element is the first element for that row.
- The above point is crucial when writing the display function, keeping an eye on where the loop counter initialises from.

