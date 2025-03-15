#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[100][100];
    int n;

    printf("Numero entre 1 e 100: ");
    scanf("%d", &n);
    printf("\n");

    if(n < 1 || n > 100){
        printf("Numero incorreto!\n");
        return 0;
    }else{
        for(int k = 0; k <= n/2; k++){
            for(int i = k; i < n-k; i++){
                for(int j = k; j < n-k; j++){
                    array[i][j]++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%3d", array[i][j]);
                if(j != n-1){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}