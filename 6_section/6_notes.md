# Section 6: Arrays

### Notes
- An array is a section of contiguous memory assigned for storing a particular datatype.
- If an array is declared, it will contain garbage values in the assigned memory locations.
- There are many different ways to initialise an array in C.

```C
    int A[5]; // Declaration only; will contain garbage values.
    int B[5] = {1,2,3,4,5}; // Array of 5 elements initialised with the desired elements.
    int C[5] = {1,2}; // Array of 5 elements initialised as {1,2,0,0,0}
    int D[5] = {0}; // Array of 5 elements initialised as {0,0,0,0,0}
    int E[] = {1,2,3}; // Array of 3 elements initialised with the given three values.
```

#### Arrays in compilers

##### How do compilers deal with arrays?
- Compilers store the memory address for the first element in the array.
- They use a formula to calculate the memory address for the other elements:

```
    addr[i] = L0 + i * w
    where:
        L0 = mem address of the first element
        w = size of datatype stored in the array.
```

##### How do compilers deal with 2D arrays?
- We've learnt that 2D arrays are still stored as a 1-dimensional contiguous array by the compiler.
- The compiler applies a formula to resolve this 1D array into the desired 2D array.
- There are two different formulas that can be used:

###### 1. Row Major Formula 
- If a compiler is designed to use row major formula for mapping memory addresses to elements, then the 2D array is mapped to its 1D array by rows.
- For example, if we have a 2D array of m rows and n columns, then the first row of n columns will be stored in mem addresses L0 - L0+n-1.
- The next row will be stored in L0+n - L0+n + n-1.
The formula used by the compiler for this is:
```
    arr[m][n];
    addr(arr[i][j]) = L0 + (i * n + j) * w
```

###### 2. Column Major Formula
- In this case, the compiler is programmed to map a 2D array to its 1D representation each column at a time.
- The formula is:
```
    arr[m][n];
    arrd(arr[i][j]) = L0 + (j * m + i) * w
```

##### How do compilers map nD arrays?
- What if you have a 4D or a 5D array? How would that be mapped by the compiler?
- The row major and column major formulas for these are:
```
    int arr[m][n][o][p]
    // For row major, we go from left to right:
    addr(arr[i][j][k][l]) = L0 + [(i*n*o*p) + (j*o*p) + (k*p) + l] * w

    // For column major, we go from right to left:
    addr(arr[i][j][k][l] = L0 + [(l*o*n*m) + (k*n*m) + (j*m) + i] * w

```
- Calculating the memory address this way will require O(n^2) operations, which is very slow.
- The formula can be optimised using ___Horner's Rule___:
```
    int arr[d1][22][d3][d4]
    arrd(arr[i1][i2][i3][i4]) = L0 + [i4 + d4*(i3 + d3*(i2 + d2*i1))] * w
    // This reduces the number of operations to O(N).
    // Where N is the number of dimensions of the array.
```


