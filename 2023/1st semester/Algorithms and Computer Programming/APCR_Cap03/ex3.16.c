#include <stdio.h>
#include <stdlib.h>

int main(){

    int sqf1 = 0;
    int sqf2 = 1;
    int sqf = 0;

    printf("%d ",sqf2);

    for(int i = 0; i <= 18; i++){
        sqf = sqf1  + sqf2;
        sqf1 = sqf2;
        sqf2 = sqf;

        printf("%d ",sqf);
    }
    return 0;
}
