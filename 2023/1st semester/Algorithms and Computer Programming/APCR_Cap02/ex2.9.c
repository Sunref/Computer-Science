#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    float medidaLado;
    float quantidadeLado;

    printf("Entre com a quantidade de lados: ");
    scanf("%f", &quantidadeLado);
    printf("Entre com a medida do lado: ");
    scanf("%f", &medidaLado);

    if(quantidadeLado == 3){
        printf("TRIANGULO de perimetro %.2f", medidaLado*3);
    }else if(quantidadeLado == 4){
        printf("QUADRADO de area %.2f", medidaLado*medidaLado);
    }else if(quantidadeLado == 5){
        printf("PENTAGONO");
    }else{
        printf("Poligono nao identificado");
    }
    return 0;
}