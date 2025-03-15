/**
*
* @author FernandaDesktop
* Ordenação Decrescente
*
*/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

void geraArray(int arrayA[], int n ); 
void imprimeArray(int arrayA[], int n, char msg[]);
void ordenaArray( int arrayA[], int n);
void copiaArray(int arrayA[], int arrayB[], int n);

int numOP = 0; //variavel global para calculo do numero de operacoes

int main(){

    int n; 
    int *array; 
    int *arrayTemp; 

    printf("Entre com o tamanho do Array de Inteiros: "); 
    scanf(" %d", &n);

    array  = (int*)malloc(n * sizeof(int)); //definindo um array com o tamanho fornecido pelo usuario
    arrayTemp = (int*)malloc(n * sizeof(int)); //definindo um array temporario (para ordenacao) com o tamanho fornecido pelo usuario

    geraArray(array, n);
    imprimeArray( array, n, "Array Desord.[]"); 

    copiaArray(array, arrayTemp, n); 
    ordenaArray(arrayTemp, n);
    imprimeArray( arrayTemp, n, "Array Ord.   []");

    printf(" \n Numero de Operacoes para Ordenacao: %d", numOP);
    return 0;

}

void geraArray(int arrayA[], int n ){

    int ale;

    srand(time(NULL)); //preenchendo o array[N] com numeros aleatorios

    for(int i = 0; i < n ; i++){
        ale = rand() % 100;
        arrayA[i] = ale;
    }

}

void imprimeArray(int arrayA[], int n, char msg[]) {

    printf("\n %s =", msg);
    for(int i =0; i < n; i++){
        printf(" %d", arrayA[i] );
    }

}

void ordenaArray( int arrayA[], int n){ //ordenando array com o metodo de InsertionSort()

    int chave; 
    for(int j = 1; j< n;j++){
        numOP ++;
        chave = arrayA[j]; 
        printf(" - %d", chave);
        int i = j -1;

        while ((i >= 0) & (arrayA[i]> chave)){  
            numOP ++;            
            arrayA [i + 1] = arrayA [i];
            i--;
        }
        arrayA [ i + 1] = chave; 
        imprimeArray(arrayA, n, "Array Ord. Decrescente[]");
    }

}

void copiaArray(int arrayA[], int arrayB[], int n){

    for(int i = 0; i < n; i++){
        arrayB[i] = arrayA[i]; 
    }

}