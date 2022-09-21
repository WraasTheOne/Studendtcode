#include <stdio.h>

int main(void){

    int i,j,k,x;
    for(i = 0; i <= 5; i++){
        for(j = 0; j <= i; j++){
        printf("%d ", j);
    }
    printf("\n");
    }

    for(k = 4; k >= 0; k--){
        for(x = 0; x <= k; x++){
        printf("%d ", x);
    }
    printf("\n");
    }
    
    return 0;
}