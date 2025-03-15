/*
*
*   Subarranjo Máximo por Fernanda, João Thiago e João Miguel.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subMaximo.c"

int main(){

    int numAcoes;
    Acao *acoes = leAtivos("../Resources/ativos.txt", &numAcoes);

    printf("\n/ --- Subarranjo Maximo --- /\n\n");
    processaAtivos(acoes, &numAcoes);
    printf("/ ------------------------- /\n");

    free(acoes);
    return 0;

}