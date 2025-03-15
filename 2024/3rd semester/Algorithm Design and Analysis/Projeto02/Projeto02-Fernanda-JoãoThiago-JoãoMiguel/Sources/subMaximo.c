/*
*
*   Subarranjo Máximo por Fernanda, João Thiago e João Miguel.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/subMaximo.h"

Acao* leAtivos(const char *caminho, int *numAcoes){

    //Lendo o arquivo "ativos.txt"
    FILE *file = fopen(caminho, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    Acao *acoes = NULL;
    *numAcoes = 0;
    char buffer[256];
    int index = 0;
    int c;

    while((c = fgetc(file)) != EOF){
        if(c == '\n'){
            buffer[index] = '\0';

            //Processando linha lida
            Acao acao;
            char *token = strtok(buffer, ";");

            //Lendo ação
            strncpy(acao.nome, token, sizeof(acao.nome));
            acao.nome[sizeof(acao.nome) - 1] = '\0';
            acao.valor = malloc(30 * sizeof(int));
            acao.tamanho = 0;

            //Lendo valores
            while((token = strtok(NULL, ";")) != NULL){
                acao.valor[acao.tamanho++] = atoi(token);
            }

            //Realocando array para nova ação
            Acao *temp = realloc(acoes, (*numAcoes + 1) *sizeof(Acao));
            if(temp == NULL){
                perror("Erro ao alocar memoria");
                exit(1);
            }

            acoes = temp;
            acoes[*numAcoes] = acao;
            (*numAcoes)++;
            index = 0; //Resetando index para leitura da próxima linha
        }else{
            buffer[index++] = (char)c;
        }
    }

    //Processando ultima linha
    if(index > 0){
        buffer[index] = '\0';

        Acao acao;
        char *token = strtok(buffer, ";");

        //Lendo ação
        strncpy(acao.nome, token, sizeof(acao.nome));
        acao.nome[sizeof(acao.nome - 1)] = '\0';
        acao.valor = malloc(30 * sizeof(int));
        acao.tamanho = 0;

        //Lendo valores
        while((token = strtok(NULL, ";")) != NULL){
            acao.valor[acao.tamanho++] = atoi(token);
        }

        //Realocando array para nova ação
        Acao *temp = realloc(acoes, (*numAcoes + 1) * sizeof(Acao));
        if(temp == NULL){
            perror("Erro ao alocar memória");
            exit(1);
        }

        acoes = temp;
        acoes[*numAcoes] = acao;
        (*numAcoes)++;
    }

    fclose(file);
    return acoes;

}

//Busca o subarranjo maximo que cruza o meio
Subarranjo findMaxCrossingSubarray(int array[], int i, int m, int f){

    Subarranjo resultado;
    int soma = 0;
    resultado.inicio = m;
    resultado.fim = m + 1;
    int somaEsquerda = -10000;
    int somaDireita = -10000;

    for(int j = m; j >= i; j--){
        soma += array[j];
        if(soma > somaEsquerda){
            somaEsquerda = soma;
            resultado.inicio = j;
        }
    }

    soma = 0;
    for(int j = m + 1; j <= f; j++){
        soma += array[j];
        if(soma > somaDireita){
            somaDireita = soma;
            resultado.fim = j;
        }
    }

    resultado.soma = somaEsquerda + somaDireita;
    return resultado;

}

//Busca maior subarrando por divisão e conquista
Subarranjo findMaxSubarray(int array[], int i, int f){

    if(i == f){
        Subarranjo resultado = {i, f, array[i]};
        return resultado;
    }else{
        int m = (i + f)/2;

        Subarranjo esquerda = findMaxSubarray(array, i, m);
        Subarranjo direita = findMaxSubarray(array, m + 1, f);
        Subarranjo meio = findMaxCrossingSubarray(array, i, m, f);

        if(esquerda.soma >= direita.soma && esquerda.soma >= meio.soma){
            return esquerda;
        }else if(direita.soma >= esquerda.soma && direita.soma >= meio.soma){
            return direita;
        }else{
            return meio;
        }
    }

}

void processaAtivos(Acao *acoes, int *numAcoes){

    for(int i = 0; i < *numAcoes; i++){
        Acao acao = acoes[i];
        int variacoes[acao.tamanho -1];

        //Calculando variações diárias
        for(int j = 1; j < acao.tamanho; j++){
            variacoes[j - 1] = acao.valor[j] - acao.valor[j - 1];
        }

        Subarranjo resultado = findMaxSubarray(variacoes, 0, acao.tamanho - 2);

        printf("%s:\n", acao.nome);
        printf("Maior periodo de variacao: dia %d a dia %d\n", resultado.inicio, resultado.fim + 1);
        printf("Soma da variacao/segmento: %d\n\n", resultado.soma);

        free(acao.valor);

    }

}