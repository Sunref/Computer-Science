#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[100][100] = {0};
    int num;
    int cont;
    
    printf("Numero entre 1 e 100: ");
    scanf("%d", &num);
    printf("\n");

    if(num < 1 || num > 100){
        printf("Numero incorreto!");
    }else{
        for(int i = 0; i < num; i++){ 
            for(int j = 0; j < num; j++){
                    cont = (i-j);
                    if(cont>0){
                        array[i][j] = cont+1;
                    }else{
                        array[i][j] = (cont*(-1))+1;
                    }
            }  
        }

        for(int i = 0; i < num; i++){ 
            for(int j = 0; j < num; j++){
                if(j == num - 1){
                    printf("%3d", array[i][j]);
                    printf("\n");
                }else{
                    printf("%3d ", array[i][j]);
                }
            }  
        }
    }
    return 0;
}