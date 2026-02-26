#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Element
{
    double exponent;
    double coeff;
    struct Element *next;
} Element;

typedef struct
{
    Element *first_element;
    int element_count;
} Polynomial;

Polynomial* create_polynomial();
void add_element_to_polynomial(Polynomial* poly, double exponent, double coeff);
void display_polynomial(Polynomial *poly);
double solve_polynomial(Polynomial* poly, int x);
void free_polynomial(Polynomial *poly);

int main()
{
    Polynomial *test1 = create_polynomial();
    add_element_to_polynomial(test1, 3,4);
    add_element_to_polynomial(test1, 2,9);
    add_element_to_polynomial(test1, 1,6);
    add_element_to_polynomial(test1, 0,7);

    printf("hello world\n");
    display_polynomial(test1);

    int x = 2;
    printf("The solution for x = %d is %lf\n", x, solve_polynomial(test1, x));

    free_polynomial(test1);
    return 0;
}

Polynomial* create_polynomial()
{
    Polynomial *new = (Polynomial*)malloc(sizeof(Polynomial));
    new->element_count = 0;
    new->first_element = NULL;
    return new;
}

void add_element_to_polynomial(Polynomial* poly, double exponent, double coeff)
{
    Element *new_element = (Element*)malloc(sizeof(Element));
    new_element->coeff = coeff;
    new_element->exponent = exponent;
    new_element->next = NULL;

    Element *p = poly->first_element;
    if (!p)
    {
        poly->first_element = new_element;
    }
    else
    {
        while (p->next)
        {
            p = p->next;
        }
        p->next = new_element;
    }
    poly->element_count++;
}

void display_polynomial(Polynomial *poly)
{
    Element *temp = poly->first_element;
    while (temp->next)
    {
        printf("%.1lfx^%.1lf + ", temp->coeff, temp->exponent);
        temp = temp->next;
    }
    if (temp->exponent == 0)
    {
        printf("%.1lf\n", temp->coeff);
    }
    else
    {
        printf("%.1lfx^%.1lf\n", temp->coeff, temp->exponent);
    }
}

double solve_polynomial(Polynomial* poly, int x)
{
    double sum = 0;
    Element *current = poly->first_element;
    while (current)
    {
        sum += current->coeff * pow(x, current->exponent);
        current = current->next;
    }
    return sum;
}

void free_polynomial(Polynomial *poly)
{
    if (!poly) return;

    Element *current, *temp;
    current = poly->first_element;
    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(poly);
}