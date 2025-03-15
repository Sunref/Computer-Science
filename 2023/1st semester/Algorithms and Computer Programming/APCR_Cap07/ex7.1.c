#include <stdlib.h>
#include <stdio.h>

int absoluto(int n);

int main(){

    int n[5];

    for(int i = 0; i < 5; i++){
        printf("n%d: ", i);
        scanf("%d", &n[i]);
    }
    
    for(int i = 0; i < 5; i++){
        printf("absoluto(%d) = %d", n[i], absoluto(n[i]));
        printf("\n");
    }
    return 0;
}

int absoluto(int n){

    if(n < 0){
        return -n;
    }
    return n;

}