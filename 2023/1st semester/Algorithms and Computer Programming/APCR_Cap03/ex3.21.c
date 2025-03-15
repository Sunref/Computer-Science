#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;

    printf("Altura: ");
    scanf("%d", &n);
    printf("\n");

    if(n > 0){
        for(int i = 0; i < n; i++){
            for (int e = i+1; e < n; e++){
                printf(" ");
            }for(int c = 0; c <= i; c++){
                printf("*");
                if(c > 0){
                    printf("*");
                }
            }
            printf("\n");
        }
    }else{
        n *= -1;
        for(int i = n; i > 0; i--){
            for (int e = i+1; e <= n; e++){
                printf(" ");
            }for(int c = 0; c <= i-1; c++){
                printf("*");
                if(c > 0){
                    printf("*");
                }
            }
            printf("\n");
        }
    }
    return 0;
}