#include <stdio.h>
#include <stdlib.h>

int buscar(const int *a, int n, int chave);

int main(){

    int n[10];
    int busca;

    for(int i = 0; i < 10; i++){
        printf("n[%d]: ", i);
        scanf("%d", &n[i]);
    }

    printf("Buscar por: ");
    scanf("%d", &busca);

    if(buscar(n, 10, busca) != -1){
        printf("O valor %d foi encontrado na posicao %d.", busca, buscar(n, 10, busca));
    }else{
        printf("O valor %d nao foi encontrado.", busca);
    }
    return 0;
}

int buscar(const int *a, int n, int chave){

    for(int i = 0; i < 10; i++){
        if(a[i] == chave)
        return i;
    }

    return -1;
}