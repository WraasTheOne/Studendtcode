#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define antal_kampe 102
#define antal_hold 12

typedef struct
{
    char ugedag[4];
    int dag;
    int maaned;
    char hold_1[4];
    char hold_2[4];
    double klokkeslaet;
    int scorer_hold_hjem;
    int scorer_hold_ude;
    int tilskuertal;
} KAMP;

typedef struct
{
    char hold_navn[4];
    int point;
    int mål_scoret;
    int mål_gået_ind;
} HOLD;

void scan_data(FILE *file, KAMP *kamp_array);

int main(void)
{
    KAMP kamp_array[antal_kampe];
    HOLD hold_array[antal_hold];

    FILE *file;
    file = fopen("fodbold_kampe.txt", "r");

    scan_data(file, kamp_array);

    indsaet_data();

    return 0;
}

void scan_data(FILE *file, KAMP *kamp_array)
{
    int indlaesninger;
    int counter = 0;

    while (!feof(file))
    {
        indlaesninger = fscanf(file, "%s %d/%d %lf %s - %s %d - %d %d\n",
                               kamp_array[counter].ugedag,
                               &kamp_array[counter].dag,
                               &kamp_array[counter].maaned,
                               &kamp_array[counter].klokkeslaet,
                               kamp_array[counter].hold_1,
                               kamp_array[counter].hold_2,
                               &kamp_array[counter].scorer_hold_hjem,
                               &kamp_array[counter].scorer_hold_ude,
                               &kamp_array[counter].tilskuertal);

        if (indlaesninger == 9)
            (counter)++;

        if (indlaesninger != 9 && !feof(file))
        {
            printf("File format incorrect.\n");
            break;
        }

        if (ferror(file))
        {
            printf("Error reading file.\n");
            break;
        }
    }
    fclose(file);
}

void indsaet_data(){


}