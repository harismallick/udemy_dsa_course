## Section 5 - Recursion

### Video 46 Notes

##### What is recursion?
When a function calls itself, it is known as a recursive function.
- All recursive functions need a base condition. What is a base condition?
- It is the condition that will cause the recursive function to terminate.
- If there is no base case, then infinite recursion will occur which will cause a stack overflow.
- Once the base case is reached, the function calls will begin to be executed from the call stack.
  
##### Difference between loop and recursion?
- Loops only move in one direction; forward.
- Recursive functions can be used to perform operations in the forward direction, then the reverse direction once the base case is reached.
- Recursive functions have an ascending phase and a descending phase. The generalised statement below shows how it works:

```C
    void func(int n) {
        if (n > 0)
        {
            // 1. Calling operation - Any code placed here will be executed at call time
            // 2. Recursice function call:
            func(n-1);
            // 3. Returning operation - Any code placed here will be executed once returning from the recursive function call.
        }
    }
```

- __Head recursion__: It is when recursive call is done first, then any operations in the functional call are performed.
- __Tail recursion__: In this case, the function call's operations are performed first, then the recursive function call is done.
 
##### How recursive function uses the stack?
- If there are n activation calls for a function, its uses (n+1) memory.
- Recursive functions are memory consuming functions.
- Nested for loops can be replaced with a recursive function with one loop.
- You saving time by using space.

##### Recursion - Time complexity
- Recursive functions have a time complexity of O(n), where n is the number of function calls.

##### Static and global variables in recursion
-  