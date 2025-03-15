#include <stdio.h>
#include <stdlib.h>

int main(){

    int n1;
    int n2;
    int div;
    char esc;

    do{
        printf("N1: ");
        scanf("%d", &n1);
        printf("N2: ");
        scanf("%d", &n2);

        while(n2 == 0){
            printf("Nao existe divisao inteira por zero!");
            printf("\nEntre novamente com N2: ");
            scanf("%d", &n2);
        }
        div = n1/n2;
        printf("%d / %d = %d", n1, n2, div);
        printf("\nVoce deseja realizar outro calculo? (S/N): ");
        scanf(" %c", &esc);
    }while(esc == 'S');
    return 0;
}