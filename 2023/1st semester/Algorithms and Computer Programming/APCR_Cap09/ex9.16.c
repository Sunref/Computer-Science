#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void removerLetra(char* str, char c);

int main() {

    char frase[100];
    char caractere;

    printf("Frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("Caractere: ");
    scanf("%c", &caractere);

    removerLetra(frase, caractere);

    printf("Frase modificada: %s", frase);

    return 0;
}

void removerLetra(char* str, char c) {

    int i, j;

    for (i = j = 0; str[i] != '\0'; i++) {
        if (tolower(str[i]) != tolower(c)) {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';
}
