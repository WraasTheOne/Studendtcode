#include <stdio.h>
#include <math.h>

#define PI 3.14159

double regn_omkreds(double radius);
void print_omkreds(double omkre);

double regn_areal(double radius);
void print_areal(double radius);

int main(void){
    int valg;
    double radius, omkreds, omkreds2, areal;
    printf(" vil du have regnet et areal så tast 1  og 0 for omkreds\n");
    scanf("%d", &valg);

    printf("Indtast en radius:\n");
    scanf("%lf", &radius);

    if (valg == 1){
        areal = regn_areal(radius);

        print_areal(areal);
    }

    else{
        //Regne omkredsen
        omkreds = regn_omkreds(radius);

        omkreds2 = regn_omkreds(2 * radius);
        //Printe ud
        print_omkreds(omkreds);
        print_omkreds(omkreds2);


    }


    return 0;
}

double regn_omkreds(double radius){
  return 2 * PI * radius;
}

void print_omkreds(double omkre){
  printf("Omkredsen er %lf\n", omkre);
}

double regn_areal(double radius){
    return PI* pow(radius,2);
}

void print_areal(double areal){
    printf("Arealet af din cirkel er %lf", areal);
}