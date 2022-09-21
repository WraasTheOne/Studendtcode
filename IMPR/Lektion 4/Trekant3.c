#include <stdio.h>

int main(void){

    int n,i,j,k,g;

    printf("hvor mange rækker vil du have printet\n");
    scanf("%d",&n);

    g = n;

    for(j = 0; j < n; j++){

        printf("%d", j);
        for(k = 0; k < g; k++){
            printf(" ");
        }
        g++;

        for(i=n; i > j; i--){
            printf("*");
        }
        printf("\n");
    }
    

    return 0;
}