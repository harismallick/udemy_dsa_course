#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    p = (int *)malloc(sizeof(int)*5);
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < 5; i++) {
        *(p + i) = i + 1;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d\n", *(p + i));
    }
    free(p);
    return 0;
}