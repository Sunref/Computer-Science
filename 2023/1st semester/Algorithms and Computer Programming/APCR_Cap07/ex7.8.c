#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool saoAmigos(int div, int n);
int lePositivo();
int somaDivisores(int n);

int main(){

    bool amg;
    int div;
    int c = 0;
    bool arrayamg[2];
    int arrayn[5][2] = {0};
    int larrayn = (int)(sizeof(arrayn)/sizeof(arrayn[0]));

    for(int i = 0; i < larrayn; i++){
        for(int j = 0; j < 2; j++){
            printf("\nn[%d]: ", i);
            arrayn[i][j] = lePositivo();
        }
    }

    for(int i = 0; i < larrayn; i++){
        for(int j = 0; j < 2; j++){
            div = somaDivisores(arrayn[i][j]);
            if( j == 0){
                amg = saoAmigos(div, arrayn[i][j+1]);
            }else{
                amg = saoAmigos(div, arrayn[i][j-1]);
            }

            if(amg == true){
                arrayamg[j] = true;
            }else{
                arrayamg[j] = false;
            }
        }
        printf("%d e %d", arrayn[i][0], arrayn[i][1]);

        if(arrayamg[0] == true && arrayamg[1] == true){
            printf(" sao amigos\n");
        }else{
            printf(" nao sao amigos\n");
        }
    }
    return 0;
}

bool saoAmigos(int div, int n){

    if(div == n){
        return true;
    }
    return false;
}
int lePositivo(){

    int num;

    do{
        scanf("%d", &num);
        if (num <= 0){
            printf("\nEntre com um valor positivo:");
        }
    }while (num <= 0);
    return num; 
}

int somaDivisores(int n){

    int somad = 0;

    for(int i = 1; i < n; i++){
        if(n % i == 0){
            somad += i;
        }
    }
    return somad;
}