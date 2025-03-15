#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool ehTriangulo(int la , int lb, int lc);
int tipoTriangulo(int la , int lb, int lc);
int lePositivo();

int main(){

    char arrayletra[3] = {'A','B','C'};
    int tptri;
    int arrayn[5][3] = {0};
    int larrayn = (int)(sizeof(arrayn)/sizeof(arrayn[0]));
    int carrayn = (int)(sizeof(arrayn[0])/sizeof(arrayn[0][0]));

    for(int i = 0; i < larrayn; i++){
        for(int j = 0; j < carrayn; j++){
            printf("\nlado[%c]: ", arrayletra[j]);
            arrayn[i][j] = lePositivo();
        }
    }

    for(int i = 0; i < larrayn; i++){
        printf("Valores %d, %d e %d:", arrayn[i][0],arrayn[i][1], arrayn[i][2]);
        tptri = tipoTriangulo(arrayn[i][0], arrayn[i][1], arrayn[i][2]);
        if(tptri == 1){
            printf(" triangulo equilatero\n");
        }else if(tptri == 2){
            printf(" triangulo isosceles\n");
        }else if (tptri == 3){
            printf(" triangulo escaleno\n");  
        }else{
            printf(" nao formam um triangulo\n");
        }
    }
    return 0;
}

bool ehTriangulo(int la , int lb, int lc){

    if (((la - lb) < lc && lc <(la + lb)) && ((la - lc) < lb && lb <(la + lc)) && ((lb - lc)< la && la< (lb + lc))){
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

int tipoTriangulo(int la , int lb, int lc){

    bool ehtri;
    ehtri = ehTriangulo(la, lb, lc);
    if (ehtri == true){
        if(la == lb && la == lc){
            return 1;
        }else{
            if(la == lb || la == lc || lb == lc){
                return 2;
            }else{
                return 3;
            }
        }
    }else{
        return 0;
    }
}