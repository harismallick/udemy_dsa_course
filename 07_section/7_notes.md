# Arrays as Abstract Data Types (ADT)

- We need to write functions to get specific information about an array, and to modify it.
- Writing such functions allows for the creation of arrays as an abstract data type.
- The operations that will be covered in this lesson are:
    1. display()
    2. add(x)/append(x)
    3. insert(index, x)
    4. delete(index)
    5. search(x)
    6. get(x)
    7. set(index, x)
    8. min(), max()
    9. reverse()
    10. shift()/rotate()

- The information that we know or can keep track of for each array are:
  - The space used by the array
  - Its size
  - Length (number of elements in it)
  
### 107 - Examining binary search time complexity
- The average time complexity of binary search for an element that exists or doesn't exist in the list is O(logn).
- The shortest time is potentially O(1) for an element that exists in the list. And the longest is O(logn).
- For an element that doesn't exist in the list, binary search is always O(logn).

### 114 - Merging two sorted arrays

- The merge operation is different to concatenation.
- Concatentation is the joining of two arrays into a single array.
- Merging is the act to combining two sorted arrays into a single sorted array.

### 116 - Set operations on an array

There are 4 set operations:
1. Union
2. Intersection
3. Difference
4. Set membership

