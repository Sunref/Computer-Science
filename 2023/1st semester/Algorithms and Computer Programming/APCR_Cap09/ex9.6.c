#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    char nome[41];

    printf("Nome:");
    fgets(nome, 41, stdin);
    nome[strlen(nome)-1] = '\0';

    for(int i = 0; i < strlen(nome); i++){
        printf("%s\n", nome);
    }
    return 0;
}