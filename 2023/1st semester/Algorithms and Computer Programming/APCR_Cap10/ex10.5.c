#include <stdio.h>
#include <stdlib.h>

typedef struct{

	float numerador;
    float denominador;

}Fracao;

void recebeFracao( Fracao *f1, Fracao *f2 );
Fracao somar( const Fracao *f1, const Fracao *f2 );
Fracao subtrair( const Fracao *f1, const Fracao *f2 );
Fracao multiplicar( const Fracao *f1, const Fracao *f2 );
Fracao dividir( const Fracao *f1, const Fracao *f2 );
void imprimirFracao( const Fracao *f );

int main(){

    Fracao f1;
    Fracao f2;
    Fracao f;

    recebeFracao(&f1, &f2);

    printf("\n%.2f/%.2f + %.2f/%.2f = ",f1.numerador,f1.denominador,f2.numerador,f2.denominador);
    f = somar(&f1, &f2);
    imprimirFracao(&f);

    printf("\n%.2f/%.2f - %.2f/%.2f = ",f1.numerador,f1.denominador,f2.numerador,f2.denominador);
    f = subtrair(&f1, &f2);
    imprimirFracao(&f);

    printf("\n%.2f/%.2f * %.2f/%.2f = ",f1.numerador,f1.denominador,f2.numerador,f2.denominador);
    f = multiplicar(&f1, &f2);
    imprimirFracao(&f);

    printf("\n%.2f/%.2f / %.2f/%.2f = ",f1.numerador,f1.denominador,f2.numerador,f2.denominador);
    f = dividir(&f1, &f2);
    imprimirFracao(&f);
    printf("\n");

    return 0;
}

void recebeFracao( Fracao *f1, Fracao *f2 ){

    printf("Fração 1\n");
    printf("    Numerador: ");
    scanf("%f", &f1->numerador);
    printf("    Denominador: ");
    scanf("%f", &f1->denominador);

    printf("\nFração 2\n");
    printf("    Numerador: ");
    scanf("%f", &f2->numerador);
    printf("    Denominador: ");
    scanf("%f", &f2->denominador);

}

Fracao somar( const Fracao *f1, const Fracao *f2 ){

    Fracao f;
    f.denominador = f1->denominador * f2->denominador;
    f.numerador = ((f.denominador/f1->denominador) * f1->numerador) + ((f.denominador/f2->denominador) * f2->numerador);
    return f;

}
Fracao subtrair( const Fracao *f1, const Fracao *f2 ){

    Fracao f;
    f.denominador = f1->denominador * f2->denominador;
    f.numerador = ((f.denominador/f1->denominador) * f1->numerador) - ((f.denominador/f2->denominador) * f2->numerador);
    return f;

}
Fracao multiplicar( const Fracao *f1, const Fracao *f2 ){

    Fracao f;
    f.denominador = f1->denominador * f2->denominador;
    f.numerador = f1->numerador * f2->numerador;
    return f;

}
Fracao dividir( const Fracao *f1, const Fracao *f2 ){

    Fracao f;
    f.denominador = f1->denominador * f2->numerador;
    f.numerador = f1->numerador * f2->denominador;
    return f;

}
void imprimirFracao( const Fracao *f ){

    printf("%.2f/%.2f",f->numerador,f->denominador);

}   