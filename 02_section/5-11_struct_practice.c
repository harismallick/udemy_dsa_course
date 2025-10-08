#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int length;
    int width;
} Rectangle;

int main() {
    Rectangle r1 = {10, 5};
    Rectangle r2;
    r2.length = 20;
    r2.width = 10;
    printf("Area of r1 = %d\n",r1.length * r1.width);
    printf("Area of r2 = %d\n",r2.length * r2.width);
    printf("Size of struct Rectangle: %d bytes\n", sizeof(r1));
    Rectangle *p = (Rectangle *)malloc(sizeof(Rectangle));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->length = 30;
    p->width = 10;
    printf("Area of p = %d\n", p->length * p->width);
    free(p);
    return 0;
}