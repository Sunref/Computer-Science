#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void tornarMinuscula(char *str);

int main() {

    char frase[41];

    printf("Frase: ");
    fgets(frase, 41, stdin);

    tornarMinuscula(frase);

    printf("%s", frase);

    return 0;
}

void tornarMinuscula(char *str){

    int i = 0;

    while(str[i] != '\0'){
        str[i] = tolower(str[i]);
        i++;
    }

}