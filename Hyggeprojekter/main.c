#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159

struct planet{
    char navn[30];
    double radius;
    double volumen;
    double masse;
};
typedef struct planet planet;

planet indlaes_planet(void);
void print_planet(planet p, int længde, FILE *f);

int main(void){

    FILE *file = fopen("planet.txt", "a");


    planet p1 = {"Earth", 12756/2, 1.08e12, 5.97e24};
    planet p2 = {"Mars", 6792/2, 1.63e11, 6.42e23};

    print_planet(p1, 4, file);
    print_planet(p2, 4, file);

    fclose(file);

    return 0;
}

planet indlaes_planet(void){
    planet min_planet;

    printf("Her: %lf\n", 4.0/3.0);

    printf("Indtast et navn: \n");
    scanf("%s", min_planet.navn);
    printf("Indtast radius: \n");
    scanf("%lf", &(min_planet.radius));
    printf("Indtast masse: \n");
    scanf("%lf", &(min_planet.masse));
    min_planet.volumen =(4.0/3.0)*PI*pow(min_planet.radius,3);

    return min_planet;
}

// void print_planet(planet p){
//     printf("Navn: %s\n", p.navn);
//     printf("Radius: %lf\n", p.radius);    
//     printf("Volumen: %lf\n", p.volumen);
//     printf("Masse: %lf\n\n", p.masse);
// }


void print_planet(planet p, int længde, FILE *f){
    fprintf(f, "%s %.2e %.2e\n", p.navn, p.radius, p.masse);

}