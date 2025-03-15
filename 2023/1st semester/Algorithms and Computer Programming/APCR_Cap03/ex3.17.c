#include <stdio.h>
#include <stdlib.h>

int main(){

    int sqf1 = 0;
    int sqf2 = 1;
    int sqf = 0;
    int n;

    printf("Termo desejado: ");
    scanf("%d", &n);

    if(n == 0 || n == 1){
        printf("\nFibonacci de %d e %d ", n, sqf2);
    }else{
        for(int i = 1; i <= 20; i++){
            sqf = sqf1  + sqf2;
            sqf1 = sqf2;
            sqf2 = sqf;
            if(i == n){
                printf("\n Fibonacci de %d e %d ", n, sqf);
            }
        }
    }
    return 0;
}
