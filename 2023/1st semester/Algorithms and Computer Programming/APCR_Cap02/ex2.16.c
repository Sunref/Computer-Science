#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int num;
    int milhar;
    int centena;
    int dezena;
    int unidade;

    printf("Entre com um numero entre 1 e 3999: ");
    scanf("%d", &num);

    unidade = (num % 10);
    dezena = ((num / 10) % 10)*10;
    centena = ((num / 100) % 10) * 100;
    milhar = (num/1000)*1000;

    if(num> 0 && num <= 3999){
        printf("%d = ",num); 
        if(milhar == 1000){
            printf("M");
        }else if(milhar == 2000){
            printf("MM");
        }else if(milhar == 3000){
            printf("MMM");
        }

        if (centena == 100){
            printf("C");
        }else if(centena == 200){
            printf("CC");
        }else if(centena == 300){
            printf("CCC");
        }else if (centena == 400){
                printf("CD");
        }else if (centena == 500){
            printf("D");
        }else if (centena == 600){
            printf("DC");
        }else if (centena == 700){
            printf("DCC");
        }else if (centena == 800){
            printf("DCCC");
        }else if (centena == 900){
            printf("CM");
        }

        if(dezena == 10){
            printf("X");
        }else if(dezena == 20){
            printf("XX");
        }else if(dezena == 30){
            printf("XXX");
        }else if(dezena == 40){
            printf("XL");
        }else if(dezena == 50){
            printf("L");
        }else if(dezena == 60){
            printf("LX");
        }else if(dezena == 70){
            printf("LXX");
        }else if(dezena == 80){
            printf("LXXX");
        }else if(dezena == 90){
            printf("XC");
        }

        if(unidade == 1){
            printf("I");
        }else if(unidade == 2){
            printf("II");
        }else if(unidade == 3){
            printf("III");
        }else if(unidade == 4){
            printf("IV");
        }else if(unidade == 5){
            printf("V");
        }else if(unidade == 6){
            printf("VI");
        }else if(unidade == 7){
            printf("VII");
        }else if(unidade == 8){
            printf("VIII");
        }else if(unidade == 9){
            printf("IX");
        }
    }else{
        printf("Numero incorreto!");
    }
    return 0;
}
