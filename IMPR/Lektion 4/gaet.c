#include <stdio.h>

#define RIGTIG 7

int main(void){

    int gaet, antal_gaet;

    do { 
        do {
            printf("du skal vælge et tal mellem 1 og 20");
            scanf("%d", gaet);
        } while (gaet < 1 || gaet > 20);

        if (gaet == RIGTIG){
            printf("du gaettede rigtigt");

        }
        else {
            printf("du gaettede forkert oev");
        }
        antal_gaet++;

    } while(gaet != RIGTIG);

    return 0;
}