
#include <stdio.h>
#include <stdlib.h>


int main(){
    int  num1, num2,soma, sub, mult,div;
  

    printf("Primeiro número: ");
    scanf("%d",&num1);
    printf("\nSegundo número: ");
    scanf("%d",&num2);

    soma = num1+num2;
    sub = num1-num2;
    mult = num1*num2;
    div = num1/num2;

    printf("%d + %d = %d\n",num1,num2,soma);
    printf("%d - %d = %d\n",num1,num2,sub);
    printf("%d * %d = %d\n",num1,num2,mult);
    printf("%d / %d = %d",num1,num2,div);


    
    return 0;
}
