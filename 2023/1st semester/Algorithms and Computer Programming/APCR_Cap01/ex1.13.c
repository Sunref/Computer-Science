#include <stdio.h>
#include <stdlib.h>

int main(){
    float  num1,num2,sm,sub,mult,div;

    printf("Primeiro número: ");
    scanf("%f",&num1);
    printf("\nSegundo número: ");
    scanf("%f",&num2);

    sm = num1+num2;
    sub  = num1-num2;
    mult = num1*num2;
    div  = num1/num2;

    printf("%.2f + %.2f = %.2f\n",num1,num2,sm);
    printf("%.2f - %.2f = %.2f\n",num1,num2,sub);
    printf("%.2f * %.2f = %.2f\n",num1,num2,mult);
    printf("%.2f / %.2f = %.2f",num1,num2,div);

    return 0;
}