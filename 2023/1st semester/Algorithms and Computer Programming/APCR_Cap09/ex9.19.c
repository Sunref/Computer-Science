#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substring(char *recorte, const char *origem, int inicio, int fim);

int main() {

    char string[100];
    int inicio, fim;
    char recorte[100];

    printf("String: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';  

    printf("Inicio: ");
    scanf("%d", &inicio);

    printf("Fim: ");
    scanf("%d", &fim);

    substring(recorte, string, inicio, fim);

    printf("Recorte: %s\n", recorte);

    return 0;
}

void substring(char *recorte, const char *origem, int inicio, int fim) {

    int tamanho = strlen(origem);

    if (inicio >= 0 && inicio < tamanho && fim > inicio && fim <= tamanho) {
        int i, j;
        for (i = inicio, j = 0; i < fim; i++, j++) {
            recorte[j] = origem[i];
        }
        recorte[j] = '\0';
    } else {
        strcpy(recorte, origem);
    }
}
