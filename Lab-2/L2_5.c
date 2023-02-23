#include <stdio.h>
#include <string.h>

void removeChar(char *str, char c) {
    int i, j;
    int len = strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] == c) {
            for (j = i; j < len; j++) {
                str[j] = str[j+1];
            }
            len--;
            i--;
        }
    }
}

int main() {
    char str[20], c;
    printf("Enter a string: ");
   // scanf("%s", str);
    fgets(str,20,stdin);
    printf("Enter a character to remove: ");
    scanf(" %c", &c); // Note the space before %c to consume any newline characters

    removeChar(str, c);
    printf("Modified string: %s", str);

    return 0;
}
