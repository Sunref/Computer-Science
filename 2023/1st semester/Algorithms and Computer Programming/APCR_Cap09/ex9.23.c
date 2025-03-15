#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirCaixa(const char *str);

int main() {
    char str[100];

    printf("String: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  

    printf("\n");
    imprimirCaixa(str);

    return 0;
}

void imprimirCaixa(const char *str) {
    int tamanhoStr = strlen(str);
    int larguraCaixa = tamanhoStr + 4;

    printf("++");
    for (int i = 0; i < larguraCaixa - 2; i++) {
        printf("=");
    }
    printf("++\n");

    printf("|| ");
    printf("%s", str);
    for (int i = 0; i < larguraCaixa - tamanhoStr - 3; i++) {
        printf(" ");
    }
    printf("||\n");

    printf("++");
    for (int i = 0; i < larguraCaixa - 2; i++) {
        printf("=");
    }
    printf("++\n");
}
