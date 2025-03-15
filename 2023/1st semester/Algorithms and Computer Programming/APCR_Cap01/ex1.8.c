#include <stdio.h>
#include <stdlib.h>


int main(){
    int  valorlarg,alt,area,prmtro;


    printf("Valor do largura: ");
    scanf("%d",&valorlarg);
    printf("Valor do altura: ");
    scanf("%d",&alt);


    prmtro = valorlarg*2 + alt*2;
    area = valorlarg*alt;


    printf("Perimetro = %d\n",prmtro);
    printf("Area = %d",area);
    

    
    return 0;
}
