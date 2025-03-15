#include <stdio.h>
#include <stdlib.h>


void classificaTrinca(int n1, int n2, int n3);

int main(){
    
    int arrayn[3][3] = {0};
    int larrayn = (int)(sizeof(arrayn)/sizeof(arrayn[0]));
    int carrayn = (int)(sizeof(arrayn[0])/sizeof(arrayn[0][0]));

    for(int i = 0; i < larrayn; i++){
        for (int j = 0; j < carrayn; j++){
            printf("\nn%d[%d]: ", j+1, j);
            scanf("%d", &arrayn[i][j]);
        }
    }
    for(int i = 0; i < larrayn; i++){
        classificaTrinca(arrayn[i][0], arrayn[i][1], arrayn[i][2]);
    }
    return 0;
}

void classificaTrinca(int n1, int n2, int n3){

    int temp;
    int temp2;
    printf("%d, %d e %d:", n1, n2, n3);
    if(n2 < n1 && n1 < n3){
        temp = n1;
        n1 = n2;
        n2 = temp;
    }else if(n3 < n2 && n2 < n1){
        temp = n1;
        n1 = n3;
        n3 = temp;
    }else if(n2 < n3 && n3 < n1){
        temp = n2;
        n2 = n3;
        temp2 = n1;
        n1 = temp;
        n3 = temp2;
    }else if(n3 < n1 && n1 < n2){
        temp = n1;
        n1 = n3;
        temp2 = n3;
        n3 = temp;
        n2 = temp2;
    }else if(n1 < n3 && n3 < n2){
        temp = n2;
        n2 = n3;
        n3 = temp;
    }

    printf(" %d <= %d <= %d\n",n1, n2, n3);
}
