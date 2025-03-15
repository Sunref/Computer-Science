#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char sentenca[41];

    printf("Sentenca: ");
    fgets(sentenca, 41, stdin);

    sentenca[strcspn(sentenca, "\n")] = '\0';

    printf("Primeiro caractere: %c\n", sentenca[0]);
    printf("Ultimo caractere: %c\n", sentenca[strlen(sentenca)-1]);
    printf("Numero de caracteres: %d", strlen(sentenca));
    return 0;
}