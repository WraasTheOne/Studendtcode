/*
Nicholas Mazur Hansen
nmha22@student.aau.dk
Cyber- og computerteknologi
*/
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
void indsaet_data(KAMP kamp_array[], HOLD *hold_array);
void print_output(HOLD *hold);
int compare(const void *a, const void *b);
int index_af_hold(char *hold_navn);
int kamp_point_resultat(HOLD *hold, KAMP kamp);
int er_strenge_lig(char *str1, char *str2);

int main(void)
{
    KAMP kamp_array[antal_kampe];
    HOLD hold_array[antal_hold] = {0};

    FILE *file;
    file = fopen("fodbold_kampe.txt", "r");

    scan_data(file, kamp_array);

    indsaet_data(kamp_array, hold_array);

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

void indsaet_data(KAMP kamp_array[], HOLD *hold_array)
{
    int index_hjemme, index_ude;

    for (int i = 0; i < antal_kampe; i++)
    {
        char *hjemme_hold_navn = kamp_array[i].hold_1;
        char *ude_hold_navn = kamp_array[i].hold_2;

        index_hjemme = index_af_hold(hjemme_hold_navn);
        index_ude = index_af_hold(ude_hold_navn);

        HOLD *hjemme_hold = &hold_array[index_hjemme];
        HOLD *ude_hold = &hold_array[index_ude];

        strcpy(hjemme_hold->hold_navn, hjemme_hold_navn);
        hjemme_hold->point += kamp_point_resultat(hjemme_hold, kamp_array[i]);
        hjemme_hold->mål_scoret += kamp_array[i].scorer_hold_hjem;
        hjemme_hold->mål_gået_ind += kamp_array[i].scorer_hold_ude;

        strcpy(ude_hold->hold_navn, ude_hold_navn);
        ude_hold->point += kamp_point_resultat(ude_hold, kamp_array[i]);
        ude_hold->mål_scoret += kamp_array[i].scorer_hold_ude;
        ude_hold->mål_gået_ind += kamp_array[i].scorer_hold_hjem;
    }
}

int kamp_point_resultat(HOLD *hold, KAMP kamp)
{
    int mål_forskel, mål_scoret, mål_gået_ind;

    if (strcmp(hold->hold_navn, kamp.hold_1))
    {
        mål_scoret = kamp.scorer_hold_ude;
        mål_gået_ind = kamp.scorer_hold_hjem;
    }
    else
    {
        mål_scoret = kamp.scorer_hold_hjem;
        mål_gået_ind = kamp.scorer_hold_ude;
    }

    mål_forskel = mål_scoret - mål_gået_ind;

    if (mål_forskel > 0)
    {
        return 3;
    }
    else if (mål_forskel == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int compare(const void *a, const void *b)
{
    int maal_forskel_1, maal_forskel_2;

    HOLD *hold_1 = (HOLD *)a;
    HOLD *hold_2 = (HOLD *)b;

    if (hold_1->point == hold_2->point)
    {
        maal_forskel_1 = hold_1->mål_scoret - hold_1->mål_gået_ind;
        maal_forskel_2 = hold_2->mål_scoret - hold_2->mål_gået_ind;
        return maal_forskel_1 - maal_forskel_2;
    }
    else
    {
        return (hold_2->point - hold_1->point);
    }
}

void print_output(HOLD *hold)
{
    printf("holdnavn : point : mål scoret : mål gået ind\n");
    for (int j = 0; j < 12; ++j)
    {
        printf("%s\t :   %d\t :\t   %d :\t\t  %d\n", hold[j].hold_navn, hold[j].point, hold[j].mål_scoret, hold[j].mål_gået_ind);
    }
}

int index_af_hold(char *hold_navn)
{
    if (er_strenge_lig(hold_navn, "FCM"))
        return 0;
    else if (er_strenge_lig(hold_navn, "VFF"))
        return 1;
    else if (er_strenge_lig(hold_navn, "LBK"))
        return 2;
    else if (er_strenge_lig(hold_navn, "FCK"))
        return 3;
    else if (er_strenge_lig(hold_navn, "BIF"))
        return 4;
    else if (er_strenge_lig(hold_navn, "OB"))
        return 5;
    else if (er_strenge_lig(hold_navn, "AGF"))
        return 6;
    else if (er_strenge_lig(hold_navn, "RFC"))
        return 7;
    else if (er_strenge_lig(hold_navn, "AaB"))
        return 8;
    else if (er_strenge_lig(hold_navn, "ACH"))
        return 9;
    else if (er_strenge_lig(hold_navn, "SIF"))
        return 10;
    else if (er_strenge_lig(hold_navn, "FCN"))
        return 11;
    else
        return -1;
}

int er_strenge_lig(char *str1, char *str2)
{
    return strcmp(str1, str2) == 0;
}