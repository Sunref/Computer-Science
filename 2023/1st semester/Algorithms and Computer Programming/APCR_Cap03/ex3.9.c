#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    int m;

    printf("Tabuada do numero: ");
    scanf("%d", &n);

    for(int i = 0; i <=10; i++){
        m = n*i;
        printf("%d x %d = %d\n", n, i, m);
    }
    return 0;
}