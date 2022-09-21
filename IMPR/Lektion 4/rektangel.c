#include <stdio.h>

int main(void){

    int n, m,i,j;

    printf("hvor mange rækker vil du have printet\n");
    scanf("%d %d",&n,&m);

    for(j = 0; j < n; j++){

        printf("%d", j);

        for(i=0; i < m; i++){
            printf("*");
        }
        printf("\n");
    }
    

    return 0;
}