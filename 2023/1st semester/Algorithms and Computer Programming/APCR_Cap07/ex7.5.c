#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool ehPar(int n);
bool ehDivisivel(int dividendo, int divisor);

int main(){

    bool impp;
    bool div;
    int c = 0;;
    int arrayn[5][2] = {0};
    int larrayn = (int)(sizeof(arrayn)/sizeof(arrayn[0]));

    for(int i = 0; i < larrayn; i++){
        for(int j = 0; j < 2; j++){
            printf("n[%d]: ",i);
            scanf("%d", &arrayn[i][j]);
        }
    }

    for(int i = 0; i < larrayn; i++){
        impp = ehPar(arrayn[i][0]);
        div = ehDivisivel(arrayn[i][0], arrayn[i][1]);

        printf("%d eh ", arrayn[i][0]);

        if(impp == true){
            printf("par");
        }else{
            printf("impar");
        }
        printf(" e %d", arrayn[i][0]);

        if(div == true){
            printf(" eh divisivel por %d\n", arrayn[i][1]);
        }else{
            printf(" nao eh divisivel por %d\n", arrayn[i][1]);
        }
    }
    return 0;
}

bool ehPar(int n){

    return n%2 == 0 ? true: false; 

}

bool ehDivisivel(int dividendo, int divisor){

    return dividendo%divisor == 0 ? true: false;

}