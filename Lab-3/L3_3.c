#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    int sum1 = 0, sum2 = 0;
    int *ptr1, *ptr2;

    printf("Enter the size of the first array: ");
    scanf("%d", &n);

    ptr1 = (int *) malloc(n * sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("Enter %d elements of the first array: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr1[i]);
        sum1 += ptr1[i];
    }

    printf("Enter the size of the revised array: ");
    scanf("%d", &m);

    ptr2 = (int *) realloc(ptr1, m * sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("Enter %d elements of the revised array: \n", m);
    for (i = 0; i < m; i++) {
        scanf("%d", &ptr2[i]);
        sum2 += ptr2[i];
    }

    printf("Sum of elements of the first array: %d\n", sum1);
    printf("Sum of elements of the revised array: %d\n", sum2);

    free(ptr2);
    return 0;
}
    