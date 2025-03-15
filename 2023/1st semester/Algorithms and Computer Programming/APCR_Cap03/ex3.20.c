#include <stdio.h>
#include <stdlib.h>

int main(){

    for(int i = 0; i < 5;i++){
        for(int c = 0; c <=i; c++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 4; i >= 0;i--){
        for(int c = 0; c <=i; c++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < 5;i++){
        for(int e = 4-i; e >= 1; e--){
            printf(" ");
        }
        for(int c = 0; c <=i; c++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 4; i >= 0;i--){
        for(int e = 4-i; e >= 1; e--){
            printf(" ");
        }
        for(int c = 0; c <=i; c++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
