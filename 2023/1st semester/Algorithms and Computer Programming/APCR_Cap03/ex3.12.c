#include <stdio.h>
#include <stdlib.h>

int main(){

    int n1;
    int n2;
    int c =0;

    printf("N1: ");
    scanf("%d", &n1);
    printf("N2: ");
    scanf("%d", &n2);

    if(n1 < n2){
        for(int i = n1; i <= n2; i++){
            if(i%2 == 0){
                c++;
            }
        }
        printf("Numeros pares entre %d e %d: %d", n1, n2, c);
    }else{
        for(int i = n1; i >= n2; i--){
            if(i%2 == 0){
                c++;
            }
        }
        printf("Numeros pares entre %d e %d: %d", n2, n1, c);
    }
    return 0;
}