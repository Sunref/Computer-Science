#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

    char sentenca[41];

    printf("Sentenca: ");
    fgets(sentenca, 41, stdin);
    sentenca[strlen(sentenca)-1] = '\0';

    int comprimento = strlen(sentenca);

    if (comprimento > 0 && sentenca[comprimento - 1] == '\n') {
        sentenca[comprimento - 1] = '\0';
        comprimento--;
        }

    printf("Caracteres das posicoes pares: ");
    for (int i = 0; i < comprimento; i += 2) {
        if (sentenca[i] == ' ') {
            printf("'%c'", sentenca[i]);
            } else {
            printf("%c", sentenca[i]);
            }

        if (i < comprimento - 2) {
            printf(", ");
            }
        }
    printf("\n");

    return 0;
}