#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int contarOcorrencias(const char* str, char c);

int main() {

    char caractere;
    char frase[100];

    printf("Caractere: ");
    scanf(" %c", &caractere);

    while (1) {
        printf("Frase: ");
        scanf(" %[^\n]%*c", frase);

        if (strcmp(frase, "fim") == 0) {
            break;
        }

        int ocorrencias = contarOcorrencias(frase, caractere);
        printf("\"%s\" tem %d ocorrencia(s) do caractere '%c'\n", frase, ocorrencias, caractere);
    }

    return 0;
}

int contarOcorrencias(const char* str, char c) {

    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c) {
            count++;
        }
        i++;
    }

    return count;
}
