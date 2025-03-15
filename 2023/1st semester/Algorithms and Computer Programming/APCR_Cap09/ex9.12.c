#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contarOcorrencias(const char* str, char c);

int main() {

    char frase[100];

    printf("Frase: ");
    fgets(frase, sizeof(frase), stdin);

    int ocorrencias[5] = {0}; 
    char letras[5] = {'A', 'B', 'C', 'D', 'E'};

    for (int i = 0; i < 5; i++) {
        char letra_maiuscula = letras[i];
        char letra_minuscula = tolower(letra_maiuscula);

        int contagem = contarOcorrencias(frase, letra_maiuscula) +
                       contarOcorrencias(frase, letra_minuscula);

        ocorrencias[i] = contagem;
    }

    for (int i = 0; i < 5; i++) {
        char letra_maiuscula = letras[i];
        char letra_minuscula = tolower(letra_maiuscula);

        printf("%c/%c: %d\n", letra_maiuscula, letra_minuscula, ocorrencias[i]);
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
