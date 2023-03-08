#include <stdio.h>

float average(float arr[], int m) {
    int i;
    float sum = 0;
    for (i = 0; i < m; i++) {
        sum += arr[i];
    }
    return sum / m;
}

int main() {
    float numbers[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    int m;
    float avg;

    printf("Enter a number m: ");
    scanf("%d", &m);

    avg = average(numbers, m);
    printf("The average of the first %d numbers is %.2f\n", m, avg);

    return 0;
}
