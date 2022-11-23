#include <stdio.h>
#include <string.h>

struct bilkort
{
    char navn[30];
    int top_fart;
    int hk;
    int acceleration;
    int ccm;
};

typedef struct bilkort bilkort;

void udskriv_kort(bilkort bil);
void skriv_kort_til_fil(FILE *file, bilkort b);
void skriv_alle_kort_til_fil(FILE *f, bilkort ba[], int længde);
bilkort læs_kort(FILE *fil);

bilkort indlaes_bilkort(void);

int main(void)
{
    bilkort b1 = {"Lotus", 200, 110, 8, 1973};
    bilkort b2 = {"Mercedes", 215, 160, 9, 4520};
    bilkort ba[2] = {b1, b2};

    udskriv_kort(b1);
    printf("\n");
    udskriv_kort(b2);

    FILE *f = fopen("fil.txt", "w");

    skriv_alle_kort_til_fil(f, ba, 2);
    //   skriv_kort_til_fil(f, b1);

    fclose(f);

    f = fopen("fil.txt", "r");

    bilkort b3 = læs_kort(f);

    printf("Her er det læste kort:\n");
    udskriv_kort(b3);

    fclose(f);

    return 0;
}

void udskriv_kort(bilkort bil)
{
    // Hiv vaerdierne ud
    char *n = bil.navn;
    int f = bil.top_fart;
    int hest = bil.hk;
    int a = bil.acceleration;
    int ccm = bil.ccm;

    // Print
    printf("\n Navn: %s", n);
    printf("\n Top fart: %d", f);
    printf("\n HK: %d", hest);
    printf("\n Acceleration: %d", a);
    printf("\n CCM: %d\n", ccm);
}

bilkort indlaes_bilkort(void)
{
    char navnet[30];
    int f;
    int hk;
    int acc;
    int ccm;

    // Indlæs fra tastatur.
    printf("Tast et navn: \n");
    scanf("%s", navnet);
    printf("Tast topfart:\n");
    scanf("%d", &f);
    printf("Tast hestekrafter:\n");
    scanf("%d", &hk);
    printf("Tast acceleration:\n");
    scanf("%d", &acc);
    printf("Tast ccm:\n");
    scanf("%d", &ccm);

    // Opret bilkort og læg værdierne ind.
    bilkort nyt_kort;
    strcpy(nyt_kort.navn, navnet);
    nyt_kort.top_fart = f;
    nyt_kort.hk = hk;
    nyt_kort.acceleration = acc;
    nyt_kort.ccm = ccm;

    return nyt_kort;
}

void skriv_kort_til_fil(FILE *file, bilkort b)
{
    fprintf(file, "%s %d %d %d %d\n", b.navn, b.top_fart, b.hk, b.acceleration, b.ccm);
}

void skriv_alle_kort_til_fil(FILE *f, bilkort ba[], int længde)
{
    for (int i = 0; i < længde; i++)
    {
        skriv_kort_til_fil(f, ba[i]);
    }
}

bilkort læs_kort(FILE *fil){
    bilkort b;
    fscanf(fil, "%s %d %d %d %d", b.navn, &b.top_fart, &b.hk, &b.acceleration, &b.ccm);
    return b;
}