#include <stdio.h>
#include <stdlib.h>

int main(){

    int array1[3][3] = {0};
    int array2[3][3] = {0};
    int arraysoma[3][3] = {0};
    int linhat = (int) (sizeof(array1)/sizeof(array1[0]));
    int coluna = (int) (sizeof(array1[0])/sizeof(array1[0][0]));
    int c = 0;

    for(int i = 0; i < linhat; i++){
        for(int j = 0; j < coluna; j++){
        printf("array1[%d][%d]: ", i, j);
        scanf("%d", &array1[i][j]);
        }
    }
    for(int i = 0; i < linhat; i++){
        for(int j = 0 ; j < coluna; j++){
        printf("array2[%d][%d]: ", i, j);
        scanf("%d", &array2[i][j]);
        }
    }
    printf("\n");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
        arraysoma[i][j] = array1[i][j] + array2[i][j];
        }
    }
    printf("\narray1:       array2:       arraySoma:\n");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%03d", array1[i][j]);
            printf(" ");
        }
        if(i == 1){
            printf("+ ");
        }else{
            printf("  ");
        }
        for(int j = 0; j < 3; j++){
            printf("%03d", array2[i][j]);
            printf(" ");
        }
            if(i == 1){
                printf("= ");
            }else {
                printf("  ");
            }

        for(int j = 0; j < 3; j++){
            printf("%03d", arraysoma[i][j]);
            if(j == 2){
                printf("\n");
            }else {
                printf(" ");
            }
        }
    }
    return 0;
}