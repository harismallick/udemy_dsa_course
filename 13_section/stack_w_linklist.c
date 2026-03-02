#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STACK_LIMIT 1000

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

typedef struct LlStack
{
    StackNode* stack_top;
    int stack_limit;
    int stack_counter;
} LlStack;


LlStack* stack_initialise(int limit);
void stack_push(LlStack *stack, int value);
int stack_pop(LlStack *stack);
int stack_top(LlStack *stack);
void stack_display(LlStack *stack);
bool stack_is_full(LlStack *stack);
bool stack_is_empty(LlStack *stack);
int stack_peek(LlStack *stack, int position);
void stack_free(LlStack *stack);
bool paranthesis_matching(char *expression);
char* convert_infix_to_postix(char *expression);
bool is_operand(char character);
int char_precedence(char character);
void print_string(char *string);
int instack_precedence(char character);
int outstack_precedence(char character);
char* convert_infix_to_postix_complex(char *expression);

int main()
{
    LlStack *test1 = stack_initialise(5);
    stack_push(test1, 1);
    stack_push(test1, 3);
    stack_push(test1, 5);
    stack_push(test1, 7);
    stack_push(test1, 9);
    stack_push(test1, 11);

    stack_display(test1);
    printf("The top element in the stack is: %d\n", stack_top(test1));

    printf("Is the stack currently full? %d\n", stack_is_full(test1));
    printf("Is the stack currently empty? %d\n", stack_is_empty(test1));

    int popped = stack_pop(test1);
    printf("The element popped from the stack: %d\n", popped);
    printf("New top element in the stack: %d\n", stack_top(test1));
    stack_display(test1);

    printf("%d\n", stack_peek(test1, 1));
    printf("%d\n", stack_peek(test1, 2));
    printf("%d\n", stack_peek(test1, 3));
    printf("%d\n", stack_peek(test1, 4));
    printf("%d\n", stack_peek(test1, 5));

    stack_free(test1);

    // lesson 240 - paranthesis matching

    printf("Paranthesis matching test cases results:\n");
    char phrase1[] = "((a+b)*(c-d))";
    printf("%d\n", paranthesis_matching(phrase1));
    char phrase2[] = "((a+b()*(c-d))";
    printf("%d\n", paranthesis_matching(phrase2));
    char phrase3[] = "((a+b)*(c-d)))";
    printf("%d\n", paranthesis_matching(phrase3));
    char phrase4[] = "{([a+b]*[c-d])}";
    printf("%d\n", paranthesis_matching(phrase4));
    char phrase5[] = "([a+b]*[c-d))";
    printf("%d\n", paranthesis_matching(phrase5));

    // Lesson 247
    char exp[] = "a+b*c-d/e";
    char *postfix = convert_infix_to_postix(exp);
    printf("Result of converting infix to postfix.\n");
    print_string(postfix);

    // Lesson 249
    char exp2[] = "((a+b)*c)-d^e^f";
    postfix = convert_infix_to_postix_complex(exp2);
    printf("Result of using the complex function:\n");
    print_string(postfix);

    free(postfix);
    return 0;
}

LlStack* stack_initialise(int limit)
{
    LlStack *new = (LlStack*)malloc(sizeof(LlStack));
    if (!new)
    {
        printf("Memory allocation for stack failed.\n");
        return NULL;
    }
    new->stack_limit = limit;
    new->stack_top = NULL;
    new->stack_counter = 0;
    return new;
}

void stack_push(LlStack *stack, int value)
{
    if (stack_is_full(stack))
    {
        printf("Stack overflow.\n");
        return;
    }

    StackNode *new = (StackNode*)malloc(sizeof(StackNode));
    new->data = value;
    new->next = stack->stack_top;
    stack->stack_top = new;
    stack->stack_counter++;
}

int stack_pop(LlStack *stack)
{
    if (!stack || !stack->stack_top) return -1;

    StackNode *temp = stack->stack_top;
    stack->stack_top = temp->next;
    int value = temp->data;
    free(temp);
    stack->stack_counter--;
    return value;
}

int stack_top(LlStack *stack)
{
    return stack->stack_top ? stack->stack_top->data : -1;
}

void stack_display(LlStack *stack)
{
    StackNode *current = stack->stack_top;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

bool stack_is_full(LlStack *stack)
{
    return stack->stack_counter == stack->stack_limit;
}

bool stack_is_empty(LlStack *stack)
{
    return stack->stack_top == NULL;
}

int stack_peek(LlStack *stack, int position)
{
    if (position < 1 || position > stack->stack_limit) return -1;
    if (stack->stack_counter < position) return -1;

    StackNode *temp = stack->stack_top;
    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

void stack_free(LlStack *stack)
{
    if (!stack) return;
    StackNode *temp, *current;
    current = stack->stack_top;
    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

bool paranthesis_matching(char *expression)
{
    LlStack *para_stack = stack_initialise(STACK_LIMIT);

    int i = 0;
    bool outcome = true;
    while (*(expression + i) != '\0')
    {
        char letter = *(expression + i);
        if (letter == '(' || letter == '[' || letter == '{')
        {   
            stack_push(para_stack, letter);
        }
        else if (letter == ')' || letter == ']' || letter == '}')
        {
            int pop_result = stack_pop(para_stack);
            if ((pop_result == -1) || ((pop_result != letter - 1) && (pop_result != letter - 2))) // ASCII manipulation
            {
                outcome = false;
                break;
            }
        }
        i++;
    }
    if (!stack_is_empty(para_stack))
    {
        outcome = false;
    }

    stack_free(para_stack);
    return outcome;
}

char* convert_infix_to_postix(char *expression)
{
    char* postfix = (char*)malloc((strlen(expression) + 1));
    LlStack *operand_stack = stack_initialise(STACK_LIMIT);

    int ifix = 0;
    int pfix = 0;
    while (expression[ifix] != '\0')
    {
        char current = expression[ifix];
        if (is_operand(current))
        {
            postfix[pfix] = current;
            pfix++;
        }
        else
        {
            int curr_precedence = char_precedence(current);
            if (stack_is_empty(operand_stack) || char_precedence(operand_stack->stack_top->data) < curr_precedence)
            {
                stack_push(operand_stack, current);
            }
            else
            {
                while (
                    !stack_is_empty(operand_stack) &&
                    char_precedence(operand_stack->stack_top->data) >= curr_precedence
                )
                {
                    postfix[pfix] = stack_pop(operand_stack);
                    pfix++;
                }
                stack_push(operand_stack, current);
            }
        }
        ifix++;
    }
    if (!stack_is_empty(operand_stack))
    {
        while (!stack_is_empty(operand_stack))
        {
            postfix[pfix] = stack_pop(operand_stack);
            pfix++;
        }
    }
    postfix[pfix] = '\0';
    stack_free(operand_stack);
    return postfix;

}

bool is_operand(char character)
{
    bool result = true;

    if (
        character == '+' ||
        character == '-' ||
        character == '*' ||
        character == '/' ||
        character == '^' ||
        character == '(' ||
        character == ')'
    )
    {
        result = false;
    }
    return result;
}
int char_precedence(char character)
{
    if (character == '+' || character == '-') return 1;
    else if (character == '*' || character == '/') return 2;
    else return 0;
}
int instack_precedence(char character)
{
    if (character == '+' || character == '-') return 2;
    else if (character == '*' || character == '/') return 4;
    else if (character == '^') return 5;
    else return 0;
}
int outstack_precedence(char character)
{
    if (character == '+' || character == '-') return 1;
    else if (character == '*' || character == '/') return 3;
    else if (character == '^') return 6;
    else if (character == '(') return 7;
    else return 0;
}

void print_string(char *string)
{
    int i = 0;
    
    while (string[i] != '\0')
    {
        printf("%c", string[i]);
        i++;
    }
    printf("\n");
}

char* convert_infix_to_postix_complex(char *expression)
{
    char* postfix = (char*)malloc((strlen(expression) + 1));
    LlStack *operand_stack = stack_initialise(STACK_LIMIT);

    int ifix = 0;
    int pfix = 0;
    while (expression[ifix] != '\0')
    {
        char current = expression[ifix];
        if (is_operand(current))
        {
            postfix[pfix] = current;
            pfix++;
        }
        else
        {
            int curr_precedence = outstack_precedence(current);
            if (stack_is_empty(operand_stack) || instack_precedence(operand_stack->stack_top->data) < curr_precedence)
            {
                stack_push(operand_stack, current);
            }
            else
            {
                while (
                    !stack_is_empty(operand_stack) &&
                    instack_precedence(operand_stack->stack_top->data) >= curr_precedence
                )
                {
                    if (instack_precedence(operand_stack->stack_top->data) > 0)
                    {
                        postfix[pfix++] = stack_pop(operand_stack);
                    }
                    else
                    {
                        stack_pop(operand_stack);
                    }
                }
                if (curr_precedence > 0) stack_push(operand_stack, current);
            }
        }
        ifix++;
    }
    if (!stack_is_empty(operand_stack))
    {
        while (!stack_is_empty(operand_stack))
        {
            if (instack_precedence(operand_stack->stack_top->data) > 0)
            {
                postfix[pfix++] = stack_pop(operand_stack);
            }
            else
            {
                stack_pop(operand_stack);
            }
        }
    }
    postfix[pfix] = '\0';
    stack_free(operand_stack);
    return postfix;

}