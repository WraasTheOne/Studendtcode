#include <stdio.h>

int main(void){
    double r, x, y;
    
    printf("indtast din ønskede radius\n");
    scanf("%lf", &r);

    printf("indtast dit kordinat\n");
    scanf("%lf%lf", &x, &y);

    printf((x<r && y<r && -r<x && -r<y)? "punktet ligger inden for cirklen": "punktet ligger ikke inden for cirklen");
    return 0;
}