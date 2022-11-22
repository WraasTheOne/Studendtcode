/*
Nicholas Mazur Hansen
nmha22@student.aau.dk
Cyber- og computerteknologi
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const char *Yatzy_runder[] = {"1-ere", "2-ere", "3-ere", "4-ere", "5-ere", "6-ere", "Bonus", "Et par", "To par", "Tre ens", "Fire ens", "Lille", "Stor", "Fuld hus", "Chance", "YATZY", "TOTAl"};

#define Yatzyrunder 17

int print_output(int *point, int dies[], int N, int j);
int scandata();
void roll_multiple_dies(int N, int dies[]);
void ere(int dies[], int N, int *point, int j);
void ens_terninger(int dies[], int *ens, int N);
void par_og_ens(int *ens, int *point, int j);
void special_spil(int *ens, int j, int *point);
int sum(int *point);




int main(void)
{
    srand(time(NULL));
    int N = 5, i, j, total;
    int *ens = malloc(6 * sizeof(int));
    int *point = malloc(Yatzyrunder * sizeof(int));

    do
    {
        int dies[N];
        for (j = 0; j < 6; j++)
        {
            roll_multiple_dies(N, dies);
            ere(dies, N, point, j);
            print_output(point, dies, N, j);
        }

        for(j = 7; j < 11; j++){
            roll_multiple_dies(N, dies);
            ens_terninger(dies, ens, N);
            par_og_ens(ens, point, j);
            print_output(point, dies, N, j);
        }

        for(j = 11; j < 16; j++){
            roll_multiple_dies(N, dies);
            ens_terninger(dies, ens, N);
            special_spil(ens, j, point);
            print_output(point, dies, N, j);
        }
        point[16] = sum(point);
        N = scandata();

    } while (N > 4);
}

int print_output(int *point, int dies[], int N, int j){
    int i;
    printf("%s ", Yatzy_runder[j]);
    for(i = 0; i < N; i++){
        printf("%d ", dies[i]);
    }
    printf(" -- %d\n", point[j]);
    return 0;
}

int scandata()
{
    int N = 0;
    printf("Yatzy with how many dies (a number less than 5 terminates)");
    scanf("%d", &N);
    printf("\nprinting dies:\n");
    return N;
}

void roll_multiple_dies(int N, int dies[])
{
    int i;
    for (i = 0; i < N; i++)
    {
        dies[i] = (rand() % 6) + 1;
    }
}

void ere(int dies[], int N, int *point, int j)
{
    int i;
    int sum = 0;

    for (i = 0; i < N; i++)
    {
        if (dies[i] == j + 1)
        {
            sum = sum + 1;
        }
    }
    point[j] = sum * (1 + j);
}

void ens_terninger(int dies[], int *ens, int N)
{
    int i, k;
    for (k = 0; k < N; k++)
    {
        ens[k] = 0;
    }
    for (i = 0; i < N; i++)
    {
        switch (dies[i])
        {
        case 1:
            ens[0] += 1;
            break;
        case 2:
            ens[1] += 1;
            break;
        case 3:
            ens[2] += 1;
            break;
        case 4:
            ens[3] += 1;
            break;
        case 5:
            ens[4] += 1;
            break;
        case 6:
            ens[5] += 1;
            break;
        }
    }
}


void par_og_ens(int *ens, int *point, int j)
{
    int i, counter = 0;
    switch (j)
    {
    case 7:
        for (i = 5; i >= 0; i--)
        {
            if (ens[i] >= 2)
            {
                point[7] = 2 * (i + 1);
                break;
            }
        }
        break;
    case 8:
        for (i = 5; i >= 0; i--)
        {
            if (ens[i] >= 2)
            {
                point[8] += (2 * (i + 1));
                counter += 1;
            }
            if (counter == 2)
            {
                break;
            }
        }
        break;
    case 9:
        for (i = 5; i >= 0; i--)
        {
            if (ens[i] > 2)
            {
                point[9] = 3 * (i + 1);
                break;
            }
        }
        break;
    case 10:
        for (i = 5; i >= 0; i--)
        {
            if (ens[i] > 3)
            {
                point[10] = 4 * (i + 1);
                break;
            }
        }
        break;
    }
}

void special_spil(int *ens, int j, int *point)
{
    int i, counter = 0, chance = 0, overskud = 0, k;
    switch (j)
    {
    case 11:
        if (ens[0] > 0 && ens[1] > 0 && ens[2] > 0 && ens[3] > 0 && ens[4] > 0)
        {
            point[11] = 15;
        }
        break;
    case 12:
        if (ens[1] > 0 && ens[2] > 0 && ens[3] > 0 && ens[4] > 0 && ens[5] > 0)
        {
            point[12] = 20;
        }
        break;
    case 13:
        for (i = 0; i < 6; i++)
        {
            if (ens[i] > 2)
            {
                for (k = 0; k < 6; k++)
                {
                    if (ens[k] > 1 && k != i)
                    {
                        point[13] = (3 * (i + 1) + (2 * (k + 1)));
                    }
                }
            }
        }
        break;
    case 14:
        for (i = 5; i >= 0; i--)
        {
            chance = chance + (ens[i] * (i + 1));
            counter += ens[i];
            
            if (counter > 5)
            {
                overskud = counter - 5;
                chance = chance - (overskud * (i + 1));
                point[14] = chance;
                break;
            }
            else if (counter == 5)
            {
                point[14] = chance;
                break;
            }
        }
        break;
    case 15:
        if (ens[0] > 0 && ens[1] > 0 && ens[2] > 0 && ens[3] > 0 && ens[4] > 0 && ens[5] > 0)
        {
            point[15] = 50;
        }
        break;
    }
}

int sum(int *point)
{
    int i, sum = 0;
    for (i = 0; i <= Yatzyrunder; i++)
    {
        sum += point[i];
    }
    return sum;
}