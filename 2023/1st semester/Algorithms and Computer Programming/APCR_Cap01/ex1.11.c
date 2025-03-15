#include <stdio.h>
#include <stdlib.h>


int main(){
    int  diagma,diagme,area;


    printf("Valor da diagonal maior: ");
    scanf("%d",&diagma);
    printf("Valor da diagonal menor: ");
    scanf("%d",&diagme);

    area = (diagma*diagme)/2;



    printf("Area = %d",area);
    

    
    return 0;
}
