#include <stdio.h>

int main() {
    float sales[4][4] = {
        {100.0, 200.0, 300.0, 400.0},
        {500.0, 600.0, 700.0, 800.0},
        {900.0, 1000.0, 1100.0, 1200.0},
        {1300.0, 1400.0, 1500.0, 1600.0}
    };

    int quarter, company;
    float *pSales = &sales[0][0]; // Declare pointer to the 2D array

    printf("Enter quarter (Q1, Q2, Q3, Q4): ");
    scanf("%d", &quarter);
    printf("Enter company (C1, C2, C3, C4): ");
    scanf("%d", &company);

    printf("The sales figure for Q%d and C%d is %.2f\n", quarter, company, *(pSales + (quarter-1)*4 + (company-1)));
    return 0;
}
