#include <stdio.h>
#include <stdlib.h>


void classificaDupla(int n1, int n2);

int main(){
    int saida;
    int arrayn[3][2] = {0};
    int larrayn = (int)(sizeof(arrayn)/sizeof(arrayn[0]));
    int carrayn = (int)(sizeof(arrayn[0])/sizeof(arrayn[0][0]));

    for(int i = 0; i < larrayn; i++){
        for (int j = 0; j < carrayn; j++){
            printf("\nn%d[%d]: ", j+1, j);
            scanf("%d", &arrayn[i][j]);
        }
    }
    for(int i = 0; i < larrayn; i++){
        classificaDupla(arrayn[i][0], arrayn[i][1]);
    }
    return 0;
}
void classificaDupla(int n1, int n2){

    int temp;
    printf("%d e %d:",n1,n2);
    if(n2 < n1){
        temp = n1;
        n1 = n2;
        n2 = temp;
    }

    printf(" %d <= %d\n",n1,n2);
}
