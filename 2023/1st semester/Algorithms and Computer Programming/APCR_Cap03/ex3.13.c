#include <stdio.h>
#include <stdlib.h>

int main(){

	int n1;
	int n2;
	int m2 = 0;
    int m3 = 0;
    int m4 = 0;

	printf("N1: ");
	scanf("%d", &n1);
	printf("\nN2: ");
	scanf("%d", &n2);
	if(n1 < n2){
        for(int i = n1; i <= n2; i++){
            if(i%2==0){
                m2++;
            }
            if(i%3 == 0){
                m3++;
            }
            if(i%4 == 0) {
                m4++;
            }
		}
		printf("\nMultiplos de 2: %d",m2);
        printf("\nMultiplos de 3: %d",m3);
        printf("\nMultiplos de 4: %d",m4);
    }else{
        for(int i = n1; i >= n2; i--){
            if(i%2==0){
                m2++;
            }
            if(i%3 == 0){
                m3++;
            }
            if(i%4 == 0) {
                m4++;
            }
		}
		printf("\nMultiplos de 2: %d",m2);
        printf("\nMultiplos de 3: %d",m3);
        printf("\nMultiplos de 4: %d",m4);
    }
    return 0;
}
