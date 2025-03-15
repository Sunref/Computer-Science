#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool ehPalindromo(const char* str);

int main() {

    char string[100];

    printf("String: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';  

    if (ehPalindromo(string)) {
        printf("\"%s\" eh um palindromo!\n", string);
    } else {
        printf("\"%s\" nao eh um palindromo!\n", string);
    }

    return 0;
}

bool ehPalindromo(const char* str) {

    int tamanho = strlen(str);
    int i, j;

    for (i = 0, j = tamanho - 1; i < j; i++, j--) {
        char ch1 = str[i];
        char ch2 = (str[j]);

        while (!isalpha(ch1)) {
            i++;
            ch1 = tolower(str[i]);
        }

        while (!isalpha(ch2)) {
            j--;
            ch2 = tolower(str[j]);
        }

        if (ch1 != ch2) {
            return false;
        }
    }

    return true;
}
