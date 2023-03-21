#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int empID;
    char name[50];
    int age;
};

int main() {
    int n, i;
    struct Employee *ptr;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    ptr = (struct Employee *) malloc(n * sizeof(struct Employee));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter details for employee %d\n", i + 1);
        printf("Enter employee ID: ");
        scanf("%d", &(ptr + i)->empID);
        printf("Enter name: ");
        scanf("%s", (ptr + i)->name);
        printf("Enter age: ");
        scanf("%d", &(ptr + i)->age);
    }

    printf("\nEmployee Details:\n");
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID: %d\n", (ptr + i)->empID);
        printf("Name: %s\n", (ptr + i)->name);
        printf("Age: %d\n", (ptr + i)->age);
    }

    free(ptr);
    return 0;
}
