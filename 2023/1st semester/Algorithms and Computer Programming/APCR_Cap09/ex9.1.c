#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char string[41];
    printf("String: ");
    fgets(string, 41, stdin);

    string[strlen(string)-1] = '\0';

    printf("\n%c, %c, %c, %c.", string[0], string[1], string[2], string[3]);

    return 0;
}
