#include <stdio.h>
#include <math.h>

int main(void){
    
    double p1_x, p1_y, p2_x, p2_y, p3_x, p3_y;

    //Her bedes brugeren indtaste punkterne fra personens trekant
    printf("intast punkt 1.\n");
    scanf("%lf%lf", &p1_x, &p1_y);

    printf("intast punkt 2\n");
    scanf("%lf%lf", &p2_x, &p2_y);

    printf("intast punkt 3\n");
    scanf("%lf%lf", &p3_x, &p3_y);

    //Her gør jeg brug af pytagoras sætning a^2+b^2=c^2 til at beregne længden mellem punkterne. 
    //Derefter lægger jeg disse resultater sammen for at finde den samlede omkreds af trekanten
    double side1 = (sqrt(pow(p2_x-p1_x,2)+pow(p2_y-p1_y,2)));
    double side2 = (sqrt(pow(p3_x-p2_x,2)+pow(p3_y-p2_y,2)));
    double side3 = (sqrt(pow(p3_x-p1_x,2)+pow(p3_y-p1_y,2)));
    double samlet_sideleangde = (side1+side2+side3);

    printf("%lf\n", samlet_sideleangde);
    return 0;
}