#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ordem(const char *str1, const char *str2);

int main() {

    char str1;
    char str2;

    char par1p1[41];
    char par1p2[41];
    char par2p1[41];
    char par2p2[41];
    char par3p1[41];
    char par3p2[41];
    char par4p1[41];
    char par4p2[41];
    char par5p1[41];
    char par5p2[41];

    printf("\nPar 1, palavra 1: ");
    fgets(par1p1,41,stdin);
    par1p1[strlen(par1p1)-1]='\0';
    printf("\nPar 1, palavra 2: ");
    fgets(par1p2,41,stdin);
    par1p2[strlen(par1p2)-1]='\0';

    printf("\nPar 2, palavra 1: ");
    fgets(par2p1,41,stdin);
    par2p1[strlen(par2p1)-1]='\0';
    printf("\nPar 2, palavra 2: ");
    fgets(par2p2,41,stdin);
    par2p2[strlen(par2p2)-1]='\0';

    printf("\nPar 3, palavra 1: ");
    fgets(par3p1,41,stdin);
    par3p1[strlen(par3p1)-1]='\0';
    printf("\nPar 3, palavra 2: ");
    fgets(par3p2,41,stdin);
    par3p2[strlen(par3p2)-1]='\0';

    printf("\nPar 4, palavra 1: ");
    fgets(par4p1,41,stdin);
    par4p1[strlen(par4p1)-1]='\0';
    printf("\nPar 4, palavra 2: ");
    fgets(par4p2,41,stdin);
    par4p2[strlen(par4p2)-1]='\0';

    printf("\nPar 5, palavra 1: ");
    fgets(par5p1,41,stdin);
    par5p1[strlen(par5p1)-1]='\0';
    printf("Par 5, palavra 2: ");
    fgets(par5p2,41,stdin);
    par5p2[strlen(par5p2)-1]='\0';

    ordem(par1p1, par1p2);
    ordem(par2p1, par2p2);
    ordem(par3p1, par3p2);
    ordem(par4p1, par4p2);
    ordem(par5p1, par5p2);
    return 0;
}

void ordem(const char *str1, const char *str2) {
    int resultado = strcmp(str1, str2);
    if (resultado < 0) {
        printf("%s - %s: ORDEM CRESCENTE\n", str1, str2);
    }else if (resultado > 0) {
        printf("%s - %s: ORDEM DECRESCENTE\n", str1, str2);
    }else {
        printf("%s - %s: IGUAIS\n", str1, str2);
    }
}


