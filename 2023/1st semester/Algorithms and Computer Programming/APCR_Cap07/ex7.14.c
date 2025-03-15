#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void imprimeDuplaClassificada(int n1, int n2, bool impp);

int main(){

    bool impopa;
    int arrayn[5][2] = {0};
    int larrayn = (int)(sizeof(arrayn)/sizeof(arrayn[0]));
    int carrayn = (int)(sizeof(arrayn[0])/sizeof(arrayn[0][0]));

    for(int i = 0; i < larrayn; i++){
        for (int j = 0; j < carrayn; j++){
            printf("\nn%d[%d]: ", j+1, j);
            scanf("%d", &arrayn[i][j]);
        }
    }
    for(int i = 0; i < larrayn; i++){
        impopa = i % 2 == 0? true : false;
        imprimeDuplaClassificada(arrayn[i][0], arrayn[i][1], impopa);
    }
    return 0;
}

void imprimeDuplaClassificada(int n1, int n2, bool impp){

    int temp;
    printf("%d e %d:",n1,n2);
    if(impp == true){
        if(n2 < n1){
            temp = n2;
            n2 = n1;
            n1 = temp; 
        }
        printf(" %d <= %d\n",n1,n2);
    }else{
        if(n2 > n1){
            temp = n1;
            n2 = n1;
            n1 = temp;
        }
        printf(" %d >= %d\n",n1,n2);
    }
}
