#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int exponent;
    int constant;
} Element;

typedef struct
{
    int element_count;
    Element* poly_array;
} Polynomial;

Polynomial* create_polynomial();
Polynomial* add_polynomials(Polynomial* a, Polynomial* b);
double solve_polynomial(Polynomial* a);
void display_polynomial(Polynomial* a);

int main()
{
    Polynomial* poly =  create_polynomial();
    display_polynomial(poly);

    int total = solve_polynomial(poly);
    printf("The sum of the polynomial is: %d\n", total);

    Polynomial* poly2 = create_polynomial();
    display_polynomial(poly2);

    Polynomial* summed_poly = add_polynomials(poly, poly2);
    printf("The sum of the two polynomials is:\n");
    display_polynomial(summed_poly);

    free(poly->poly_array);
    free(poly);
    free(poly2->poly_array);
    free(poly2);
    free(summed_poly->poly_array);
    free(summed_poly);

    return 0;
}

Polynomial* create_polynomial()
{
    int size;
    printf("Enter the number of elements in your polynomial:\n");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("The size of the polynomial must be 1 or greater.\n");
        return NULL;
    }

    Polynomial* poly = (Polynomial*)malloc(sizeof(Polynomial));
    poly->element_count = size;

    Element* arr = (Element*)malloc(sizeof(Element) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter the constant and exponent of the %d element in your polynomial:\n");
        scanf("%d%d", &arr[i].constant, &arr[i].exponent);
    }
    poly->poly_array = arr;

    return poly;
}

Polynomial* add_polynomials(Polynomial* a, Polynomial* b)
{
    Polynomial* summed_poly = (Polynomial*)malloc(sizeof(Polynomial));
    summed_poly->element_count = a->element_count + b->element_count;
    summed_poly->poly_array = (Element*)malloc(sizeof(Element) * summed_poly->element_count);

    int i, j, k;
    i = j = k = 0;

    while ((i < a->element_count) && (j < b->element_count))
    {
        if (a->poly_array[i].exponent > b->poly_array[j].exponent)
        {
            summed_poly->poly_array[k++] = a->poly_array[i++];
        }
        if (a->poly_array[i].exponent < b->poly_array[j].exponent)
        {
            summed_poly->poly_array[k++] = b->poly_array[j++];
        }
        else
        {
            summed_poly->poly_array[k].exponent = a->poly_array[i].exponent;
            summed_poly->poly_array[k].constant = a->poly_array[i].constant + b->poly_array[j].constant;
            i++;
            j++;
            k++;
        }
    }

    for (; i < a->element_count; i++)
    {
        summed_poly->poly_array[k++] = a->poly_array[i];
    }
    for (; j < b->element_count; j++)
    {
        summed_poly->poly_array[k++] = a->poly_array[j];
    }

    summed_poly->element_count = k;
    return summed_poly;
}

double solve_polynomial(Polynomial* a)
{
    int x;
    printf("Enter a value for x:\n");
    scanf("%d", &x);

    int total = 0;

    for (int i = 0; i < a->element_count; i++)
    {
        total += a->poly_array[i].constant * (int)pow(x, a->poly_array[i].exponent);
    }
    return total;
}

void display_polynomial(Polynomial* a)
{
    for (int i = 0; i < a->element_count; i++)
    {
        printf("%dx^%d ", a->poly_array[i].constant, a->poly_array[i].exponent);
        if (i < a->element_count - 1)
        {
            printf("+ ");
        }
    }
    printf("\n");
}