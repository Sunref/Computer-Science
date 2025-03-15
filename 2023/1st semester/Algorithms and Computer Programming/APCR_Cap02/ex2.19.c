#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    float temp;
    float cel;
    float far;
    char op;

    printf("Escolha uma operacao de acordo com o menu:\n        C) Celsius -> Fahrenheit;\n         F) Fahrenheit -> Celsius.\nOpcao: ");
    scanf(" %c", &op);

    switch (op){
        case 'C':
            printf("Entre com a temperatura em graus Celsius: ");
            scanf("%f", &cel);
            far = 1.8 * cel + 32;
            printf("\n%.2f graus Celsius correspondem a %.2f graus Fahrenheit", cel, far);
            break;

        case 'F':
            printf("Entre com a temperatura em graus Fahrenheit: ");
            scanf("%f", &far);
            cel = (far-32)/1.8;
            printf("\n%.2f graus Fahrenheit correspondem a %.2f graus Celsius", far, cel);
            break;

        default:
            printf("\nOpcao invalida!");
    }      
    return 0;
}