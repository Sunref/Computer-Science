#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool ehPrimo();

int main(){

    bool valid;
    for(int i = 1; i <= 20; i++){
        valid = ehPrimo(i);
        printf("%d: ", i);

        if(valid == true){
            printf("eh primo\n");
        }else{
            printf("nao eh primo\n");
        }
    }
    return 0;
}

bool ehPrimo(int n){
    int c = 0;
    for(int i = 1; i <= n; i++){
        if(n % i != 0){
            c++;
        }
    }
    if(c == (n - 2)){
        return true;
    }else{
        return false;
    }
}
