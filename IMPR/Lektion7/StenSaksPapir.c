#include <stdio.h>

enum planeter
{
    merkur,
    venus,
    jorden,
    mars,
    jupiter,
    saturn,
    uranus,
    neptun
};
typedef enum planeter planeter;

#define merkur_radius 15329
#define venus_radius 38025
#define jorden_radius 40075
#define mars_radius 21344
#define jupiter_radius 439264
#define saturn_radius 378675
#define uranus_radius 160590
#define neptun_radius 155600

void print_planet_omkreds(planeter p);
planeter planet_from_char(int p);

int main(void)
{
    planeter planet;
    int planet_nr;

    printf("skriv forbogstavet på din planet\n");
    scanf("%d", &planet_nr);

    planet = planet_from_char(planet_nr);
    print_planet_omkreds(planet);

    return 0;
}

planeter planet_from_char(int p)
{
    planeter v_planet;
    switch (p)
    {
    case (1):
        v_planet = merkur;
        break;
    case 2:
        v_planet = venus;
        break;
    case 3:
        v_planet = jorden;
        break;
    case 4:
        v_planet = mars;
        break;
    case 5:
        v_planet = jupiter;
        break;
    case 6:
        v_planet = saturn;
        break;
    case 7:
        v_planet = uranus;
        break;
    case 8:
        v_planet = neptun;
        break;
    }
    return v_planet;
}

void print_planet_omkreds(planeter p)
{
    switch (p)
    {
    case merkur:
        printf("merkurs har en omrkeds på %d km\n", merkur_radius);
        break;
    case venus:
        printf("venus omkreds er på %d km\n", venus_radius);
        break;
    case jorden:
        printf("jorden omkreds er på %d km\n", jorden_radius);
        break;
    case mars:
        printf("mars omkreds er på %d km\n", mars_radius);
        break;
    case jupiter:
        printf("jupiters omkreds er på %d km\n", jupiter_radius);
        break;
    case saturn:
        printf("saturn omkreds er på %d km\n", saturn_radius);
        break;
    case uranus:
        printf("uranus' omkreds er på %d km\n", uranus_radius);
        break;
    case neptun:
        printf("neptun omkreds er på %d km\n", neptun_radius);
        break;
    }
}