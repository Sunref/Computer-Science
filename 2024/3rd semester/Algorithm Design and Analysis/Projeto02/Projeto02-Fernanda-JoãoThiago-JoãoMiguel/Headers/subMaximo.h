/*
*
*   Subarranjo Máximo por Fernanda, João Thiago e João Miguel.
*
*/

#ifndef SUBMAXIMO_H_INCLUDED
#define SUBMAXIMO_H_INCLUDED

typedef struct {
    char nome[10];
    int *valor;
    int tamanho;
} Acao;

typedef struct {
    int inicio;
    int fim;
    int soma;
} Subarranjo;

Acao* leAtivos(const char *caminho, int *numAcoes);
Subarranjo findMaxCrossingSubarray(int array[], int i, int m, int f);
Subarranjo findMaxSubarray(int array[], int i, int f);
void processaAtivos(Acao *acoes, int *numAcoes);

#endif //SUBMAXIMO_H_INCLUDED