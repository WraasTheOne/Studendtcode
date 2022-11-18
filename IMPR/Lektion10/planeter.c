#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct{
    char navn[20];
    double volumen;
    double masse;

} planet;

double beregn_rumfang(planet a);

int main(void){
    double densitet;

    planet jorden = {"jorden", (1*pow(10,21)), (6*pow(10,24))};
    planet mars = {"mars",( 6*pow(10,23)), (16*pow(10,10))};
    int valg;
    scanf("%d", &valg);

    switch(valg)
    {
    case 1:
        densitet = beregn_rumfang(jorden);
        break;
    case 2:
        densitet = beregn_rumfang(mars);
    default:
        break;
    }

    printf("%lf\n", densitet);


}

double beregn_rumfang(planet a){
    return (a.masse/a.volumen);
}