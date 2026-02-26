## Stack Datastructure

- Operates on the principle of last in first out (LIFO)
- Recursive functions can be converted to iterative functions and vice versa.
- In some cases, when converting recursion into iteration, we might need to declare a stack, called programmer stack.
- Abstract data type for stack contains the following core operations:
  1. push - add an element to the stack.
  2. pop - remove the top element from the stack
  3. peek(index) - see a particular element in the stack
  4. stackTop - a pointer that points to the top-most element in the stack
  5. isEmpty - boolean check for empty stack
  6. isFull - If for upper bounds for the stack


#### Lesson 232 - Stack using array

- Need an integer to store size of the stack (array).
- Need a pointer that will be stackTop.
- push and pop operations will be performed from the tail-end of the array.
- This is because inserting and deleting from tail of a static array is in O(1) time.

#### Lesson 233

- How to find the index position to return when peeking stack at a given index:

```
    index = top - position + 1

    where, top is the index position of the top element in the stack
    position is how far down the call stack you are trying to peek.
```

#### Lesson 235 - Stack using linked list

- 