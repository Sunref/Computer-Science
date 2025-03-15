#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char string1[41];
    char string2[41];
    char string3[41];

    printf("String 1: ");
    fgets(string1, sizeof(string1), stdin);

    printf("String 2: ");
    fgets(string2, sizeof(string2), stdin);

    printf("String 3: ");
    fgets(string3, sizeof(string3), stdin);

    int comprimento1 = strlen(string1);
    if (comprimento1 > 0 && string1[comprimento1 - 1] == '\n') {
        string1[comprimento1 - 1] = '\0';
        comprimento1--;
    }

    int comprimento2 = strlen(string2);
    if (comprimento2 > 0 && string2[comprimento2 - 1] == '\n') {
        string2[comprimento2 - 1] = '\0';
        comprimento2--;
    }

    int comprimento3 = strlen(string3);
    if (comprimento3 > 0 && string3[comprimento3 - 1] == '\n') {
        string3[comprimento3 - 1] = '\0';
        comprimento3--;
    }

    if (strcmp(string1, string2) > 0) {
        char temp[41];
        strcpy(temp, string1);
        strcpy(string1, string2);
        strcpy(string2, temp);
    }

    if (strcmp(string2, string3) > 0) {
        char temp[41];
        strcpy(temp, string2);
        strcpy(string2, string3);
        strcpy(string3, temp);
    }

    if (strcmp(string1, string2) > 0) {
        char temp[41];
        strcpy(temp, string1);
        strcpy(string1, string2);
        strcpy(string2, temp);
    }

    printf("Saída: %s, %s e %s\n", string1, string2, string3);
    return 0;
}
