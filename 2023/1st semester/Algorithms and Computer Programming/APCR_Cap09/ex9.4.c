#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {

    char sentenca[41];

    printf("Sentenca: ");
    fgets(sentenca, 41, stdin);
    sentenca[strlen(sentenca)-1] = '\0';

    for(int i = 0; i < strlen(sentenca); i++){
        if(i % 2 != 0){
            if(sentenca[i] == ' '){
        printf("' ', ", sentenca[i]);
            }else{
            printf("%c", sentenca[i]);  
            if(i != strlen(sentenca) -1 ){
                printf(", ");
                }
            }
        }
    }
    return 0;
}
