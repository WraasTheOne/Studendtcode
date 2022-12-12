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
void indsaet_data();
void hold_navne(HOLD *hold, KAMP *kampe);
void indsaet_data(int mål_scoret, int mål_gået_ind, HOLD *hold, char hold_navn[4]);
void print_output(HOLD *hold);
int compare(const void *a, const void *b);

int main(void)
{
    KAMP kamp_array[antal_kampe];
    HOLD hold_array[antal_hold] = {0};

    FILE *file;
    file = fopen("fodbold_kampe.txt", "r");

    scan_data(file, kamp_array);

    hold_navne(hold_array, kamp_array);
    for (int i = 0; i < antal_kampe; i++)
    {
        indsaet_data(kamp_array[i].scorer_hold_hjem, kamp_array[i].scorer_hold_ude, hold_array, kamp_array[i].hold_1);
        indsaet_data(kamp_array[i].scorer_hold_ude, kamp_array[i].scorer_hold_hjem, hold_array, kamp_array[i].hold_2);
    }

    qsort(hold_array, antal_hold, sizeof(HOLD), compare);

    print_output(hold_array);

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

void hold_navne(HOLD *hold, KAMP *kampe)
{

    for (int j = 0; j < antal_kampe; ++j)
    {
        for (int k = 0; k < antal_hold; ++k)
        {
            if (strcmp(kampe[j].hold_1, hold[k].hold_navn) == 0)
            {
                break;
            }
            else if (strcmp(kampe[j].hold_1, hold[k].hold_navn) != 0 && hold[k].hold_navn[0] == '\000')
            {
                strncpy(hold[k].hold_navn, kampe[j].hold_1, 4);
                break;
            }
        }
    }
}

void indsaet_data(int mål_scoret, int mål_gået_ind, HOLD *hold, char hold_navn[4])
{
    int i = 0;
    for (i = 0; i < antal_hold; ++i)
    {
        if (strcmp(hold_navn, hold[i].hold_navn) == 0)
        {
            break;
        }
    }

    int point = mål_scoret - mål_gået_ind;
    if (point == 0)
    {
        hold[i].point += 1;
    }
    else if (point > 0)
    {
        hold[i].point += 3;
    }
    hold[i].mål_scoret += mål_scoret;
    hold[i].mål_gået_ind += mål_gået_ind;
}

int compare(const void *a, const void *b)
{

    HOLD *hold_1 = (HOLD *)a;
    HOLD *hold_2 = (HOLD *)b;

    return (hold_2->point - hold_1->point);
}

void print_output(HOLD *hold)
{
    for (int j = 0; j < 12; ++j)
    {
        if (hold[j].hold_navn[2] == '\000' || hold[j].point < 10)
        {
            printf(" ");
        }
        printf("%s:%d:%d", hold[j].hold_navn, hold[j].point, hold[j].mål_scoret);
        printf("\n");
    }
}