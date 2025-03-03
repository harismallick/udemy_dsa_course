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
- Typically, each function call will create its own set of local variables with defined values.
- But, declaring a static variable inside a recursive function makes it so that different function calls access the same values for variables stored in stack memory.
- Only one copy of the variable is created in memory.
- This means that the value of static variable can be changed between function calls.
- This is the same as declaring a variable outside the function, but accessing it inside.

```C
    int func(int n)
    {
        static int x = 0;
        if (n == 0)
        {
            return 0;
        }
        x++;
        return x + func(n - 1);
    }
    // This is the same as:
    int x = 0;
    int func2(int n)
    {
        if (n ==0)
        {
            return 0;
        }
        x++;
        return x + func2(n - 1);
    }
```

##### Types of Recursion

There are 5 types of recursion:
    1. Tail recursion
    2. Head recursion
    3. Tree recursion
    4. Indirect recursion
    5. Nested recursion
   
###### Tail recursion
- When the recursive call is the last thing to happen in a recursive function, it is known as tail recursion.
- All the operation in the function will be performed at calling time. 
- A tail recursion can always be rewritten as a loop. The recursive function will take O(N) space and time, while the loop with take O(N) time but O(1) space.
- For this reason, tail recursion should rarely be used. It should be replaced with a loop. 
- Converting tail recursion to a loop is sometimes automatically done by some compilers.

```C
void func1(int n)
{
    if (n > 0)
    {
        print("%d\n", n);
        func1(n - 1);
    }
}
// This can be re-written as:

void func2(int n)
{
    while (n > 0)
    {
        print("%d\n", n);
        n--;
    }
}

```

###### Head recursion
- When the recursive call is the first thing to happen in a recursive function, it is known as head recursion.
- In head recursion, all the processing inside the function is done at return time, not call time.
- A head recursive function can also be converted into a loop, but its not as easy as converting tail recursion.
- The implementation needs to be changed slightly.

```C
// Head recursion
void func1(int n)
{
    if (n > 0)
    {
        func1(n - 1);
        print("%d\n", n);
    }
}
// This can be re-written as:
// Another variable had to be introduced
void func2(int n)
{
    int i = 1;
    while (i >= n)
    {
        print("%d\n", i);
        i++;
    }
}

```

###### Tree recursion
- Head and tail recursion are examples of linear recursion -- function called only __once__ within itself.
- Tree recursion is when the function is called __multiple__ times within itself.
- For example, to traverse a binary tree, you would call the recursive function twice, once to traverse the left node and once to traverse the right.
- If a function is being called twice within itself, then the time complexity is O(2^N), and the space complexity is O(N).

```C

    void tree_recursion(int n)
    {
        if (n > 0)
        {
            printf("%d ", n);
            tree_recursion(n - 1);
            tree_recursion(n - 1);
            // tree_recursion(n - 1);
        }
    }
```

###### Indirect recursion
- When multiple functions call one another in a cyclical fashion, it is known as indirect recursion.
```C

    void indirect_recursion_a(int n)
    {
        if (n > 0)
        {
            printf("%d ", n);
            indirect_recursion_b(n - 1);
        }
    }

    void indirect_recursion_b(int n)
    {
        if (n > 1)
        {
            printf("%d ", n);
            indirect_recursion_a(n / 2);
        }
    }
```

###### Nested recursion 
- Nested recursion is when the value passed to a recursive function is a function call itself.
```C

    int nested_recursion(int n)
    {
        if (n > 100)
        {
            return n - 10;
        }
        else
        {
            return nested_recursion(nested_recursion(n + 11));
        }
    }
```

