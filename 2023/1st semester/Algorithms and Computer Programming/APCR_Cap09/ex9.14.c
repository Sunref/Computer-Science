#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void tornarMaiuscula(char *str);

int main() {

    char frase[41];

    printf("Frase: ");
    fgets(frase, 41, stdin);

    tornarMaiuscula(frase);

    printf("%s", frase);

    return 0;
}

void tornarMaiuscula(char *str){

    int i = 0;

    while(str[i] != '\0'){
        str[i] = toupper(str[i]);
        i++;
    }

}