#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[2][3];
    int arrayt[3][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("array[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            arrayt[i][j] = array[j][i];
        }
    }

    printf("\nM:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%03d", array[i][j]);
            if(j == 2){
                printf("\n");
            }else {
                printf(" ");
            }
        }
    }

    printf("\nMt:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%03d", arrayt[i][j]);
            if(j == 1){
                printf("\n");
            }else {
                printf(" ");
            }
        }
    }
    return 0;
}