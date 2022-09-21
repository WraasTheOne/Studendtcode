#include <stdio.h>

int main(void){

    int n,i;
    int x = 0;

    printf("Indtast en værdi\n");
    scanf("%d", &n);

    for(i = 0; i <= n; i++){
        x = x+i;
    }
    
    
    if(x == (n*(n+1))/2){
        printf("Talet gaer op i det");
    }
    else{
        printf("talet gaer ikke op i det");
    };


    return 0;
}