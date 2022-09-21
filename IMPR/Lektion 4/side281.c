#include <stdio.h>
#include <math.h>

int main(void){

    int count_years = 0;
    int population = 9870;

    for(int i = 0; population < 30000; i++){
        population = (population*1.1);
        count_years++;
    }  

    printf("det tog %d år at få din population op på %d\n", count_years, population);

    return 0;
}