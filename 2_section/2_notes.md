## Section 2 - Essential C and C++ Concepts

### Video 7 Notes

- The video is on pointers.
- Why do we need pointers? To access the following in a program:
  - Heap memory
  - Resources outside the program: keystrokes, display, network card, etc.
  - Pointers used to pass parameters to a function.
- malloc() returns a void pointer to the contiguous memory space it allocated.
- This void pointer needs to be typecasted to the appropriate pointer type during assignment.
- When declaring a pointer that points to a descrete datatype, like int, char, float, etc, the pointer is assigned the memory by using the '&' symbol.
- When declaring a pointer to an array, the '&' is not needed. This is because an array declaration is a pointer to the first element in the array.

```C
    // Pointer declaration for a discrete datatype:
    int a;
    int *pA = &a;
    // pointer declaration for an array:
    int b[5];
    int *pB = b;
```

### Video 15 Notes
- Parameters can be passed in three different ways to a function:
  - Pass by value: This is where the value of the actual parameter is copied into the formal parameter declared in the function's prototype.
  - Pass by address: This is where the memory address of the actual parameters are passed to the function. This is useful when you wish to alter the actual parameters passed to the helper function.
  - Pass by reference: variable passed by reference (C++) or by pointer (C).

### Video 19 Notes
- Arrays can only be passed by reference/pointer as a parameter to a function.
- Structs can be pass by value or by reference.
- If the struct has an array in it, a copy of this array will be created in the helper function if the struct is passed by value. 

### Video 21 Notes
- Throughout this course, we will be using helper functions to initialise, modify and delete any structs declared in the main function or via malloc()
- This is the highest form of programming that can be done in C, and is as close to OOP as we can get in C.
- The C++ examples shown in the course will use classes.
