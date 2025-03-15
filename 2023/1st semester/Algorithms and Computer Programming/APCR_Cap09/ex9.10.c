#include <stdio.h>
#include <stdlib.h>

int tamanho(const char* str);

int main() {

    char frase[100];

    printf("Frase: ");
    fgets(frase, sizeof(frase), stdin);

    int tam = tamanho(frase);
    printf("%d caractere(s)!\n", tam);

    return 0;
}

int tamanho(const char* str) {

    int count = 0;

    while (str[count] != '\0') {
        count++;
    }

    return count-1;
}
