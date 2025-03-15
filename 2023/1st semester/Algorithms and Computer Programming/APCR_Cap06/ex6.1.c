#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float a;
    float b;
    float c;
    float delta;
    float x1;
    float x2;
    float temp;

    printf("a:");
    scanf("%f", &a);
    printf("b:");
    scanf("%f", &b);
    printf("c:");
    scanf("%f", &c);
    printf("\n");

    if(a == 0){
        printf("\nNao existe equacao do segundo grau!");
    }else{
        delta = pow(b,2) - 4*(a*c);
        x1 = ((-1*b) + sqrt(delta))/(2*a);
        x2 = ((-1*b) - sqrt(delta))/(2*a); 
        if(x1 > x2){
            temp = x2;
            x2 = x1;
            x1 = temp;
        }if(delta < 0){
            printf("Delta: %.2f", delta);
            printf("\nS = {}");
        }else{
            if(x1 == x2){
                printf("Delta: %.2f", delta);
                printf("\nS = {%.2f}", x1);
            }else{
                printf("Delta: %.2f", delta);
                printf("\nS = {%.2f, %.2f}", x1, x2);
            }
        }
    } 
    return 0;
}