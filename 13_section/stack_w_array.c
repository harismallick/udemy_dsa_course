#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int size;
    int top;
    int *stack;
} StackArray;

StackArray* stack_initialise(int size);
void stack_push(StackArray *stack, int value);
int stack_pop(StackArray *stack);
int stack_top(StackArray *stack);
void stack_display(StackArray *stack, int counter);
bool stack_is_full(StackArray *stack);
bool stack_is_empty(StackArray *stack);
void stack_free(StackArray *stack);
int stack_peek(StackArray *stack, int position);

int main()
{
    StackArray *test1 = stack_initialise(5);
    stack_push(test1, 1);
    stack_push(test1, 3);
    stack_push(test1, 5);
    stack_push(test1, 7);
    stack_push(test1, 9);
    stack_push(test1, 11);

    stack_display(test1, 0);
    printf("The top element in the stack is: %d\n", stack_top(test1));

    printf("Is the stack currently full? %d\n", stack_is_full(test1));
    printf("Is the stack currently empty? %d\n", stack_is_empty(test1));

    int popped = stack_pop(test1);
    printf("The element popped from the stack: %d\n", popped);
    printf("New top element in the stack: %d\n", stack_top(test1));
    stack_display(test1, 0);

    printf("%d\n", stack_peek(test1, 1));
    printf("%d\n", stack_peek(test1, 2));
    printf("%d\n", stack_peek(test1, 3));
    printf("%d\n", stack_peek(test1, 4));
    printf("%d\n", stack_peek(test1, 5));

    stack_free(test1);

    return 0;
}

StackArray* stack_initialise(int size)
{
    StackArray *new = (StackArray*)malloc(sizeof(StackArray));
    new->size = size;
    new->stack = (int*)calloc(size, sizeof(int));
    new->top = -1;
    return new;
}
void stack_push(StackArray *stack, int value)
{
    if (stack_is_full(stack))
    {
        printf("The stack is full. Cannot add given element.\n");
        return;
    }
    stack->stack[++stack->top] = value;
}
int stack_pop(StackArray *stack)
{
    if (stack_is_empty(stack))
    {
        printf("Cannot pop from an empty stack.\n");
        return -1;
    }
    int popped_value = stack->stack[stack->top];
    stack->stack[stack->top--] = 0;
    return popped_value;
}

int stack_top(StackArray *stack)
{
    if (stack_is_empty(stack)) return -1;
    
    return stack->stack[stack->top];
}

void stack_display(StackArray *stack, int counter)
{
    if (counter > stack->top)
    {
        return;
    }
    stack_display(stack, counter+1);
    printf("%d\n", stack->stack[counter]);
}

bool stack_is_full(StackArray *stack)
{
    return stack->top == stack->size-1;
}
bool stack_is_empty(StackArray *stack)
{
    return stack->top == -1;
}

void stack_free(StackArray *stack)
{
    if (!stack) return;

    free(stack->stack);
    free(stack);
}

int stack_peek(StackArray *stack, int position)
{
    if (stack_is_empty(stack)) return -1;
    
    if (position > stack->top + 1)
    {
        printf("Position out of call stack range");
        return -1;
    }

    int counter = stack->top - position + 1;
    return stack->stack[counter];
}