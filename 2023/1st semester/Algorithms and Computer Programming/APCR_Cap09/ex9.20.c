#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool contem(const char *fonte, const char *aPesquisar);

int main() {
    char fonte[100];
    char aPesquisar[100];

    printf("String fonte: ");
    fgets(fonte, sizeof(fonte), stdin);
    fonte[strcspn(fonte, "\n")] = '\0';  

    printf("String a pesquisar: ");
    fgets(aPesquisar, sizeof(aPesquisar), stdin);
    aPesquisar[strcspn(aPesquisar, "\n")] = '\0';  

    if (contem(fonte, aPesquisar)) {
        printf("\"%s\" esta contida em \"%s\"\n", aPesquisar, fonte);
    } else {
        printf("\"%s\" nao esta contida em \"%s\"\n", aPesquisar, fonte);
    }

    return 0;
}

bool contem(const char *fonte, const char *aPesquisar) {

    int tamanhoFonte = strlen(fonte);
    int tamanhoAPesquisar = strlen(aPesquisar);

    if (tamanhoAPesquisar > tamanhoFonte) {
        return false;
    }

    for (int i = 0; i <= tamanhoFonte - tamanhoAPesquisar; i++) {
        int j;
        for (j = 0; j < tamanhoAPesquisar; j++) {
            if (fonte[i + j] != aPesquisar[j]) {
                break;
            }
        }
        if (j == tamanhoAPesquisar) {
            return true;
        }
    }

    return false;
}
