#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[3][4];
    int arraymult[3][4];
    int mult;

    for(int i = 0; i < 3 ; i++){
        for(int j = 0; j < 4; j++){
            printf("array[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    printf("Multiplicar por: ");
    scanf("%d", &mult);
    printf("\n");

    for(int i = 0; i<3; i++){
        for(int j = 0 ; j<4; j++){
            arraymult[i][j] = array[i][j]*mult;
        }
    }
    printf("\n");

    printf("arrayMult:\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%03d", arraymult[i][j]);
            if(j == 3){
                printf("\n"); 
            }else{
                printf(" ");
            }
        }
    }
    return 0;
}