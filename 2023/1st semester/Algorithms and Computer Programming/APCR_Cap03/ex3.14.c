#include <stdio.h>
#include <stdlib.h>

int main(){

    int n1;
    int n2;
    int s =0;

    printf("N1: ");
    scanf("%d", &n1);
    printf("N2: ");
    scanf("%d", &n2);

    if(n1 < n2){
        for(int i = n1; i <= n2; i++){
            s += i;
        }
        printf("Somatorio entre %d e %d: %d", n1, n2, s);
    }else{
        for(int i = n1; i >= n2; i--){
            s += i;
        }
        printf("Somatorio entre %d e %d: %d", n2, n1, s);
    }
    return 0;
}