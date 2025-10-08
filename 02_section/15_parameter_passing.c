/*
Videos 15 - 20 are covered in this file.
*/

#include <stdio.h>

typedef struct {
    int length;
    int breadth;
} Rectangle;

void swap(int *a, int *b);
void print_list(int *arr, int n);
// Pass by value example:
int rect_area(Rectangle r);
// Pass by reference example:
void rect_sides_swap(Rectangle *r);

int main() {
    int x = 10, y = 20;
    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swapping: x = %d, y = %d\n", x, y);

    int arr[] = {1, 2, 3, 4, 5};
    print_list(arr, sizeof(arr) / sizeof(arr[0]));

    Rectangle r = {10, 20};
    int area = rect_area(r);
    printf("Area = %d * %d = %d\n", r.length, r.breadth, area);
    rect_sides_swap(&r);
    printf("After swapping: length = %d, breadth = %d\n", r.length, r.breadth);
    return 0;
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_list(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int rect_area(Rectangle r) {
    return r.length * r.breadth;
}

void rect_sides_swap(Rectangle *r) {
    int temp = r->length;
    r->length = r->breadth;
    r->breadth = temp;
}