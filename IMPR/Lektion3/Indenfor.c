#include <stdio.h>

int main(void){

    double r, x, y;
    printf("indtast din ønskede radius\n");
    scanf("%lf", &r);

    printf("indtast dit kordinat\n");
    scanf("%lf%lf", &x, &y);

    if (x<r && y<r && -r<x && -r<y){
        printf("dit indtastede punkt (%lf,%lf) ligger inden for cirklen med radius %lf.", x, y, r);
    } 

    else{
        printf("dit indtastede punkt (%lf,%lf) ligger ikke inden for cirklen med radius %lf.", x, y, r);
    }

}