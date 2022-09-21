#include <stdio.h>

int main(void){

    int n,i,j;

    printf("hvor mange rækker vil du have printet\n");
    scanf("%d",&n);


    for(j = 0; j < n; j++){
        printf("%d", j);
        for(i=0; i < j; i++){
            printf("*");
        }
        printf("\n");
    }
    

    return 0;
}