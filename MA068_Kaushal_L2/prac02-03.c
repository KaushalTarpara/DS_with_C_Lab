#include <stdio.h>

void checkEvenOdd(int num) {
    if (num % 2 == 0) {
        printf("The number is even\n");
    } else {
        printf("The number is odd\n");
    }
}

int main() {
    int num;
    int (*pCheckEvenOdd)(int) = &checkEvenOdd; // Declare function pointer

    printf("Enter a number: ");
    scanf("%d", &num);

    (*pCheckEvenOdd)(num);
    return 0;
}
