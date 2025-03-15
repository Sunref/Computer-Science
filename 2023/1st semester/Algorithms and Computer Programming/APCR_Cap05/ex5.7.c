#include <stdio.h>
#include <stdlib.h>

int main(){

    int array1[3][2];
    int array2[2][3];
    int arrayresult[3][3] = {{0}};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            printf("array1[%d][%d]: ", i, j);
            scanf("%d", &array1[i][j]);
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0 ; j < 3; j++){
            printf("array2[%d][%d]: ", i,j);
            scanf("%d", &array2[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                arrayresult[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }

    printf("\nA x B =\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%03d", arrayresult[i][j]);
            if( j == 2){
                printf("\n");
            }else{
                printf(" ");
            }
        }
    }
    return 0;
}