#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirDireita(const char *str);

int main() {

    char str[100];

    printf("String: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  

    imprimirDireita(str);

    return 0;
}

void imprimirDireita(const char *str) {

    int tamanhoStr = strlen(str);
    int espacosEsquerda = 80 - tamanhoStr;

    for (int i = 0; i < espacosEsquerda; i++) {
        printf(" ");
    }

    printf("%s\n", str);
}
