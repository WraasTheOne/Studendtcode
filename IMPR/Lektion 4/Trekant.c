#include <stdio.h>

int main(void){

    int n,i,j,k,g;

    printf("hvor mange rækker vil du have printet\n");
    scanf("%d",&n);

    g = n;

    for(j = 0; j < n; j++){

        printf("%d", j);
        for(k = g; k > 0; k--){
            printf(" ");
        }
        g--;

        for(i=0; i < j; i++){
            printf("*");
        }
        printf("\n");
    }
    

    return 0;
}