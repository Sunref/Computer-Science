#include <stdlib.h>
#include <stdio.h>

float maiorNumero(float n1, float n2);

int main(){

    float n1;
    float n2;
    float maior;
    float arrayn[5][2] = {0};
    int larrayn = (int)(sizeof(arrayn)/sizeof(arrayn[0]));

    for(int i = 0; i < larrayn; i++){
        printf("\nn1[%d]: ",i);
        scanf("%f", &arrayn[i][0]);

        if(arrayn[i][0] < 0){
            do{
                printf("Entre com um valor positivo!");
                if(arrayn[i][0] < 0){
                    printf("\nn1[%d]: ",i);
                    scanf("%f", &arrayn[i][0]); 
                }
            }while(arrayn[i][0] < 0);
        }

        printf("\nn2[%d]: ",i);
        scanf("%f", &arrayn[i][1]); 
        if(arrayn[i][1] < 0){
            do{
                printf("Entre com um valor positivo!");
                if(arrayn[i][1] < 0){
                    printf("\nn1[%d]: ",i);
                    scanf("%f", &arrayn[i][1]); 
                }
            }while(arrayn[i][1] < 0); 
        }
    }
    for(int i = 0; i < larrayn; i++){
        maior = maiorNumero(arrayn[i][0], arrayn[i][1]);
        if(maior != -1){
            printf("\n%.2f, %.2f: O maior valor e %.2f",arrayn[i][0],arrayn[i][1],maior);
        }else{
            printf("\n%.2f, %.2f: Eles sao iguais",arrayn[i][0],arrayn[i][1]);
        }
    }
    return 0;
}

float maiorNumero(float n1, float n2){
    int t;

    if(n1 > n2){
        return n1;
    }else if(n2 == n1){
        return -1;
    }else{
        return n2;
    }
}