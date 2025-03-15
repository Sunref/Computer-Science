/**
*
* @author FernandaDesktop
* Torre de Hanoi
*
*/

#include <stdio.h>
#include <stdlib.h>

void hanoi(int N, int origem, int destino, int auxiliar);
void mover(int origem, int destino);

int main(){

    int N;

    printf("Entre com o numero de discos: ");
    scanf("%d", &N);

    hanoi(N, 1, 3, 2);

    return 0;

}

void hanoi(int N, int origem, int destino, int auxiliar){

    if(N > 0){
        hanoi(N-1, origem, auxiliar, destino);
        mover(origem, destino);
        hanoi(N-1, auxiliar, destino, origem);
    }

}

void mover(int origem, int destino){

    printf("Mover disco da torre %d para a torre %d\n", origem, destino);

}