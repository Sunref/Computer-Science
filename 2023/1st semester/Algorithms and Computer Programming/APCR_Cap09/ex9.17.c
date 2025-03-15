#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int contarPalavras(const char* str);

int main() {

    char frase[100];

    printf("Frase: ");
    fgets(frase, sizeof(frase), stdin);

    int quantidadePalavras = contarPalavras(frase);

    printf("Quantidade de palavras: %d\n", quantidadePalavras);

    return 0;
}

int contarPalavras(const char* str) {

    int quantidade = 0;
    bool dentroPalavra = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            if (!dentroPalavra) {
                dentroPalavra = true;
                quantidade++;
            }
        } else {
            dentroPalavra = false;
        }
    }

    return quantidade;
}
