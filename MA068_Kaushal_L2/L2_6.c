#include <stdio.h>

void copyArray(int *source, int *destination, int size) {
    int i;
    for (i = 0; i < size; i++) {
        *(destination + i) = *(source + i);
    }
}

int main() {
    int source[5] = {1, 2, 3, 4, 5};
    int destination[7];
    int size = 5;

    copyArray(source, destination, size);

    printf("Source array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", source[i]);
    }
    printf("\nDestination array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", destination[i]);
    }

    return 0;
}
