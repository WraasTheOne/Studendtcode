#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define Yatzyrunder 16

int main(void){
    int N = 0;
    N = scandata();
    if(N < 5){

        return -1;
    }
    int point[Yatzyrunder];
    int dies[N];
    



    return 0;
}

int scandata(){
    int N = 0;
    printf("atzy with how many dies (a number less than 5 terminates)");
    scanf("%d", N);
    return N;
}


void roll_multiple_dies(int N){
    int i;
    for(i = 0; i < N; i++){


    }
}