#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverter(char* destino, const char* origem);

int main() {

    char entrada[41];
    char saida[41];

    printf("String: ");
    fgets(entrada, sizeof(entrada), stdin);

    entrada[strcspn(entrada, "\n")] = '\0';

    inverter(saida, entrada);
    printf("Invertida: %s", saida);

    return 0;
}

void inverter(char* destino, const char* origem) {

    int tamanho = strlen(origem);

    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[tamanho - i - 1];
    }

    destino[tamanho] = '\0';
}
