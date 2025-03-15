#include <stdio.h>
#include <stdlib.h>

void trocar(int *n1, int *n2);

int main(){

    int n1;
    int n2;

    printf("n1: ");
    scanf("%d", &n1);
    printf("n2: ");
    scanf("%d", &n2);

    printf("\nAntes:");
    printf("\n    n1: %d", n1);
    printf("\n    n2: %d", n2);

    trocar(&n1, &n2);

    printf("\nDepois:");
    printf("\n    n1: %d", n1);
    printf("\n    n2: %d", n2);
    return 0;
}

void trocar(int *n1, int *n2){

    int t;
    t = *n1;
    *n1 = *n2;
    *n2 = t;
}