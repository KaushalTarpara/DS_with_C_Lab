#include <stdio.h>
#include <string.h>

int isPalindrome(char *str) {
    int len = strlen(str);
    char *end = str + len - 1;

    while (str < end) {
        if (*str != *end) {
            return 0;
        }
        str++;
        end--;
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
